#include "stdafx.h"
#include "HoleFiller.h"


HoleFiller::HoleFiller()
{
}
float HoleFiller::getEvaluatedColor(Coordinate hole_pixel, const pixelset& boundary_pixels) {
	// iterates through the boundary pixels and gives a weight to each one of them, and returns 
	// a color according to closer boundary pixels
	float w;
	float weight_color_sum=0;
	float weight_sum=0;
	for (pixelset::iterator it = boundary_pixels.begin(); it != boundary_pixels.end(); ++it) {
		w = weight->weight(hole_pixel, it->getCoordinate());
		weight_color_sum += w*it->getColor();
		weight_sum += w;
	}
	return weight_color_sum / weight_sum;
}
void HoleFiller::fillHoleInImage(MyImage& image, const pixelset& hole_pixels, const pixelset& boundary_pixels) {
	// fills the hole pixels according to an algorithm that checks distance from boundary.
	float color;
	for (pixelset::iterator it = hole_pixels.begin(); it != hole_pixels.end(); ++it) {
		color = getEvaluatedColor(it->getCoordinate(), boundary_pixels);
		image.setPixelColor(it->getCoordinate(), color);
	}
}
std::map<std::string,pixelset> HoleFiller::getConnectedBoundaryAndHole(const MyImage& image,PixelCoordinate pixel) {
	// gets a hole pixel that is connected to boundary and returns a map of the connected hole and boundary pixels.
	// constant time comlexity.
	std::map<std::string, pixelset> ans;
	pixelset boundary;
	pixelset hole;
	pixelset connected_pixels=connection_strategy->getConnectedPixels(image, pixel.getCoordinate());
	for (pixelset::iterator it = connected_pixels.begin(); it != connected_pixels.end(); ++it) {
		if (it->getColor() == pixel.getColor()) {
			hole.insert(*it);
		}
		else {
			boundary.insert(*it);
		}
	}
	ans["hole"] = hole;
	ans["boundary"] = boundary;
	return ans;
}
void HoleFiller::fillHoleOptimal(MyImage& image,  pixelset hole_pixels) {
	// will iterate through hole pixels that are connected to boundary, and will recursively 
	// color them with the boundary color. O(n)
	float color;
	pixelset new_hole_pixels;
	if (hole_pixels.size() < 10)
		return;
	for (pixelset::iterator it = hole_pixels.begin(); it != hole_pixels.end(); ++it) { 
		pixelset boundary_connected_pixels = getConnectedBoundaryAndHole(image,*it)["boundary"];
		pixelset hole_connected_pixels = getConnectedBoundaryAndHole(image, *it)["hole"];
		new_hole_pixels.insert(hole_connected_pixels.begin(), hole_connected_pixels.end());
		color = getEvaluatedColor(it->getCoordinate(), boundary_connected_pixels);
		image.setPixelColor(it->getCoordinate(), color);
	}
	fillHoleOptimal(image, new_hole_pixels);
}
PixelCoordinate getHolePixel(pixelset pixels, float hole_color) {
	// gets a boundary pixel and returns a hole pixel connected to it.
	for (pixelset::iterator it = pixels.begin(); it != pixels.end(); ++it) {
		if (it->getColor() == hole_color) {
			return *it;
		}
	}
}
void HoleFiller::fillHoleInImageOptimal(MyImage& image, const pixelset& boundary_pixels, float hole_color){
	// fills a hole in an image, first will find the hole pixels that are connected to boundary.O(sqrt(n))
	// then will fill the hole in a optimal way
	pixelset hole_connected_to_boundary;
	for (pixelset::iterator it = boundary_pixels.begin(); it != boundary_pixels.end(); ++it) {
		PixelCoordinate temp = getHolePixel(connection_strategy->getConnectedPixels(image, it->getCoordinate()),hole_color);
		hole_connected_to_boundary.insert(temp);
	}
	fillHoleOptimal(image, hole_connected_to_boundary);
}






HoleFiller::~HoleFiller()
{
	delete(connection_strategy);
}
