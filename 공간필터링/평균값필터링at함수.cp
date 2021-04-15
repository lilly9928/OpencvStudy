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
    
    Mat src=imread("Lenna.jpg",IMREAD_GRAYSCALE);
    
    Mat dst(src.size(),CV_8U,Scalar(0)); //비어있는 영상 생성
    if(src.empty()){return -1;}
    
    for(int y = 1; y <src.rows - 1 ; y++){
        for(int x = 1; x < src.cols - 1; x++){
            //인접화소의 좌표를 모두 합하고 9로 나누어 평균값 계산
            int sum = 0 ;
            sum += src.at<uchar>(y - 1, x - 1);
            sum += src.at<uchar>(y, x - 1);
            sum += src.at<uchar>(y + 1, x - 1);
            sum += src.at<uchar>(y - 1, x);
            sum += src.at<uchar>(y + 1 , x);
            sum += src.at<uchar>(y - 1, x + 1);
            sum += src.at<uchar>(y, x + 1);
            sum += src.at<uchar>(y + 1 , x + 1);
            dst.at<uchar>(y , x) = sum / 9 ;
        }
    }
    
    imshow("initial", src);
    imshow("final", dst);
    waitKey(0);

    return 0;
}
