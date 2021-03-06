// Tank_ByOpenCV.cpp: 定义控制台应用程序的入口点。
//
#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "opencv.hpp"
#include "Tank.h"
#include <iostream>
#include <string>
using namespace cv;
using namespace std;

Mat ResizeImg(const Mat& img, const cv::Size& sz)
{
	Mat resized_img;
	cv::resize(img, resized_img, sz, 0, 0, cv::INTER_LINEAR);
	return resized_img;
}

int main()
{
	cv::Mat img = cv::Mat::zeros(768, 1024, CV_8U);
	Tank tank(img, cv::Size(50, 60), 10);
	std::string window_name = "img";
	cv::namedWindow(window_name, 1);
	cv::imshow(window_name, img);
	const double factor_smaller = 0.99;
	const double factor_bigger = 1.01;
	double factor = 1;

	while (true)
	{
		const char key = cv::waitKey(15);
		if (key == 27)
			break;
		tank.Move(key);
		cv::imshow(window_name, tank.Draw());
	}
    return 0;
}

