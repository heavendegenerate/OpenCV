#include "stdafx.h"
#include "demo.h"

void onMouse(int event, int x, int  y, int flags, void* param) {
	cv::Mat *im = reinterpret_cast<cv::Mat*>(param);
	switch (event) {
	case CV_EVENT_LBUTTONDOWN:
		std::cout << "at(" << x << "," << y << ") value is" << static_cast<int>(im->at<uchar>(cv::Point(x, y))) << endl;
		break;
	default:
		break;
	}
}

int demo() {
	cv::Mat image;

	image = cv::imread("cat.jpg");
	cout << image.channels() << endl;
	//image = cv::imread("cat.jpg", CV_LOAD_IMAGE_COLOR);
	if (image.empty()) {
		cout << "´ò¿ªÍ¼ÏñÊ§°Ü" << endl;
		waitKey();
		return -1;

	}
	cv::circle(image, cv::Point(500, 110), 65, 0, 3);
	cv::putText(image, "This is a cat", cv::Point(40, 200), cv::FONT_HERSHEY_PLAIN, 2.0, 255, 2);
	namedWindow("image", CV_WINDOW_AUTOSIZE);
	cv::setMouseCallback("image", onMouse, reinterpret_cast<void*>(&image));
	imshow("image", image);
	Mat result;
	flip(image, result, 1);
	namedWindow("output");
	imshow("output", result);

	waitKey(0);
	return 0;
}

void MatTest() {
	namedWindow("Image 1");
	namedWindow("Image 2");
	namedWindow("Image 3");
	namedWindow("Image 4");
	namedWindow("Image 5");
	namedWindow("Image");

	Mat image1(240, 320, CV_8U, 100);
	imshow("Image", image1);
	waitKey(0);

	image1.create(200, 200, CV_8U);
	image1 = 200;
	imshow("Image", image1);
	waitKey(0);
	Mat image2(240, 320, CV_8UC3, Scalar(0, 0, 255));
	imshow("Image", image2);
	waitKey(0);
	Mat image3(Size(320, 240), CV_8UC3);
	image3 = imread("cat.jpg");
	Mat image4 = image3;
	image1 = image3;
	image3.copyTo(image2);
	Mat image5 = image3.clone();
	cv::flip(image3, image3, 1);
	imshow("Image 3", image3);
	imshow("Image 1", image1);
	imshow("Image 2", image2);
	imshow("Image 4", image4);
	imshow("Image 5", image5);
	waitKey(0);
	Mat gray = function();
	imshow("Image", gray);
	waitKey(0);
	image1 = imread("cat.jpg", CV_LOAD_IMAGE_GRAYSCALE);
	image1.convertTo(image2, CV_32F, 1 / 255.0, 0.0);
	imshow("Image", image2);
	waitKey(0);
}

cv::Mat function() {
	Mat ima(500, 500, CV_8U, 50);
	return ima;
}
