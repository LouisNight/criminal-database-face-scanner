#ifndef FACEDETECTOR_H
#define FACEDETECTOR_H

#include <opencv2/opencv.hpp>
#include <string>
#include <vector>


class FaceDetector {
public:
    
    FaceDetector(const std::string& cascadePath);
    
    std::vector<cv::Rect> detectFaces(const cv::Mat& frame);

private:
    cv::CascadeClassifier faceCascade;
};

#endif