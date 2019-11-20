#pragma once
#include "BoundaryFinder.h"
#include "ConnectedPixelsStrategy.h"
#include "FourConnected.h"
#include "EightConnected.h"
#include "HoleFinder.h"
enum connectivity_e { FOUR = 4, EIGHT = 8 };
static const float HOLE_COLOR = 1.0;





class HoleFillingLibrary
{
public:
	HoleFillingLibrary();
	~HoleFillingLibrary();
	void setStrategy(connectivity_e connected);
	MyImage holeFillingLibrary(Mat img, int z, int epsilon, connectivity_e con);
	
private:
	BoundaryFinder* boundary_finder;
	HoleFinder* hole_finder;
	//HoleFiller* hole_filler;
};
