// OpenCVTest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int _tmain(int argc, _TCHAR* argv[])
{
	cv::Mat image;
	image = cv::imread("cat.jpg");
	if (image.empty()) {
		cout << "打开图像失败" << endl;
		waitKey();
		return -1;

	}

	namedWindow("image", CV_WINDOW_AUTOSIZE);
	imshow("image", image);
	waitKey();
	return 0;
}

