#pragma once
#include <opencv2/opencv.hpp>
using namespace cv;

class MyImage
{

public:
	MyImage();
	MyImage(Mat _image);
	~MyImage();
	Mat getImage()const;
	void setImage(Mat _image);
private:
	Mat image;
};
inline MyImage::MyImage(Mat _image) {
	image = _image.clone();
}
inline Mat MyImage::getImage()const {
	return image;
}
inline void MyImage::setImage(Mat _image) {
	image = _image.clone();
}

