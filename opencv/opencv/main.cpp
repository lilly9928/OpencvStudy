//
//  main.cpp
//  opencv
//
//  Created by kawaii on 2021/03/25.
//

#include <iostream>
#include <opencv2/core/core.hpp> //핵심적인 부분
#include <opencv2/highgui/highgui.hpp> //사용자 인터페이스


using namespace std;
using namespace cv;

int main() {
    Mat img = imread("Lenna.jpg");
    
    if (img.empty()) {
        printf("Image read failed");
        exit(-1);
    }
    
    imshow("image", img);
    waitKey(0);
    return 0;
}
