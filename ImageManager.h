#include <string>
#include <vector>
#include <unordered_set>
#include <filesystem>
#include <opencv2/core/mat.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>

#ifndef TEXTURE_ATLAS_IMAGE_H
#define TEXTURE_ATLAS_IMAGE_H

namespace ImageManager {
	cv::Mat createImage(const std::string& file);
	bool isImageRead(const cv::Mat& image);
	bool isValidExtension(const std::filesystem::path& path);
	void saveImage(const std::string& path, const cv::Mat& image);
	std::vector<std::filesystem::path> getImageFiles(const std::string& dir);
	cv::Mat concatenateImages(const std::vector<cv::Mat>& images);
	void displayImage(const cv::Mat& mat);
	int getImageHeight(const cv::Mat& image);
	int getImageWidth(const cv::Mat& image);
	std::string writeMetadata(const std::string& image_name, unsigned int x_coord, const cv::Mat& image);
	void removeTextureAtlas(const std::string& dir_name);
	std::string getFileDelimiter(const std::string& dir_name);
	bool areImagesSameHeight(std::vector<cv::Mat> images);
}

#endif //TEXTURE_ATLAS_IMAGE_H
