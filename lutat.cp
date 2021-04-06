//
//  main.cpp
//  opencv 화소처리 -LUT 사용 , at함수
//
//  Created by kawaii on 2021/04/06.
//
#include "opencv2/opencv.hpp"
#include <iostream>
using namespace std;
using namespace cv;

void reduceColorAt(Mat& input, uchar table[]){
    for(int i = 0; i<input.cols; ++i){
        for( int j = 0; j<input.cols;++j)
        input.at<uchar>(i,j) = table[input.at<uchar>(i,j)];
    }
}

int main()
{
    Mat img1 = imread("Lenna.jpg",IMREAD_GRAYSCALE);
    imshow("first", img1);

    uchar table[256];
    for(int i=0; i < 256 ; ++i)
    table[i]=(uchar)((i/100)*100);
    
    reduceColorAt(img1, table);
    imshow("New", img1);
    
    waitKey(0);
    return 0;
}
