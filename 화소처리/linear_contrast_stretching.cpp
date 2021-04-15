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

int contrastEnh(int input, int x1, int y1, int x2, int y2)
{
    double output;
    if(0 <= input && input <= x1){
        output = y1 /x1 * input;
    }
    else if(x1 < input && input <= x2){
        output = ((y2-y1)/(x2-x1))*(input - x1) + y1;
    }
    else if(x2 < input && input <= 255){
        output = ((255-y2)/(255-x2))*(input - x2) + y2;
    }
    return (int)output;
}

int main()
{
    Mat image = imread("Lenna.jpg");
    Mat oimage = image.clone();
    
    int x1,y1,x2,y2;
    cout << "x1 값을 입력하시오:" ; cin >> x1;
    cout << "y1 값을 입력하시오:" ; cin >> y1;
    cout << "x2 값을 입력하시오:" ; cin >> x2;
    cout << "y2 값을 입력하시오:" ; cin >> y2;
    
    for(int r = 0; r < image.rows; r++){
        for(int c = 0; c < image.cols;c++){
            for(int ch = 0; ch < 3; ch++){
                int output = contrastEnh(image.at<Vec3b>(r,c)[ch], x1, y1, x2, y2);
                oimage.at<Vec3b>(r,c)[ch] = saturate_cast<uchar>(output);
                // at<uchar>(r,c)[ch]: (x,y)[ch,,?]
                //saturate_cast<uchar> : opencv에서 정의한 형을 변환하는 템플릿 함수
            }
        }
    }
    
    imshow("first", image);
    imshow("result", oimage);
    waitKey();
    return 0;
}
