#pragma once
#include "ConnectedPixelsStrategy.h"
class BoundaryFinder
{
public:
	BoundaryFinder();
	~BoundaryFinder();
	std::set<PixelCoordinate> findBoundary(const MyImage& image,float hole_color);
	void setConnectionStrategy(ConnectedPixelsStrategy* cs);
private:
	ConnectedPixelsStrategy* connection_strategy;
};

