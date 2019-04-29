#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
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

	std::string path = argv[1];
	im::removeTextureAtlas(argv[1]);

	std::string metadata_file = path + im::getFileDelimiter(path) + "metadata.txt";
	std::cout << "Metadata will be located at: " << metadata_file << std::endl;
	std::ofstream outfile(metadata_file);
	outfile << "image name | x coordinate | y coordinate | image width | image height" << std::endl;

	std::vector<cv::Mat> images;
	std::vector<std::filesystem::path> image_names = im::getImageFiles(path);
	unsigned int x_coord = 0;

	std::cout << "Images to be concatenated: " << std::endl;
	for (auto& image_name : image_names) {
		cv::Mat image;
		image = im::createImage(path + im::getFileDelimiter(argv[1]) + image_name.string());
		std::cout << path + im::getFileDelimiter(argv[1]) + image_name.string() << std::endl;

		if (im::isImageRead(image)) {
			images.emplace_back(image);
			outfile << im::writeMetadata(image_name.string(), x_coord, image) << std::endl;
			x_coord += im::getImageWidth(image);
		}
	}

	if (!im::areImagesSameHeight(images)) {
		std::cout << "Images must be of equal height." << std::endl;
		return -1;
	}

	outfile.close();
	cv::Mat texture_atlas = im::concatenateImages(images);
	im::displayImage(texture_atlas);
	im::saveImage(argv[1], texture_atlas);
}


