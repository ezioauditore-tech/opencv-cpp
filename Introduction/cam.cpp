#include <opencv2/opencv.hpp>

int main(){
    cv::VideoCapture cap(0);

    if(!cap.isOpened()){
        std::cout << "Error opening video stream" << std::endl;
        return -1;
    }
    cv::namedWindow("Frame", cv::WINDOW_AUTOSIZE);
    while(true){
        cv::Mat frame;
        cap >> frame;
        if(frame.empty()){
            std::cout << "End of video" << std::endl;
            break;
        }
        cv::imshow("Frame", frame);
        if(cv::waitKey(25) >= 0){
            break;
        }
    }
    cap.release();
    cv::destroyAllWindows();
}