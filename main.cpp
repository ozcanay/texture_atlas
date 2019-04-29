#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>
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
	if (!fs::is_directory(argv[1]))
		std::cout << "Directory must be inputted to the program." << std::endl;
	return fs::is_directory(argv[1]);
}



int main(int argc, char** argv)
{
	if (!isArgNumExpected(argc) || !isArgDirectory(argv)) return -1;
	im::removeTextureAtlas(argv[1]);

	std::string metadata_file = "metadata.txt";
	std::ofstream outfile(metadata_file);
	outfile << "image name | x coordinate | y coordinate | image width | image height" << std::endl;

	std::string path = argv[1];
	std::string folder_name = im::getFolder(path);
	std::vector<cv::Mat> images;
	std::vector<std::filesystem::path> image_names = im::getImageFiles(path);

	unsigned int x_coord = 0;

	for (auto& image_name : image_names) {
		cv::Mat image;
		image = im::createImage(folder_name + image_name.string());

		if (im::isImageValid(image)) {
			images.emplace_back(image);
			outfile << im::writeMetadata(image_name.string(), x_coord, image) << std::endl;
			x_coord += im::getImageWidth(image);
		}
	}

	outfile.close();
	cv::Mat texture_atlas = im::concatenateImages(images);
	im::displayImage(texture_atlas);
	im::saveImage(argv[1], texture_atlas);
}
