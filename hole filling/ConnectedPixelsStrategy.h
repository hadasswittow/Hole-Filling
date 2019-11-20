#pragma once
#include "PixelCoordinate.h"
#include "MyImage.h"
#include <set>
class ConnectedPixelsStrategy
{
public:

	ConnectedPixelsStrategy();
	virtual	~ConnectedPixelsStrategy();
	virtual std::set<PixelCoordinate> getConnectedPixels(const MyImage& image, Coordinate pcs) = 0;
	virtual std::set<PixelCoordinate> getEdgeConnectedPixels(const MyImage& image, Coordinate pcs) = 0;

};

