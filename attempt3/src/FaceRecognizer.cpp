#include "..\include\FaceRecognizer.h"
#include <dlib/dnn.h>
#include <dlib/opencv.h>
#include <dlib/image_processing.h>
#include <iostream>

FaceRecognizer::FaceRecognizer(const std::string& modelPath)
{
    // For now, just prints the model path.
   
    std::cout << "Loading dlib model from: " << modelPath << std::endl;
}

void FaceRecognizer::predictFace(const cv::Mat& faceROI, int& predictedLabel, double& confidence)
{
    // Converts opencv image to dlib image
    dlib::cv_image<dlib::bgr_pixel> dlibImg(faceROI);
    dlib::matrix<dlib::rgb_pixel> dlibMatrix;
    dlib::assign_image(dlibMatrix, dlibImg);

    // Dummy recognition: Always returns label 1 with 0.90 confidence.
    predictedLabel = 1;
    confidence = 0.90;
    std::cout << "Predicted label: " << predictedLabel
        << " with confidence: " << confidence << std::endl;
}
