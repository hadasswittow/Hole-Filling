#include "stdafx.h"
#include "HoleFillingLibrary.h"


HoleFillingLibrary::HoleFillingLibrary()
{
	hole_finder = new HoleFinder();
	hole_filler = new HoleFiller();
}


HoleFillingLibrary::~HoleFillingLibrary()
{
	delete hole_finder;
	delete hole_filler;
}
MyImage HoleFillingLibrary::holeFillingLibrary(MyImage& img, unsigned int z, float epsilon, connectivity_e connection_strategy) {
	//recieves an image with a hole and fills the hole according to an algorithm.
	Weight w(z,epsilon);
	setStrategy(connection_strategy);
	setWeighting(&w);
	std::map<std::string, pixelset> hole_and_boundary = hole_finder->findHoleAndBoundary(img, HOLE_COLOR);
	hole_filler->fillHoleInImageOptimal(img, hole_and_boundary["boundary"],HOLE_COLOR);
	return MyImage();
}
void HoleFillingLibrary::setStrategy(connectivity_e connected) {
	// sets the connectivity strategy- four connected or eight connected.
	if (connected == FOUR) {
		hole_filler->setConnectionStrategy(new FourConnected);
		hole_finder->setConnectionStrategy(new FourConnected);
	}
	else if (connected == EIGHT) {
		hole_filler->setConnectionStrategy(new EightConnected);
		hole_finder->setConnectionStrategy(new EightConnected);
	}

}
void HoleFillingLibrary::setWeighting(IWeight* weight) {
	hole_filler->setWeighting(weight);
}