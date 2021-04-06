//
//  main.cpp
//  opencv 화소처리 -이진화
//
//  Created by kawaii on 2021/04/06.
//
#include "opencv2/opencv.hpp"
#include <iostream>
using namespace std;
using namespace cv;


int main()
{
    Mat src = imread("Lenna.jpg",IMREAD_GRAYSCALE);
    Mat dst;

    int threshold_value = 127;
    threshold(src, dst, threshold_value, 255, THRESH_BINARY);
    imshow("first", src);
    imshow("result", dst);
    
    waitKey();
    return 0;
}
