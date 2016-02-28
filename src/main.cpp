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

    cv::Mat webcamFrame;
    cv::Mat equationFrame;

    // Display the frames
    while (true) {
        captureDevice >> webcamFrame;
        cv::imshow("calc-math-cv", webcamFrame);

        char keyPressed = (char) cv::waitKey(10);
        if (keyPressed == 'q') {
            return 0;
        } else if (keyPressed == 'g') { // Grab the frame and process it
            webcamFrame.copyTo(equationFrame);
            break;
        }
    }

    // Process the retrieved image
    cv::cvtColor(equationFrame, equationFrame, cv::COLOR_BGR2GRAY); // Convert to grayscale
    cv::GaussianBlur(equationFrame, equationFrame, cv::Size(11, 11), 0);
    cv::adaptiveThreshold(equationFrame, equationFrame, 255, cv::ADAPTIVE_THRESH_MEAN_C, cv::THRESH_BINARY, 5, 2);
    cv::bitwise_not(equationFrame, equationFrame);

    cv::imshow("calc-math-cv", equationFrame);
    cv::waitKey(0);

    return 0;
}
