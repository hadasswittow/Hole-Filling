#pragma once
#include "MyImage.h"
#include "PixelCoordinate.h"
class ImageHoleMask
{
public:
	ImageHoleMask() {};
	ImageHoleMask(MyImage image);
	void setHolePixel(PixelCoordinate pc);
	Mat getMask();
	void setMaskPixel(Coordinate c, uchar num);
	void setMask(const MyImage& image);
	~ImageHoleMask();
private:
	Mat mask;
	PixelCoordinate pixel_in_hole;

};
inline ImageHoleMask::ImageHoleMask(MyImage image) {
	mask= Mat::zeros(image.getImage().rows, image.getImage().cols, CV_8U);
}
inline void ImageHoleMask::setHolePixel(PixelCoordinate pc) {
	pixel_in_hole = pc;
}
inline Mat ImageHoleMask::getMask() {
	return mask;
}
inline void ImageHoleMask::setMaskPixel(Coordinate c, uchar num) {
	mask.at<uchar>(c.getX(), c.getY()) = num;
}
inline void ImageHoleMask::setMask(const MyImage& image) {
	mask = Mat::zeros(image.getImage().rows, image.getImage().cols, CV_8U);
}
