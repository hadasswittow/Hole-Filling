#include "stdafx.h"
#include "HoleFillingLibrary.h"


HoleFillingLibrary::HoleFillingLibrary()
{
	hole_finder = new HoleFinder();
	boundary_finder= new BoundaryFinder();
	
}


HoleFillingLibrary::~HoleFillingLibrary()
{
	delete boundary_finder;
	delete hole_finder;
}
MyImage HoleFillingLibrary::holeFillingLibrary(Mat img, int z, int epsilon, connectivity_e con) {
	MyImage image(img);
	hole_finder->setHoleMask(img);//set the mask with image to know the mask size
	ImageHoleMask image_hole_mask = hole_finder->findHoleInImage(image, HOLE_COLOR);
	return MyImage();
}
void HoleFillingLibrary::setStrategy(connectivity_e connected) {
	if (connected == FOUR) {
		FourConnected four;
		boundary_finder->setConnectionStrategy(&four);
		hole_finder->setConnectionStrategy(&four);
	}
	else if (connected == EIGHT) {
		EightConnected eight;
		boundary_finder->setConnectionStrategy(&eight);
		hole_finder->setConnectionStrategy(&eight);
	}

}