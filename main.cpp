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

std::string getPath(char** argv) {
    return argv[1];
}

int main(int argc, char** argv )
{
    if(!isArgNumExpected(argc) || !isArgDirectory(argv)) return -1;

    std::string path = getPath(argv);
    std::string folder_name = im::getFolder(path);
    std::vector<cv::Mat> images;

    std::vector<std::string> image_names = im::getImageFiles(path);

    for(auto& image_name : image_names) {
        if(im::isPNG(image_name) || im::isJPEG(image_name)) {
            cv::Mat image;
            image = im::createImage(folder_name + image_name);

            if(im::isValidImage(image) && im::isImageSquare(image))
                images.emplace_back(image);
        }
    }

    cv::Mat texture_atlas = im::concatenateImages(images);
    im::displayImage(texture_atlas);
    im::saveImage(getPath(argv), texture_atlas);
}

