#pragma once
#include "PixelCoordinate.h"
class IWeight
{

public:
	IWeight() {};
	~IWeight() {};
	virtual float weight(Coordinate u, Coordinate v) = 0;

};

