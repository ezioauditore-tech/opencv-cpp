#include <opencv2/opencv.hpp>

int main() {
    cv::Mat inputImage = cv::imread("C:\\Users\\sakth\\OneDrive\\Desktop\\Projects\\opencv-cpp\\Images\\background.jpeg");

    if (inputImage.empty()) {
        std::cerr << "Error: Unable to read the input image." << std::endl;
        return -1;
    }
    cv::Mat grayscaleImage;
    cv::cvtColor(inputImage, grayscaleImage, cv::COLOR_BGR2GRAY);

    // Apply binary thresholding to create a mask
    cv::Mat mask;
    cv::threshold(grayscaleImage, mask, 128, 255, cv::THRESH_BINARY);

    // Create an inverted mask
    cv::Mat invertedMask;
    cv::bitwise_not(mask, invertedMask);

    // Extract the foreground using the mask
    cv::Mat foreground;
    inputImage.copyTo(foreground, mask);

    // Create a white background image
    cv::Mat background(inputImage.size(), inputImage.type(), cv::Scalar(255, 255, 255));

    // Extract the background using the inverted mask
    cv::Mat extractedBackground;
    background.copyTo(extractedBackground, invertedMask);

    // Combine the foreground and background
    cv::Mat resultImage = foreground + extractedBackground;

    cv::imshow("Original Image", inputImage);
    cv::imshow("Foreground", foreground);
    cv::imshow("Background Removed", resultImage);
    cv::waitKey(0);

    return 0;
}
