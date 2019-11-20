#include "stdafx.h"
#include "HoleFinder.h"
typedef std::set<PixelCoordinate> pixelset;
#include <iostream>


HoleFinder::~HoleFinder()
{
}
void HoleFinder::setConnectionStrategy(ConnectedPixelsStrategy* cs) {
	connection_strategy = cs;
}
// gets a hole pixel and returns all hole pixels connected to it recusively 
void HoleFinder::fillHoleMask(const MyImage& image, float hole_color, PixelCoordinate pixel) {
	pixelset connected_pixels;
	pixelset::iterator it;
	size_t count = 0;
	connected_pixels = connection_strategy->getConnectedPixels(image, pixel.getCoordinate());
	for (it = connected_pixels.begin(); it != connected_pixels.end(); ++it) {
		// if the connected pixel is a hole pixel and wasn't checked already
		char temp = hole_mask.getMask().at<uchar>(it->getX(), it->getY());
		if(it->getColor() == hole_color){
			++count;
			if (temp != 1) {
				fillHoleMask(image, hole_color, *it);
			}		
		}
	}
	if (count == connected_pixels.size())//if all connected pixels are hole- the pixel is a hole pixel
	{
		hole_mask.setMaskPixel(pixel.getCoordinate(),1);
	}else {
		hole_mask.setMaskPixel(pixel.getCoordinate(),2);//set pixel as boundary pixel
	}
}
ImageHoleMask HoleFinder::findHoleInImage(const MyImage& image, float hole_color) {
	pixelset ans;
	pixelset::iterator it;
	// find the first hole pixel and from that pixel go find all hole pixels
	for (int x = 0; x < image.getImage().rows; ++x) {
		for (int y = 0; y < image.getImage().cols; ++y) {
			int i = 0;
			if (image.getImage().at<float>(x, y) == hole_color)
			{
				PixelCoordinate pixel_in_hole(x, y, image.getImage().at<float>(x, y));
				hole_mask.setHolePixel(pixel_in_hole);
				fillHoleMask(image, hole_color, pixel_in_hole);
				return hole_mask;
			}
		}
	}
}
