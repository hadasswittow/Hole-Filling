#pragma once
#include "ConnectedPixelsStrategy.h"
#include "FourConnected.h"
#include "EightConnected.h"
#include "HoleFinder.h"
#include <iostream>
#include "HoleFiller.h"
#include "Weight.h"
enum connectivity_e { FOUR = 4, EIGHT = 8 };
static const float HOLE_COLOR = 1.0;





class HoleFillingLibrary
{
public:
	HoleFillingLibrary();
	~HoleFillingLibrary();
	void setWeighting(IWeight* weight);
	void setStrategy(connectivity_e connected);
	MyImage holeFillingLibrary(MyImage& img, unsigned int z, float epsilon, connectivity_e con);
	
private:
	HoleFinder* hole_finder;
	HoleFiller* hole_filler;
};
