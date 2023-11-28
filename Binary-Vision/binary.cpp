#include <opencv2/opencv.hpp>

int main() {
    // Read an input image
    cv::Mat inputImage = cv::imread("C:\\Users\\sakth\\OneDrive\\Desktop\\Projects\\opencv-cpp\\Images\\NumberPlate.jpg", cv::IMREAD_GRAYSCALE);

    if (inputImage.empty()) {
        std::cerr << "Error: Unable to read the input image." << std::endl;
        return -1;
    }

    // Display the original image
    cv::imshow("Original Image", inputImage);
    cv::waitKey(0);

    // 1. Global Thresholding
    cv::Mat globalThreshold;
    cv::threshold(inputImage, globalThreshold, 128, 255, cv::THRESH_BINARY);
    cv::imshow("Global Thresholding", globalThreshold);
    cv::waitKey(0);

    // 2. Adaptive Thresholding
    cv::Mat adaptiveThreshold;
    cv::adaptiveThreshold(inputImage, adaptiveThreshold, 255, cv::ADAPTIVE_THRESH_MEAN_C, cv::THRESH_BINARY, 11, 2);
    cv::imshow("Adaptive Thresholding", adaptiveThreshold);
    cv::waitKey(0);

    // 3. Otsu's Thresholding
    cv::Mat otsuThreshold;
    cv::threshold(inputImage, otsuThreshold, 0, 255, cv::THRESH_BINARY + cv::THRESH_OTSU);
    cv::imshow("Otsu's Thresholding", otsuThreshold);
    cv::waitKey(0);

    // 4. Inverse Binary Thresholding
    cv::Mat inverseBinaryThreshold;
    cv::threshold(inputImage, inverseBinaryThreshold, 128, 255, cv::THRESH_BINARY_INV);
    cv::imshow("Inverse Binary Thresholding", inverseBinaryThreshold);
    cv::waitKey(0);

    return 0;
}
