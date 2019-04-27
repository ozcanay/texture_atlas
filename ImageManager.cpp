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

std::string ImageManager::getFolder(const std::string &path) {
    std::string folder;
    std::size_t found = path.find_last_of("/\\");

    if(path.find("/") != std::string::npos)
        folder = path.substr(found + 1) + "/";
    else
        folder = path.substr(found + 1) + "\\";

    return folder;
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
        std::string title = "Texture Atlas";
        namedWindow(title, cv::WINDOW_AUTOSIZE );
        imshow(title, mat);
        cv::waitKey(0);
    } catch(const cv::Exception &ex) {
        std::cerr << ex.what() << std::endl;
    }
}

bool ImageManager::isPNG(const std::string &file) {
    return std::filesystem::path(file).extension() == ".png";
}

bool ImageManager::isJPEG(const std::string &file) {
    return std::filesystem::path(file).extension() == ".jpeg";
}

void ImageManager::saveImage(const std::string &path, const cv::Mat &image) {
    std::string output_image = "/texture_atlas.png";
    try {
        std::cout << path + output_image << std::endl;
        cv::imwrite(path + output_image, image);
    } catch(const cv::Exception &ex) {
        std::cerr << ex.what() << std::endl;
    }
}



