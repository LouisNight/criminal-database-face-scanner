#include <opencv2/opencv.hpp>
#include "..\include\FaceDetector.h"
#include "..\include\FaceRecognizer.h"
#include "..\include\FaceDatabase.h"
#include <iostream>
#include <dlib/matrix.h>
#include <vector>

int main()
{
    cv::VideoCapture cap(0);
    if (!cap.isOpened()) {
        std::cerr << "Error: Could not open the webcam." << std::endl;
        return -1;
    }


    FaceDetector detector("C:/Users/Night/source/repos/attempt3/attempt3/resources/haarcascade_frontalface_default.xml");

    FaceRecognizer recognizer("C:/Users/Night/Documents/Visual Studio 2022/models/dlib_face_recognition_resnet_model_v1.dat");

    FaceDatabase db;
    db.loadDatabase("face_db.dat");

    cv::Mat frame;
    while (cap.read(frame))
    {
        char key = cv::waitKey(30);
        std::vector<cv::Rect> faces = detector.detectFaces(frame);
        for (const auto& faceRect : faces)
        {
            cv::rectangle(frame, faceRect, cv::Scalar(0, 255, 0), 2);
            cv::Mat faceROI = frame(faceRect);

            try {
                dlib::matrix<float, 0, 1> descriptor = recognizer.computeFaceDescriptor(faceROI);
                auto match = db.findClosestMatch(descriptor, 0.6);

                std::string text = match.first + " (distance: " + std::to_string(match.second) + ")";
                cv::putText(frame, text, cv::Point(faceRect.x, faceRect.y - 10),
                    cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(0, 255, 0), 1);
            }
            catch (const std::exception& e) {
                std::cerr << "Exception computing face descriptor: " << e.what() << std::endl;
            }
        }

        cv::imshow("HumanCV", frame);
        if (key == 'q')
            break;

        // Press 'n' to enroll a new face
        if (key == 'n' && !faces.empty()) {
            std::cout << "Enter name: ";
            std::string name;
            std::cin >> name;

            dlib::matrix<float, 0, 1> descriptor = recognizer.computeFaceDescriptor(frame(faces[0]));
            db.addFace(name, descriptor);
            std::cout << "Face added: " << name << "\n";
        }

        // Press 's' to save the database
        if (key == 's') {
            db.saveDatabase("face_db.dat");
        }
    }
    return 0;
}
