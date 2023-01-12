#ifndef FACADE_H
#define FACADE_H

#include <iostream>

namespace Facade {
class Component {
public:
  Component() {}
  virtual void Work() = 0;
};

class Disk : public Component {
public:
  Disk() {}
  virtual void Work() { std::cout << "disk work" << std::endl; }
};

class CPU : public Component {
public:
  CPU() {}
  virtual void Work() { std::cout << "CPU work" << std::endl; }
};

class Memory : public Component {
public:
  Memory() {}
  virtual void Work() { std::cout << "Memory work" << std::endl; }
};

class System {
public:
  System() : disk_(new Disk), cpu_(new CPU), memory_(new Memory) {}
  void StartUp() {
    std::cout << "StartUp" << std::endl;
    disk_->Work();
    cpu_->Work();
    memory_->Work();
  }

private:
  Component *disk_;
  Component *cpu_;
  Component *memory_;
};

void Client() {
  std::cout << "***"
            << "Facade"
            << "***\n";
  auto sys = new System;
  sys->StartUp();
  std::cout << "***"
            << "Facade"
            << "***\n";
}
} // namespace Facade

#endif // FACADE_H
