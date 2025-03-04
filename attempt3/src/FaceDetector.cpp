#include "..\include\FaceDetector.h"
#include <iostream>

FaceDetector::FaceDetector(const std::string& cascadePath)
{
    if (!faceCascade.load(cascadePath)) {
        std::cerr << "Error loading cascade file: " << cascadePath << std::endl;
    }
}

std::vector<cv::Rect> FaceDetector::detectFaces(const cv::Mat& frame)
{
    std::vector<cv::Rect> faces;
    
    faceCascade.detectMultiScale(frame, faces, 1.1, 3, 0, cv::Size(30, 30));
    return faces;
}
