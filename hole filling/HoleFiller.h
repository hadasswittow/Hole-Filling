#pragma once
#include <set>
#include "IWeight.h"
#include "MyImage.h"
#include "ConnectedPixelsStrategy.h"
#include <map>
#include <string>
#include <unordered_set>

typedef std::unordered_set<PixelCoordinate> pixelset;

class HoleFiller
{
public:

	HoleFiller();
	void fillHoleInImage(MyImage& image, const pixelset& hole_pixels, const pixelset& boundary_pixels);
	float getEvaluatedColor(Coordinate hole_pixel, const pixelset& boundary_pixels);
	~HoleFiller();
	void setWeighting(IWeight* _weight);

	// related to the optimal solution
	void fillHoleInImageOptimal(MyImage& image, const pixelset& boundary_pixels, float hole_color);
	void setConnectionStrategy(ConnectedPixelsStrategy* cs);
	std::map<std::string, pixelset> getConnectedBoundaryAndHole(const MyImage& image, PixelCoordinate pixel);
	void fillHoleOptimal(MyImage& image, pixelset hole_pixels);


private:
	IWeight* weight;
	ConnectedPixelsStrategy* connection_strategy;
};
inline void HoleFiller::setWeighting(IWeight* _weight) {
	weight = _weight;
}
inline void HoleFiller::setConnectionStrategy(ConnectedPixelsStrategy* cs) {
	connection_strategy = cs;
}


