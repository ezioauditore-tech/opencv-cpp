#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;
int main(int argc, char** argv )
{

    cv::Mat image = cv::imread("C:\\Users\\sakth\\OneDrive\\Desktop\\Projects\\opencv-cpp\\Images\\lenna.png");

    if ( !image.data )
    {
        printf("No image data \n");
        return -1;
    }
    namedWindow("Display Image", (400,300) );
    imshow("Display Image", image);
    waitKey(0);
    return 0;
}