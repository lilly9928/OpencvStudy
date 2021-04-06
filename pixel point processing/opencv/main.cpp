//
//  main.cpp
//  opencv
//
//  Created by kawaii on 2021/03/25.
//
#include "opencv2/opencv.hpp"
#include <iostream>
using namespace std;
using namespace cv;

int main()
{
    double alpha = 1.0;
    int beta = 0;
    Mat image = imread("Lenna.jpg");
    Mat oimage = Mat::zeros(image.size(), image.type());
    cout << "알파값을 입력하세요: [1.0-3.0]: "; cin >> alpha;
    cout << "베타값을 입력하세요: [0-100]: ";    cin >> beta;
    oimage = image * alpha + beta;
    imshow("Original Image", image);
    imshow("New Image", oimage);
    waitKey();
    return 0;
}
