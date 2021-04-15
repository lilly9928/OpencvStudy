//
//  main.cpp
//  opencv 화소처리 -기타화소처리 선형콘트라스트확대
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
    imshow("first", src);
    
    Mat dst;
    dst = 255-src;
    imshow("result", dst);
    
    waitKey();
    return 0;
}
