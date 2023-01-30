// # Copyright 2022 CalvinHxx. All rights reserved.
#ifndef BRIDGE_H
#define BRIDGE_H

#include <iostream>

namespace Bridge {
class Computertype {
 public:
  Computertype() {}
  virtual void Feature() = 0;
};

class DesktopComputertype : public Computertype {
 public:
  DesktopComputertype() {}
  virtual void Feature() { std::cout << "powerful desktop\n"; }
};

class LaptopComputertype : public Computertype {
 public:
  LaptopComputertype() {}
  virtual void Feature() { std::cout << "portable laptop\n"; }
};

class AbstractComputer {
 public:
  AbstractComputer() {}
  void SetType(Computertype *type) { computertype_ = type; }
  virtual void Work() = 0;

 protected:
  Computertype *computertype_;
};

class LenovoComputer : public AbstractComputer {
 public:
  LenovoComputer() {}
  virtual void Work() {
    std::cout << "LenovoComputer\n";
    computertype_->Feature();
  }
};

class DellComputer : public AbstractComputer {
 public:
  DellComputer() {}
  virtual void Work() {
    std::cout << "DellComputer\n";
    computertype_->Feature();
  }
};

void Client() {
  std::cout << "***"
            << "TestBridge"
            << "***\n";
  auto desktop = new DesktopComputertype;
  auto lenovo = new LenovoComputer;
  lenovo->SetType(desktop);
  lenovo->Work();
  auto laptop = new LaptopComputertype;
  auto dell = new DellComputer;
  dell->SetType(laptop);
  dell->Work();
  std::cout << "***"
            << "TestBridge"
            << "***\n";
}
}  // namespace Bridge

#endif  // BRIDGE_H
