#pragma once
#include "ConnectedPixelsStrategy.h"
class EightConnected : public ConnectedPixelsStrategy
{
public:
	EightConnected();
	~EightConnected();
	/*virtual*/ std::unordered_set<PixelCoordinate> getConnectedPixels(const MyImage& image, Coordinate pcs);
	/*virtual*/ std::unordered_set<PixelCoordinate> getEdgeConnectedPixels(const MyImage& image, Coordinate pcs);

};

