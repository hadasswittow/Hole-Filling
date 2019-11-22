#pragma once
#include <opencv2/opencv.hpp>
using namespace cv;
#include "PixelCoordinate.h"

class MyImage
{

public:
	MyImage();
	MyImage(Mat _image);
	MyImage(MyImage& _image);
	~MyImage();
	Mat getImage()const;
	void setImage(Mat _image);
	void setPixelColor(const Coordinate& c, float color);
private:
	Mat image;
};
inline MyImage::MyImage(Mat _image) {
	image = _image.clone();
}
inline MyImage::MyImage(MyImage& _image) {
	image = _image.getImage().clone();
}
inline Mat MyImage::getImage()const {
	return image;
}
inline void MyImage::setImage(Mat _image) {
	image = _image.clone();
}
inline void MyImage::setPixelColor(const Coordinate& c,float color) {
	image.at<float>(c.getX(),c.getY()) = color;
}
