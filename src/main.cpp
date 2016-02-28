#include <iostream>

#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

int main()
{
    // Init
    cv::VideoCapture captureDevice(0);
    if (!cap.isOpened()) { // Check if we turned the camera on
        return -1;
    }

    cv::Mat frame;

    // Display the frames
    while (true) {
        cap >> frame;
        cv::imshow("calc-math-cv", frame);

        if (cv::waitKey(30) >= 0) {
            break;
        }
    }

    return 0;
}
