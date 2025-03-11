#ifndef FACERECOGNIZER_H
#define FACERECOGNIZER_H

#include <opencv2/opencv.hpp>
#include <string>
#include <dlib/dnn.h>
#include <dlib/opencv.h>


using anet_type = dlib::loss_metric<dlib::fc_no_bias<128,
    dlib::avg_pool_everything<
    dlib::con<64, 7, 7, 2, 2,
    dlib::input_rgb_image_sized<150>
    >>>>;


class FaceRecognizer {
public:
    
    FaceRecognizer(const std::string& modelPath);
    
    dlib::matrix<float, 0, 1> computeFaceDescriptor(const cv::Mat& faceROI);

private:
    anet_type net;
};

#endif
