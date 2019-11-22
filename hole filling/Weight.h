#pragma once
#include "IWeight.h"
#include <math.h>
class Weight : public IWeight
{
public:
	Weight(unsigned int _z, float _epsilon):z(_z),epsilon(_epsilon) {};
	~Weight() {};
	/*virtual*/ float weight(Coordinate u, Coordinate v);

private:
	unsigned int z;
	float epsilon;

};
inline float Weight::weight(Coordinate u, Coordinate v) {
	int distance = sqrt(pow((u.getX() - v.getX()), 2) + pow((u.getY() - v.getY()), 2));
	return 1.0 / (pow(distance, z) + epsilon);
}


