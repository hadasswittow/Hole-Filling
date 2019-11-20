#pragma once
#include "ConnectedPixelsStrategy.h"
class EightConnected : public ConnectedPixelsStrategy
{
public:
	EightConnected();
	~EightConnected();
	/*virtual*/ std::set<PixelCoordinate> getConnectedPixels(const MyImage& image, Coordinate pcs);
	/*virtual*/ std::set<PixelCoordinate> getEdgeConnectedPixels(const MyImage& image, Coordinate pcs);

};

