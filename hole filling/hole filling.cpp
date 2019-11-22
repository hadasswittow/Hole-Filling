#include "stdafx.h"
#include "HoleFillingLibrary.h"
#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>
#include <vector>
using namespace cv;
void saveImageToFile(Mat filled_image);
MyImage getInputAndFillHole();

int main(int argc, char** argv)
{
	MyImage img = getInputAndFillHole(); // gets the information from the user and returns the image filled.	
	saveImageToFile(img.getImage()); // writes the result to an image file.
	
	return 0;
}
void saveImageToFile(Mat filled_image) {
	filled_image *= 255;
	filled_image.convertTo(filled_image, CV_8U);
	imwrite("hole_filled.jpg", filled_image);
}
MyImage getInputAndFillHole() {
	std::cout << "Hi! Please enter your image file name, z, epsilon and the way your pixels are connect!\n";
	std::cout << "For example: myImage.png 2 0.0001 8 .\n";
	std::string image_name;
	int z; float epsilon; int _con;
	std::cin >> image_name >> z >> epsilon >> _con;
	connectivity_e con = (_con == 4) ? FOUR : EIGHT;
	Mat image = imread(image_name, IMREAD_GRAYSCALE);
	if (image.empty()) // Check for failure
	{
		std::cout << "Could not open or find the image" << std::endl;
		system("pause"); //wait for any key press
	}
	image.convertTo(image, CV_32FC3, 1.0 / 255);
	MyImage img(image);
	HoleFillingLibrary hfl;
	hfl.holeFillingLibrary(img, z,epsilon, con);
	return img;
}
