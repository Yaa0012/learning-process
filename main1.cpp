#include <iostream>
#include <opencv2/opencv.hpp>

int main() {
    cv::Mat img = cv::imread("cl.jpg");
    if (img.empty()) return -1;
    cv::Mat gray;
    cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);
    cv::Mat resized;
    cv::resize(img, resized, cv::Size(300, 200));
    cv::imshow("Original", img);
    cv::imshow("Gray", gray);
    cv::imshow("Resized", resized);
    cv::imwrite("save.jpg", gray);
    cv::waitKey(0);
    return 0;
}
