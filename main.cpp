#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;


void alpha_blending(){
    // Read the images
    Mat logo = imread("opencv-logo.png");
    Mat background = imread("ocean.jpg");

//    namedWindow("mask", WINDOW_NORMAL);
//    namedWindow("mask_inv", WINDOW_NORMAL);
//    namedWindow("masked_bg", WINDOW_NORMAL);
//    namedWindow("masked_logo", WINDOW_NORMAL);
    namedWindow("background_source", WINDOW_NORMAL);
    namedWindow("result", WINDOW_NORMAL);

    imshow("background_source", background);
    waitKey(0);

    Mat logo_gray, mask, mask_inv, masked_bg, masked_logo, dst;

    // I want to put logo on top-left corner, So I create a ROI
    Rect region_of_interest = Rect(0,0,logo.cols,logo.rows);
    Mat roi = background(region_of_interest);
    // Now create a mask of logo and create its inverse mask also
    cvtColor(logo,logo_gray, COLOR_BGR2GRAY);
    threshold(logo_gray, mask, 0, 255, THRESH_BINARY);
//    imshow("mask", mask);
//    waitKey(0);
    bitwise_not(mask, mask_inv);
//    imshow("mask_inv", mask_inv);
//    waitKey(0);

    // Now black-out the area of logo in ROI
    bitwise_and(roi,roi,masked_bg,mask_inv);
//    imshow("masked_bg", masked_bg);
//    waitKey(0);

    // Take only region of logo from logo image.
    bitwise_and(logo,logo,masked_logo, mask);
//    imshow("masked_logo", masked_logo);
//    waitKey(0);

    // Put logo in ROI and modify the main image
    add(masked_bg,masked_logo, dst);
    dst.copyTo(roi);

    imshow("result", background);
    waitKey(0);
}

int main() {
    alpha_blending();
    return 0;
}
