// # Copyright 2022 CalvinHxx. All rights reserved.
#ifndef SRC_STRUCTURAL_PATTERNS_PROXY_H_
#define SRC_STRUCTURAL_PATTERNS_PROXY_H_

#include <chrono>
#include <iostream>
#include <string>
#include <thread>

namespace Proxy {
class Image {
public:
  Image() {}
  virtual void ShowImage() = 0;
};

class HighResulutionImage : public Image {
public:
  explicit HighResulutionImage(const std::string &str) : image_url_(str) {
    start_time_ = std::chrono::steady_clock::now();
  }
  bool isLoad() { //  模拟图片加载
    std::chrono::seconds sec(2);
    if ((std::chrono::steady_clock::now() - start_time_) > sec) {
      return true;
    }
    return false;
  }
  void ShowImage() override {
    std::cout << "image url:" << image_url_ << std::endl;
  }

private:
  std::string image_url_;
  std::chrono::time_point<std::chrono::steady_clock> start_time_;
};

class ImageProxy : public Image {
public:
  explicit ImageProxy(HighResulutionImage *image) : image_(image) {}
  void ShowImage() override {
    while (!image_->isLoad()) {
      std::cout << "临时图像" << std::endl;
      std::chrono::milliseconds msec(500);
      std::this_thread::sleep_for(msec);
    }
    image_->ShowImage();
  }

private:
  HighResulutionImage *image_;
};

void Client() {
  //  图像未加载显示临时图像
  std::cout << "***"
            << "Proxy"
            << "***\n";
  HighResulutionImage *h_image = new HighResulutionImage("123.jpg");
  ImageProxy *h_image_proxy = new ImageProxy(h_image);
  h_image_proxy->ShowImage();
  std::cout << "***"
            << "Proxy"
            << "***\n";
}
} // namespace Proxy

#endif // SRC_STRUCTURAL_PATTERNS_PROXY_H_
