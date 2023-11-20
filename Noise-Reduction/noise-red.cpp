#include <opencv2/opencv.hpp>

int main() {
    // Load the input image
    cv::Mat image = cv::imread("C:\\Users\\sakth\\OneDrive\\Desktop\\Projects\\opencv-cpp\\Images\\noise.jpeg");

    // Display the original image
    cv::imshow("Original Image", image);
    cv::waitKey(0);

    // 1. Gaussian Blur
    cv::Mat gaussianBlurred;
    cv::GaussianBlur(image, gaussianBlurred, cv::Size(5, 5), 0);
    cv::imshow("Gaussian Blur", gaussianBlurred);
    cv::waitKey(0);

    // 2. Median Filter
    cv::Mat medianFiltered;
    cv::medianBlur(image, medianFiltered, 5);
    cv::imshow("Median Filter", medianFiltered);
    cv::waitKey(0);

    // 3. Bilateral Filter
    cv::Mat bilateralFiltered;
    cv::bilateralFilter(image, bilateralFiltered, 9, 75, 75);
    cv::imshow("Bilateral Filter", bilateralFiltered);
    cv::waitKey(0);

    // 4. Denoising Algorithms
    cv::Mat denoised;
    cv::fastNlMeansDenoisingColored(image, denoised, 10, 10, 7, 21);
    cv::imshow("Denoised Image", denoised);
    cv::waitKey(0);

    return 0;
}
