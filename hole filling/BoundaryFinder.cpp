#include "stdafx.h"
#include "BoundaryFinder.h"


BoundaryFinder::BoundaryFinder()
{
}


BoundaryFinder::~BoundaryFinder()
{
}
void BoundaryFinder::setConnectionStrategy(ConnectedPixelsStrategy* cs) {
	connection_strategy = cs;
}
std::set<PixelCoordinate> BoundaryFinder::findBoundary(const MyImage& image, float hole_color) {
	int count = 0;
	std::set<PixelCoordinate> connected_pixels;
	std::set<PixelCoordinate> boundary_pixels;
	std::set<PixelCoordinate>::iterator it;
	for (int x = 0; x < image.getImage().rows;  ++x) {
		for (int y = 0; y < image.getImage().cols;++y) {
			connected_pixels = connection_strategy->getEdgeConnectedPixels(image, Coordinate(x, y));
			for (it = connected_pixels.begin(); it != connected_pixels.end(); ++it) {
				if (it->getColor() == hole_color) {
					++count;
				}
			}

		}
	}
	return boundary_pixels;
}
