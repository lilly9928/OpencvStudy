//
//  main.cpp
//  opencv
//
//  Created by kawaii on 2021/04/07.
//

#include "opencv2/opencv.hpp"
#include<iostream>
using namespace cv;
using namespace std;

int main()
{
    
    Mat image = imread("Lenna.jpg",IMREAD_GRAYSCALE);
    
    float weights[]= {
        1 / 9.0F , 1 / 9.0F , 1 / 9.0F ,
        1 / 9.0F , 1 / 9.0F , 1 / 9.0F ,
        1 / 9.0F , 1 / 9.0F , 1 / 9.0F
    };
    
    Mat mask(3,3,CV_32F,weights);
    Mat blur;
    filter2D(image, blur, -1, mask);
    blur.convertTo(blur, CV_8U);
    imshow("image", image);
    imshow("blur", blur);
    
    waitKey(0);

    return 0;
}
