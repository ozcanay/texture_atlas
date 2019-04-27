//
// Created by ozcanay on 4/25/19.
//
#include "ImageManager.h"

bool ImageManager::isImageSquare(const cv::Mat& image) {
    return getImageWidth(image) == getImageHeight(image);
}

int ImageManager::getImageHeight(const cv::Mat& image) {
    return image.size[0];
}

int ImageManager::getImageWidth(const cv::Mat& image) {
    return image.size[1];
}

cv::Mat ImageManager::createImage(const std::string &file) {
    cv::Mat image;
    image = cv::imread(file);
    return image;
}

bool ImageManager::isValidImage(const cv::Mat &image) {
    return image.data;
}

std::vector<std::string> ImageManager::getImageFiles(const std::string &dir) {
    std::vector<std::string> vec;
    for(auto& p: std::filesystem::directory_iterator(dir))
        vec.emplace_back(p.path().filename());
    return vec;
}

std::string ImageManager::getImageFolder(const std::string &dir) {

}

cv::Mat ImageManager::concatenateImages(const std::vector<cv::Mat> &images) {
    cv::Mat mat;

    try {
        cv::hconcat(images, mat);
    } catch(const cv::Exception &ex) {
        std::cerr << ex.what();
        std::cout << "Dimensions must hold equal for all the images in the folder." << std::endl;
    }

    return mat;
}

void ImageManager::displayImage(const cv::Mat &mat) {
    try {
        namedWindow("final", cv::WINDOW_AUTOSIZE );
        imshow("final", mat);
        cv::waitKey(0);
    } catch(const cv::Exception &ex) {
        std::cerr << ex.what() << std::endl;
    }
}


