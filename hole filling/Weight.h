#pragma once
#include "IWeight.h"
#include <math.h>
template<unsigned int Z, float EPSILON>
class Weight : public IWeight
{
public:
	Weight() {};
	~Weight() {};
	/*virtual*/ float weight(PixelCoordinate u, PixelCoordinate v);
};
template<unsigned int Z, float EPSILON>
inline float Weight::weight(PixelCoordinate u, PixelCoordinate v) {
	int distance = sqrt(pow((u.getX() - v.getX()), 2) + pow((u.getY() - v.getY()), 2));
	return 1.0/(pow(distance,Z)+EPSILON)
}


