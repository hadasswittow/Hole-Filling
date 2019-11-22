#pragma once
#include "ConnectedPixelsStrategy.h"
#include <map>
typedef std::set<PixelCoordinate> pixelset;

class HoleFinder
{
public:
	HoleFinder(){};
	~HoleFinder();
	std::map<std::string, pixelset> findHoleAndBoundary( MyImage& image, float hole_color);
	void setConnectionStrategy(ConnectedPixelsStrategy* cs);

private:
	ConnectedPixelsStrategy* connection_strategy;
};
