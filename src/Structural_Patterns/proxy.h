// # Copyright 2022 CalvinHxx. All rights reserved.
#ifndef SRC_STRUCTURAL_PATTERNS_PROXY_H_
#define SRC_STRUCTURAL_PATTERNS_PROXY_H_

#include <iostream>

namespace Proxy {
class Graphic {
 public:
  virtual void Display() = 0;
};

class Image : public Graphic {
 public:
  void Display() override { std::cout << "Image" << std::endl; }
};

class Proxy : public Graphic {
 public:
  void Display() override { ImageProxy().Display(); }

 protected:
  Image& ImageProxy() {
    if (!p_) {
      p_ = new Image;
    }
    return *p_;
  }

 private:
  Image* p_;
};

void Client() {
  std::cout << "***"
            << "Proxy"
            << "***\n";
  Graphic* image_proxy = new Proxy();
  image_proxy->Display();
  std::cout << "***"
            << "Proxy"
            << "***\n";
}
}  // namespace Proxy

#endif  // SRC_STRUCTURAL_PATTERNS_PROXY_H_
