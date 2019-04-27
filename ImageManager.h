#include <string>
#include <vector>
#include <filesystem>
#include <opencv2/core/mat.hpp>
#include <opencv4/opencv2/core/core.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include <opencv4/opencv2/opencv.hpp>

#ifndef TEXTURE_ATLAS_IMAGE_H
#define TEXTURE_ATLAS_IMAGE_H

namespace ImageManager {
    cv::Mat createImage(const std::string &file);
    bool isImageSquare(const cv::Mat &image);
    bool isValidImage(const cv::Mat &image);
    std::vector<std::string> getImageFiles(const std::string &dir);
    std::string getImageFolder(const std::string &dir);
    cv::Mat concatenateImages(const std::vector<cv::Mat> &images);
    void displayImage(const cv::Mat &mat);
    int getImageHeight(const cv::Mat& image);
    int getImageWidth(const cv::Mat& image);
}

#endif //TEXTURE_ATLAS_IMAGE_H
