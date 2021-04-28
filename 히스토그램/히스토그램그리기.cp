//
//  main.cpp
//  opencv
//
//  Created by kawaii on 2021/04/07.
//
#include "opencv2/opencv.hpp"
#include <iostream>
using namespace cv;
using namespace std;

void drawHist(int histogram[],int rows,int cols){
    int hist_w = rows;
    int hist_h = cols;
    int bin_w = cvRound((double)hist_w/256);
    
    Mat histImage(hist_h,hist_w,CV_8UC3,Scalar(255,255,255));
    
    int max = histogram[0];
    for (int i = 1; i <256 ; i++){
        if(max < histogram[i])
            max = histogram[i];
    }
    for(int i = 0 ; i<255; i++)
    histogram[i]= floor(((double)histogram[i]/max)*histImage.rows);
    
    for(int i = 0; i <255 ; i++){
        line(histImage,Point(bin_w*(i),hist_h),
             Point(bin_w*(i),hist_h - histogram[i]),Scalar(0,0,255));
    }
    imshow("Historgram", histImage);
}
int main()
{
    Mat src =imread("Lenna.jpg",IMREAD_GRAYSCALE);
    int histogram[256] = {0};
    imshow("src", src);
    for(int y = 0; y <src.rows; y++)
    for(int x =0; x<src.cols; x++)
    histogram[(int)src.at<uchar>(y,x)]++;
    
    drawHist(histogram,src.rows,src.cols);
   
    waitKey(0);
    return 0;

}
