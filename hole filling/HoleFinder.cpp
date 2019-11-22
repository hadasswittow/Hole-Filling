#include "stdafx.h"
#include "HoleFinder.h"



HoleFinder::~HoleFinder()
{
	delete(connection_strategy);
}
void HoleFinder::setConnectionStrategy(ConnectedPixelsStrategy* cs) {
	connection_strategy = cs;
}

PixelCoordinate* touchesBoundary(pixelset connected_pixels,const MyImage& image, float hole_color) {
	//checks: if the hole pixel touches the boundary return the boundary pixel
	// otherwise returns nullptr to symbolize that the pixel is only a hole pixel
	pixelset::iterator it;
	float color;
	bool boundry_found = false;
	PixelCoordinate* boundary = nullptr;
	for (it = connected_pixels.begin(); it != connected_pixels.end(); ++it) {
		color = image.getImage().at<float>(it->getX(), it->getY());
		if(it->getColor() != hole_color &&!boundry_found) {// if the pixel touches the boundry return boundry pixel; 
			boundary = new PixelCoordinate(*it);
			boundry_found = true;
		}
	}
	return boundary;
}
std::map<std::string, pixelset> HoleFinder::findHoleAndBoundary( MyImage& image, float hole_color) {
	//finds a hole and a boundary of the hole in a given .
	std::map<std::string, pixelset> ans;
	pixelset hole;
	pixelset boundary;
	pixelset connected_pixels;
	// goes through image and saves the hole and boundary pixels.
	for (int x = 0; x < image.getImage().rows; ++x) {
		for (int y = 0; y < image.getImage().cols; ++y) {
			if (image.getImage().at<float>(x, y) == hole_color)
			{
				connected_pixels = connection_strategy->getConnectedPixels(image, Coordinate(x,y));
				PixelCoordinate* boundary_pixel= touchesBoundary(connected_pixels, image, hole_color);
				if (boundary_pixel) {
					boundary.insert(*boundary_pixel);
					delete boundary_pixel;
				}
				hole.insert(PixelCoordinate(x, y, hole_color));				
			}
		}
	}
	ans["hole"] = hole;
	ans["boundary"] = boundary;
	return ans;
}
