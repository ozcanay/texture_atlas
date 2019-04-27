#include "ImageManager.h"

bool ImageManager::isImageSquare(const cv::Mat& image) {
    return getImageWidth(image) == getImageHeight(image);
}

bool ImageManager::isImageRead(const cv::Mat &image) {
    return image.data;
}

bool ImageManager::isImageValid(const cv::Mat &image) {
    return isImageRead(image) && isImageSquare(image);
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

std::vector<std::string> ImageManager::getImageFiles(const std::string &dir) {
    std::vector<std::string> vec;
    for(auto& p: std::filesystem::directory_iterator(dir)) {
        if(isValidExtension(p.path()))
            vec.emplace_back(p.path().filename());
    }

    return vec;
}

bool ImageManager::isValidExtension(const std::filesystem::path &path) {
    return path.filename().extension() == ".png" || path.filename().extension() == ".jpeg";
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

void ImageManager::saveImage(const std::string &path, const cv::Mat &image) {
    std::string output_image = "/texture_atlas.png";
    try {
        std::cout << path + output_image << std::endl;
        cv::imwrite(path + output_image, image);
    } catch(const cv::Exception &ex) {
        std::cerr << ex.what() << std::endl;
    }
}

std::string ImageManager::writeMetadata(const std::string &image_name, unsigned int x_coord, const cv::Mat &image) {
    return image_name + " | " + std::to_string(x_coord) + " | 0 | " + std::to_string(getImageWidth(image)) + " | " + std::to_string(getImageHeight(image));
}

void ImageManager::removeTextureAtlas(const std::string &dir_name) {
    std::string texture_atlas;

    if(getOS(dir_name) == OperatingSystem::LINUX) {
        texture_atlas = dir_name + "/texture_atlas.png";
        std::filesystem::remove(texture_atlas);
    } else if(getOS(dir_name) == OperatingSystem::WINDOWS) {
        texture_atlas = dir_name + "\\texture_atlas.png";
    }
}

OperatingSystem ImageManager::getOS(const std::string &dir_name) {
    OperatingSystem os;

    if(dir_name.find("/") != std::string::npos)
        os = OperatingSystem::LINUX;
    else
        os = OperatingSystem::WINDOWS;

    return os;
}



