#include "fmt/format.h" // NOLINT
#include <array>        // NOLINT
#include <cassert>      // NOLINT
#include <cstdio>       // NOLINT
#include <opencv2/core/types.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <shared_mutex> // NOLINT
#include <thread>       // NOLINT
#include <utility>      // NOLINT
#include <vector>       // NOLINT

const std::array CAMERA_IDS = {0, 2, 4};
const int WIDTH = 640;
const int HEIGHT = 480;
const int FPS = 30;
const int FRAME_DELAY_MS = 1;
const int ESC_KEY = 27;

static cv::Mat combined_frame;                 // NOLINT
static std::shared_mutex combined_frame_mutex; // NOLINT

void capture_camera(int camera_id, cv::VideoCapture &cap) { // NOLINT
    cv::Mat frame;
    while (true) {
        cap >> frame;

        assert(!frame.empty());

        cv::Rect roi(WIDTH * (camera_id / 2), 0, WIDTH, HEIGHT);
        {
            std::unique_lock lock(combined_frame_mutex);
            frame.copyTo(combined_frame(roi));
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(FRAME_DELAY_MS));
    }
}

int main() {
    fmt::print("Hello from server\n");

    std::vector<cv::VideoCapture> caps;
    caps.reserve(CAMERA_IDS.size());

    for (const int &camera_id : CAMERA_IDS) {
        cv::VideoCapture cap(camera_id);

        assert(cap.isOpened());

        cap.set(cv::CAP_PROP_FRAME_WIDTH, WIDTH);
        cap.set(cv::CAP_PROP_FRAME_HEIGHT, HEIGHT);
        cap.set(cv::CAP_PROP_FPS, FPS);

        caps.emplace_back(std::move(cap));

        fmt::print("Camera {} opened\n", camera_id);
    }

    combined_frame = cv::Mat::zeros(HEIGHT, WIDTH * CAMERA_IDS.size(), CV_8UC3);

    std::vector<std::jthread> threads;
    threads.reserve(CAMERA_IDS.size());

    assert(caps.size() == CAMERA_IDS.size());
    for (const int &camera_id : CAMERA_IDS) {
        threads.emplace_back(
            capture_camera, camera_id,
            std::ref(caps.at(static_cast<size_t>(camera_id) / 2)));
    }

    while (true) {
        {
            std::shared_lock lock(combined_frame_mutex);
            cv::imshow("Combined", combined_frame);
        }

        if (cv::waitKey(FRAME_DELAY_MS) == ESC_KEY) {
            break;
        }
    }

    for (auto &cap : caps) {
        cap.release();
    }

    return 0;
}
