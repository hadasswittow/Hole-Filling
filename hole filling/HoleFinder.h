#pragma once
#include "ConnectedPixelsStrategy.h"
#include <map>
#include <unordered_set>

typedef std::unordered_set <PixelCoordinate> pixelset;

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
