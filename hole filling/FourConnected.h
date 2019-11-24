#pragma once
#include "ConnectedPixelsStrategy.h"
class FourConnected : public ConnectedPixelsStrategy
{
public:
	FourConnected();
	~FourConnected();
	/*virtual*/ std::unordered_set<PixelCoordinate> getConnectedPixels(const MyImage& image, Coordinate pcs);
	/*virtual*/ std::unordered_set<PixelCoordinate> getEdgeConnectedPixels(const MyImage& image, Coordinate pcs);
};

