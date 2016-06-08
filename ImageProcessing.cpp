#include "StdAfx.h"
#include "ImageProcessing.h"


ImageProcessing::ImageProcessing(void)
{
}

 std::string ImageProcessing::intToString(int number){
		std::stringstream ss;
		ss << number;
		return ss.str();
	}

void ImageProcessing::drawObject(int x, int y, int area, cv::Mat &frame, int width, int height){

	//use some of the openCV drawing functions to draw crosshairs
	//on the tracked image!

	cv::circle(frame,cv::Point(x,y),10,cv::Scalar(0,255,0),2);
	
    if(y-12>0)
    cv::line(frame,cv::Point(x,y),cv::Point(x,y-12),cv::Scalar(0,255,0),2);
    else cv::line(frame,cv::Point(x,y),cv::Point(x,0),cv::Scalar(0,255,0),2);
    if(y+12<height)
    line(frame,cv::Point(x,y),cv::Point(x,y+12),cv::Scalar(0,255,0),2);
    else line(frame,cv::Point(x,y),cv::Point(x,height),cv::Scalar(0,255,0),2);
    if(x-12>0)
    cv::line(frame,cv::Point(x,y),cv::Point(x-12,y),cv::Scalar(0,255,0),2);
    else cv::line(frame,cv::Point(x,y),cv::Point(0,y),cv::Scalar(0,255,0),2);
    
	if(x+12<width)
    cv::line(frame,cv::Point(x,y), cv::Point(x+12,y),cv::Scalar(0,255,0),2);
    else cv::line(frame,cv::Point(x,y),cv::Point(width,y),
		cv::Scalar(0,255,0),2);

	cv::putText(frame,"x-pix: "+intToString(x)+","+"y-pix: "+intToString(y)+","+
		"Area: "+intToString(area),
		cv::Point(x,y+30),1,1,cv::Scalar(0,255,0),1);
}


void ImageProcessing::calculateRotaion(int x, SerialPort^ _serialPort){
		int midPosition =320; //midle x-plane pixel position

		//compare the position of the the target to the mid position,
		//rotate camera for by multiples of 7.5 degress
		// for any change more than 80 pixels in any direction
		if (  x>0 && abs(x-midPosition)>80 && (x-midPosition>0)){

			for (int i= 0; i<(abs(x-midPosition)/80); i++)
				serial1.sendDataToPort(_serialPort, "r");

		}
		else if (x>0 &&abs(x-midPosition)>80 && (x-midPosition<0)){
			for (int j= 0; j<(abs(x-midPosition)/80); j++)
			serial1.sendDataToPort(_serialPort, "l");
		}
}

void ImageProcessing::morphObjs(cv::Mat &thresh, int sensitivity){
	
	//size of blur used to smooth the image to remove possible noise and
	//increase the size of the object we are trying to track.
	cv::blur(thresh, thresh, cv::Size(sensitivity,sensitivity));
	cv::threshold(thresh, thresh, sensitivity, 255, cv::THRESH_BINARY);
}

int ImageProcessing::trackFilteredObject(int &x, int &y, cv::Mat threshold, cv::Mat &cameraFeed,
	int width, int height, SerialPort^ _serialPort){
	cv::Mat temp;
	cv::Moments moment;
	double area;

	threshold.copyTo(temp);
	//these two vectors needed for output of findContours
	std::vector< std::vector<cv::Point> > contours;
	std::vector<cv::Vec4i> hierarchy;
	//find contours of filtered image using openCV findContours function
	cv::findContours(temp,contours,hierarchy,CV_RETR_CCOMP,CV_CHAIN_APPROX_SIMPLE );
	//use moments method to find our filtered object
	double refArea = 0;
	bool objectFound = false;
	//max number of objects to be detected in frame
	const int MAX_NUM_OBJECTS=50;
	//minimum and maximum object area
	int MIN_OBJECT_AREA = 20*20;
	int MAX_OBJECT_AREA = height * width/1.5;
	if (hierarchy.size() > 0) {
		int numObjects = hierarchy.size();
        //if number of objects greater than MAX_NUM_OBJECTS we have a noisy filter
        if(numObjects<MAX_NUM_OBJECTS){
			for (int index = 0; index >= 0; index = hierarchy[index][0]) {

				 moment = cv::moments((cv::Mat)contours[index]);
				
				 area = moment.m00;

				//if the area is less than 20 px by 20px then it is probably just noise
				//if the area is the same as the 3/2 of the image size, probably just a bad filter
				//we only want the object with the largest area so we safe a reference area each
				//iteration and compare it to the area in the next iteration.
                if(area>MIN_OBJECT_AREA && area<MAX_OBJECT_AREA && area>refArea){
					x = moment.m10/area;
					y = moment.m01/area;
					objectFound = true;
					refArea = area;
				}else objectFound = false;
			}
			//let user know you found an object
			if(objectFound ==true){
				cv::putText(cameraFeed,"Tracking Object",cv::Point(0,50),2,1,cv::Scalar(0,255,0),2);
				//draw object location on screen
				drawObject(x,y,area,cameraFeed, width, height);
			}
			return x;

		}else {
			cv::putText(cameraFeed,"TOO MUCH NOISE! ADJUST FILTER",cv::Point(0,50),1,2,cv::Scalar(0,0,255),2);
			return x=0;
		}
	}
}