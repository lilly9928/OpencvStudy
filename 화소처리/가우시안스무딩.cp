//
//  main.cpp
//  opencv
//
//  Created by kawaii on 2021/04/07.
//

#include <opencv2/opencv.hpp>
using namespace cv;

int main()
{
    Mat src = imread("Lenna.jpg", 1);
    Mat dst;
    imshow("src", src);

    for (int i = 1; i<61; i = i + 2)
    {
        GaussianBlur(src, dst, Size(i, i), 0, 0);
        imshow("Gaussian filter", dst);
        waitKey(1000);
    }
}
