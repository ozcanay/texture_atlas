#include <string>
#include <vector>
#include <filesystem>
// #include <filesystem>
#include <cstdio>
#include <opencv4/opencv2/core/mat.hpp>
#include <opencv4/opencv2/core/core.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include <opencv4/opencv2/opencv.hpp>

#ifndef TEXTURE_ATLAS_IMAGE_H
#define TEXTURE_ATLAS_IMAGE_H

enum class OperatingSystem {
	WINDOWS,
	LINUX
};

namespace ImageManager {
	cv::Mat createImage(const std::string& file);
	bool isImageSquare(const cv::Mat& image);
	bool isImageRead(const cv::Mat& image);
	bool isImageValid(const cv::Mat& image);
	bool isValidExtension(const std::filesystem::path& path);
	void saveImage(const std::string& path, const cv::Mat& image);
	std::vector<std::filesystem::path> getImageFiles(const std::string& dir);
	std::string getFolder(const std::string& path);
	cv::Mat concatenateImages(const std::vector<cv::Mat>& images);
	void displayImage(const cv::Mat& mat);
	int getImageHeight(const cv::Mat& image);
	int getImageWidth(const cv::Mat& image);
	std::string writeMetadata(const std::string& image_name, unsigned int x_coord, const cv::Mat& image);
	void removeTextureAtlas(const std::string& dir_name);
	OperatingSystem getOS(const std::string& dir_name);
}

#endif //TEXTURE_ATLAS_IMAGE_H
