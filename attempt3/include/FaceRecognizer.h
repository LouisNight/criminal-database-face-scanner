#ifndef FACERECOGNIZER_H
#define FACERECOGNIZER_H

#include <opencv2/opencv.hpp>
#include <string>

// FaceRecognizer uses dlib (DUMMY IMPLEMENTATION)
class FaceRecognizer {
public:
    
    FaceRecognizer(const std::string& modelPath);
    
    void predictFace(const cv::Mat& faceROI, int& predictedLabel, double& confidence);

private:
    // Add dlib network/model members
};

#endif
