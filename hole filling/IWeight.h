#pragma once
#include "PixelCoordinate.h"
template<unsigned int Z,float EPSILON>
class IWeight
{
public:
	IWeight() {};
	~IWeight() {};
	virtual float weight(PixelCoordinate u, PixelCoordinate v) = 0;

};

