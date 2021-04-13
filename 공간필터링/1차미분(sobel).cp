//
//  main.cpp
//  opencv
//
//  Created by kawaii on 2021/04/07.
//

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
int main()
{
    Mat src;
    Mat grad;
    int scale = 1;
    int delta = 0;
    src = imread("Lenna.jpg", IMREAD_GRAYSCALE);
    if (src.empty()) { return -1; }

    Mat grad_x, grad_y;
    Mat abs_grad_x, abs_grad_y;

    Sobel(src, grad_x, CV_16S, 1, 0, 3, scale, delta, BORDER_DEFAULT);
    Sobel(src, grad_y, CV_16S, 0, 1, 3, scale, delta, BORDER_DEFAULT);

    convertScaleAbs(grad_x, abs_grad_x); //8비트 행렬로 변환
    convertScaleAbs(grad_y, abs_grad_y);
    addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, grad); //가줓치 합 계산 함수
    imshow("Image", src);
    imshow("Sobel", grad);
    waitKey(0);
    return 0;
}
