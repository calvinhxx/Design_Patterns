#ifndef ADAPTER_H
#define ADAPTER_H

#include <iostream>
#include <math.h>

namespace Adapter {
///
/// "方钉与圆孔"
///
class RoundPeg {
public:
  RoundPeg(int radius = 0) : radius_(radius) {}
  virtual int GetRadius() { return radius_; }

private:
  int radius_;
};

class RoundHole {
public:
  RoundHole(int radius = 0) : radius_(radius) {}
  bool Fits(RoundPeg *peg) { return radius_ >= peg->GetRadius(); }

private:
  int radius_;
};

class SquarePeg {
public:
  SquarePeg(int width = 0) : width_(width) {}
  int GetWidth() { return width_; }

private:
  int width_;
};

class SquarePegAdapter : public RoundPeg {
public:
  SquarePegAdapter(SquarePeg *peg)
      : peg_(peg), RoundPeg(peg->GetWidth() * sqrt(2) / 2) {}
  virtual int GetRadius() override { return peg_->GetWidth() * sqrt(2) / 2; }

private:
  SquarePeg *peg_;
};

void Client() {
  std::cout << "***"
            << "TestAdapter"
            << "***\n";
  auto roundpeg = new RoundPeg(5);
  auto roundhole = new RoundHole(5);
  assert(roundhole->Fits(roundpeg));
  auto squarepeg = new SquarePeg(5);
  //        auto squarepeg = new SquarePeg(10);
  auto adapter = new SquarePegAdapter(squarepeg);
  assert(roundhole->Fits(adapter));
  std::cout << "***"
            << "TestAdapter"
            << "***\n";
}
} // namespace Adapter

#endif // ADAPTER_H
