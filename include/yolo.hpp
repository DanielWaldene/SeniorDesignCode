#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <random>

#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/dnn.hpp>


struct Detection{
    int class_id{0};
    std::string className;
    float confidence{0.0};
    cv::Scalar color{};
    cv::Rect box{};
};
class InferenceEngine{
    public: 
        InferenceEngine(const std::string &modelpath, const cv::Size &inputsize, const std::string &classfile, const bool useGPU);
        std::vector<Detection> runInference(const cv::Mat &frame);
    private:
        void loadClassList(const std::string &filename);
        void loadModel(const std::string &modelpath, const bool useGPU);
        cv::Mat formatToSquare(const cv::Mat &source, int *pad_x, int *pad_y, float *scale);
        std::string modelpath_;
        std::string classfile_;
        bool cudaEnabled{};
        std::vector<std::string> classes;
        cv::Size2f modelShape{};
        float modelConfThreshold{0.25};
        float modelScoreThreshold{0.45};
        float modelNMSThreshold{0.5};
        bool letterboxforsquare = true;
        cv::dnn::Net net;
        void Tracking();
};
