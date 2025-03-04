#include <opencv2/opencv.hpp>
#include "..\include\FaceDetector.h"
#include "..\include\FaceRecognizer.h"
#include <iostream>

int main()
{
    cv::VideoCapture cap(0);
    if (!cap.isOpened()) {
        std::cerr << "Error: Could not open the webcam." << std::endl;
        return -1;
    }


    FaceDetector detector("C:/Users/Night/source/repos/attempt3/attempt3/resources/haarcascade_frontalface_default.xml");

    FaceRecognizer recognizer("dummy_model.dat");

    cv::Mat frame;
    while (cap.read(frame))
    {
        std::vector<cv::Rect> faces = detector.detectFaces(frame);
        for (const auto& faceRect : faces)
        {
            cv::rectangle(frame, faceRect, cv::Scalar(0, 255, 0), 2);

            cv::Mat faceROI = frame(faceRect);

            int predictedLabel;
            double confidence;
            recognizer.predictFace(faceROI, predictedLabel, confidence);

            std::string text = "ID: " + std::to_string(predictedLabel)
                + " (" + std::to_string(confidence) + ")";
            cv::putText(frame, text, cv::Point(faceRect.x, faceRect.y - 10),
                cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(0, 255, 0), 1);
        }

        cv::imshow("HumanCV", frame);
        if (cv::waitKey(30) == 'q')
            break;
    }
    return 0;
}
