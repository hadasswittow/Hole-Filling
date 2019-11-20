#pragma once
#include "ConnectedPixelsStrategy.h"
class FourConnected : public ConnectedPixelsStrategy
{
public:
	FourConnected();
	~FourConnected();
	/*virtual*/ std::set<PixelCoordinate> getConnectedPixels(const MyImage& image, Coordinate pcs);
	/*virtual*/ std::set<PixelCoordinate> getEdgeConnectedPixels(const MyImage& image, Coordinate pcs);
};

