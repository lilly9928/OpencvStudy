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

int main()
{
    Mat src =imread("sample2.jpeg",IMREAD_GRAYSCALE);

    Mat dst;
    equalizeHist(src, dst);
    imshow("src", src);
    imshow("dst", dst);
    waitKey(0);
    return 0;

}
