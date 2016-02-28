#include <iostream>

#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

int main()
{
    // Init
    cv::VideoCapture captureDevice(0);
    if (!captureDevice.isOpened()) { // Check if we turned the camera on
        return -1;
    }

    cv::Mat frame;

    // Display the frames
    while (true) {
        captureDevice >> frame;
        cv::imshow("calc-math-cv", frame);

        if ((int) cv::waitKey(10) == 'q') {
            return 0;
        }
    }

    return 0;
}
