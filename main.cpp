#include <iostream>
#include <string>
#include <filesystem>
#include <opencv4/opencv2/core/core.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include <opencv4/opencv2/opencv.hpp>
#include "ImageManager.h"

namespace fs = std::filesystem;
namespace im = ImageManager;

bool isArgNumExpected(int argc) {
    bool result = true;
    if (argc != 2)
    {
        result = false;
        std::cout << "Program must be fed with the directory name and nothing else." << std::endl;
    }
    return result;
}

bool isArgDirectory(char** argv) {
    if(!fs::is_directory(argv[1]))
        std::cout << "Directory must be inputted to the program." << std::endl;
    return fs::is_directory(argv[1]);
}

std::string getFolder(const std::string &path) {
    std::string folder;
    std::size_t found = path.find_last_of("/\\");

    if(path.find("/") != std::string::npos)
        folder = path.substr(found + 1) + "/";
    else
        folder = path.substr(found + 1) + "\\";

    return folder;
}

int main(int argc, char** argv )
{
    if(!isArgNumExpected(argc) || !isArgDirectory(argv)) return -1;

    std::string path = argv[1];
    std::string folder_name = getFolder(path);
    std::vector<cv::Mat> images;

    std::vector<std::string> imageNames = im::getImageFiles(path);
    for(auto& imageName : imageNames) {
        cv::Mat image;
        image = im::createImage(folder_name + imageName);

        if(im::isValidImage(image) && im::isImageSquare(image))
            images.emplace_back(image);
    }

    cv::Mat result_mat = im::concatenateImages(images);
    im::displayImage(result_mat);
}

