#include "stdafx.h"
#include "EightConnected.h"


EightConnected::EightConnected()
{
}


EightConnected::~EightConnected()
{
}
std::unordered_set<PixelCoordinate> EightConnected::getConnectedPixels(const MyImage& _image, Coordinate pc) {
	unsigned int x = pc.getX();
	unsigned int y = pc.getY();
	Mat image = _image.getImage();
	std::unordered_set<PixelCoordinate> ans;
	if (x == 0 || y == 0 || x == image.rows - 1 || y == image.cols)
		return getEdgeConnectedPixels(_image, pc);

	ans.insert(PixelCoordinate(x + 1, y, image.at<float>(x + 1, y)));
	ans.insert(PixelCoordinate(x - 1, y, image.at<float>(x - 1, y)));
	ans.insert(PixelCoordinate(x, y + 1, image.at<float>(x, y + 1)));
	ans.insert(PixelCoordinate(x, y - 1, image.at<float>(x, y - 1)));
	ans.insert(PixelCoordinate(x + 1, y +1, image.at<float>(x + 1, y +1)));
	ans.insert(PixelCoordinate(x - 1, y + 1, image.at<float>(x - 1, y +1)));
	ans.insert(PixelCoordinate(x -1, y - 1, image.at<float>(x - 1, y - 1)));
	ans.insert(PixelCoordinate(x + 1, y - 1, image.at<float>(x + 1, y - 1)));
	
	return ans;

}
std::unordered_set<PixelCoordinate> EightConnected::getEdgeConnectedPixels(const MyImage& _image, Coordinate pc) {
	unsigned int x = pc.getX();
	unsigned int y = pc.getY();
	Mat image = _image.getImage();
	std::unordered_set<PixelCoordinate> ans;
	if (x == 0) {
		if (y == 0) {
			ans.insert(PixelCoordinate(x, y + 1, image.at<float>(x, y + 1)));
			ans.insert(PixelCoordinate(x + 1, y, image.at<float>(x + 1, y)));
			ans.insert(PixelCoordinate(x + 1, y + 1, image.at<float>(x + 1, y + 1)));
		}
		else if (y == image.cols -1) {
			ans.insert(PixelCoordinate(x + 1, y, image.at<float>(x + 1, y)));
			ans.insert(PixelCoordinate(x + 1, y - 1, image.at<float>(x + 1, y - 1)));
			ans.insert(PixelCoordinate(x, y - 1, image.at<float>(x, y - 1)));
		}
		else {
			ans.insert(PixelCoordinate(x + 1, y, image.at<float>(x + 1, y)));
			ans.insert(PixelCoordinate(x, y + 1, image.at<float>(x, y + 1)));
			ans.insert(PixelCoordinate(x, y - 1, image.at<float>(x, y - 1)));
			ans.insert(PixelCoordinate(x + 1, y + 1, image.at<float>(x + 1, y + 1)));
			ans.insert(PixelCoordinate(x + 1, y - 1, image.at<float>(x + 1, y - 1)));
		}
	}
	else if (y == 0) {
		if(x == image.rows - 1) {
			ans.insert(PixelCoordinate(x - 1, y, image.at<float>(x - 1, y)));
			ans.insert(PixelCoordinate(x - 1, y + 1, image.at<float>(x - 1, y + 1)));
			ans.insert(PixelCoordinate(x, y + 1, image.at<float>(x, y + 1)));
		}
		else {
			ans.insert(PixelCoordinate(x + 1, y, image.at<float>(x + 1, y)));
			ans.insert(PixelCoordinate(x - 1, y, image.at<float>(x - 1, y)));
			ans.insert(PixelCoordinate(x, y + 1, image.at<float>(x, y + 1)));
			ans.insert(PixelCoordinate(x + 1, y + 1, image.at<float>(x + 1, y + 1)));
			ans.insert(PixelCoordinate(x - 1, y + 1, image.at<float>(x - 1, y + 1)));
		}
	}
	else if (y == image.cols - 1) {
		if (x == image.rows - 1) {
			ans.insert(PixelCoordinate(x - 1, y, image.at<float>(x - 1, y)));
			ans.insert(PixelCoordinate(x - 1, y - 1, image.at<float>(x - 1, y - 1)));
			ans.insert(PixelCoordinate(x, y - 1, image.at<float>(x, y - 1)));
		}
		else {
			ans.insert(PixelCoordinate(x + 1, y, image.at<float>(x + 1, y)));
			ans.insert(PixelCoordinate(x - 1, y, image.at<float>(x - 1, y)));
			ans.insert(PixelCoordinate(x, y - 1, image.at<float>(x, y - 1)));
			ans.insert(PixelCoordinate(x - 1, y - 1, image.at<float>(x - 1, y - 1)));
			ans.insert(PixelCoordinate(x + 1, y - 1, image.at<float>(x + 1, y - 1)));
		}
	}
	else {
		ans.insert(PixelCoordinate(x - 1, y, image.at<float>(x - 1, y)));
		ans.insert(PixelCoordinate(x, y + 1, image.at<float>(x, y + 1)));
		ans.insert(PixelCoordinate(x, y - 1, image.at<float>(x, y - 1)));
		ans.insert(PixelCoordinate(x - 1, y + 1, image.at<float>(x - 1, y + 1)));
		ans.insert(PixelCoordinate(x - 1, y - 1, image.at<float>(x - 1, y - 1)));
	}
	return ans;
}