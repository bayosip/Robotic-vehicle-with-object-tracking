#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <Windows.h>
#include "SerialComm.h"
#pragma once
ref class ImageProcessing
{
private:
	SerialComm serial1;
public:
	ImageProcessing(void);
	std::string intToString(int number);
	int trackFilteredObject(int &x, int &y,cv::Mat threshold, cv::Mat &cameraFeed,
	int width, int height, SerialPort^ _serialPort);
	void calculateRotaion(int x, SerialPort^ _serialPort);
	void morphObjs(cv::Mat &thresh, int sensitivity);
	void drawObject(int x, int y, int area, cv::Mat &frame,
	int width, int height);
};

