#include "stdafx.h"
#include "HoleFillingLibrary.h"
#include <opencv2/opencv.hpp>

#include <iostream>
#include <string>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	// Read the image file
	Mat image = imread("C:/Users/USER/Documents/Visual Studio 2015/Projects/hole filling/img.png", IMREAD_GRAYSCALE);
	image.convertTo(image, CV_32FC3, 1.0 / 255);
	MyImage img(image);
	HoleFillingLibrary hfl;
	HoleFinder hf;
	hf.setHoleMask(img);
	hf.setConnectionStrategy(new EightConnected);
	ImageHoleMask hole=hf.findHoleInImage(img,1.0);
	char c;
	//c= hole.getMask().at<uchar>(113, 235);
	cout << "hi" << endl;
	
	if (image.empty()) // Check for failure
	{
		cout << "Could not open or find the image" << endl;
		system("pause"); //wait for any key press
		return -1;
	}

	String windowName = "My HelloWorld Window"; //Name of the window

	namedWindow(windowName, WINDOW_AUTOSIZE); // Create a window

	imshow(windowName, image); // Show our image inside the created window.

	waitKey(0); // Wait for any keystroke in the window

	destroyWindow(windowName); //destroy the created window

	return 0;
}
