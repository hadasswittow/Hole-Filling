#pragma once
#include "PixelCoordinate.h"
#include "MyImage.h"
#include <unordered_set>

class ConnectedPixelsStrategy
{
public:

	ConnectedPixelsStrategy();
	virtual	~ConnectedPixelsStrategy();
	virtual std::unordered_set<PixelCoordinate> getConnectedPixels(const MyImage& image, Coordinate pcs) = 0;
	virtual std::unordered_set<PixelCoordinate> getEdgeConnectedPixels(const MyImage& image, Coordinate pcs) = 0;

};

