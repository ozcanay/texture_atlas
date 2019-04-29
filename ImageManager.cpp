#include "ImageManager.h"

bool ImageManager::isImageRead(const cv::Mat& image) {
	return image.data;
}

int ImageManager::getImageHeight(const cv::Mat& image) {
	return image.size[0];
}

int ImageManager::getImageWidth(const cv::Mat& image) {
	return image.size[1];
}

cv::Mat ImageManager::createImage(const std::string& file) {
	cv::Mat image;
	image = cv::imread(file);
	return image;
}

std::vector<std::filesystem::path> ImageManager::getImageFiles(const std::string& dir) {
	std::vector<std::filesystem::path> vec;
	for (auto& p : std::filesystem::directory_iterator(dir)) {
		if (isValidExtension(p.path()))
			vec.emplace_back(p.path().filename());
	}

	return vec;
}

bool ImageManager::isValidExtension(const std::filesystem::path& path) {
	return path.filename().extension() == ".png" || path.filename().extension() == ".jpeg";
}

cv::Mat ImageManager::concatenateImages(const std::vector<cv::Mat>& images) {
	cv::Mat mat;

	try {
		cv::hconcat(images, mat);
	}
	catch (const cv::Exception& ex) {
		std::cerr << ex.what();
		std::cout << "Dimensions must hold equal for all the images in the folder." << std::endl;
	}

	return mat;
}

void ImageManager::displayImage(const cv::Mat& mat) {
	try {
		std::string title = "Texture Atlas";
		namedWindow(title, cv::WINDOW_AUTOSIZE);
		imshow(title, mat);
		cv::waitKey(0);
	}
	catch (const cv::Exception & ex) {
		std::cerr << ex.what() << std::endl;
	}
}

void ImageManager::saveImage(const std::string & path, const cv::Mat& image) {
	std::string output_image = getFileDelimiter(path) + "texture_atlas.png";
	std::cout << "Created texture atlas is located at: " << path + output_image << std::endl;
	try {
		cv::imwrite(path + output_image, image);
	}
	catch (const cv::Exception & ex) {
		std::cerr << ex.what() << std::endl;
	}
}

std::string ImageManager::writeMetadata(const std::string& image_name, unsigned int x_coord, const cv::Mat& image) {
	return image_name + " | " + std::to_string(x_coord) + " | 0 | " + std::to_string(getImageWidth(image)) + " | " + std::to_string(getImageHeight(image));
}

void ImageManager::removeTextureAtlas(const std::string& dir_name) {
	std::string texture_atlas;
	texture_atlas = dir_name + getFileDelimiter(dir_name) + "texture_atlas.png";
	std::filesystem::remove(texture_atlas);
}

std::string ImageManager::getFileDelimiter(const std::string& dir_name) {
	std::string file_delimiter;

	// Linux file delimiter
	if (dir_name.find("/") != std::string::npos)
		file_delimiter = "/";
	else // Windows file delimiter
		file_delimiter = "\\";

	return file_delimiter;
}

bool ImageManager::areImagesSameHeight(std::vector<cv::Mat> images) {
	bool areImagesSameHeight = true;
	std::unordered_set<int> uniqueImageHeightValues;

	for (auto& image : images) {
		uniqueImageHeightValues.insert(getImageHeight(image));
	}

	if (uniqueImageHeightValues.size() == 1) {
		std::cout << "Height values of all images are equal. Concatenating..." << std::endl;
	}
	else {
		areImagesSameHeight = false;
		std::cout << "Height values of all images must be equal to concatenate images horizontally." << std::endl;
	}

	return areImagesSameHeight;
}
