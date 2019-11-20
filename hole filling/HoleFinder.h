#pragma once
#include "ConnectedPixelsStrategy.h"
#include "ImageHoleMask.h"
typedef std::set<PixelCoordinate> pixelset;

class HoleFinder
{
public:
	HoleFinder(){};
	~HoleFinder();
	ImageHoleMask findHoleInImage(const MyImage& image, float hole_color);
	void fillHoleMask(const MyImage& image, float hole_color, PixelCoordinate pixel);
	void setConnectionStrategy(ConnectedPixelsStrategy* cs);
	void setHoleMask(const MyImage& image);

private:
	ConnectedPixelsStrategy* connection_strategy;
	ImageHoleMask hole_mask;
};
inline void HoleFinder::setHoleMask(const MyImage& image) {
	hole_mask.setMask(image.getImage());
}