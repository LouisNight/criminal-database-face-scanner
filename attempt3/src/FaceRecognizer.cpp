#include "..\include\FaceRecognizer.h"
#include <dlib/dnn.h>
#include <dlib/opencv.h>
#include <dlib/image_processing.h>
#include <iostream>

FaceRecognizer::FaceRecognizer(const std::string& modelPath)
{
    try {

        dlib::deserialize(modelPath) >> net;
        std::cout << "Loaded dlib model from: " << modelPath << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Error loading dlib model: " << e.what() << std::endl;
    }
}

dlib::matrix <float, 0, 1> FaceRecognizer::computeFaceDescriptor(const cv::Mat& faceROI)
{
    // convert opencv image to dlib image
    dlib::cv_image<dlib::bgr_pixel> dlibImg(faceROI);
    dlib::matrix<dlib::rgb_pixel> dlibMatrix;
    dlib::assign_image(dlibMatrix, dlibImg);

    return net(dlibMatrix);
}
