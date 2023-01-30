// # Copyright 2022 CalvinHxx. All rights reserved.
#ifndef TEMPLATEMETHOD_H
#define TEMPLATEMETHOD_H

#include <iostream>

namespace TemplateMethod {
class TempClass {
 public:
  TempClass() {}
  void TemplateMethod() {
    Function1();
    Function2();
    Function3();
  }

 private:
  virtual void Function1() = 0;
  virtual void Function2() = 0;
  virtual void Function3() = 0;
};

class ConcreteClassA : public TempClass {
 public:
  ConcreteClassA() {}

 private:
  void Function1() override { std::cout << "ConcreteClassA 1" << std::endl; }
  void Function2() override { std::cout << "ConcreteClassA 2" << std::endl; }
  void Function3() override { std::cout << "ConcreteClassA 3" << std::endl; }
};

class ConcreteClassB : public TempClass {
 public:
  ConcreteClassB() {}

 private:
  void Function1() override { std::cout << "ConcreteClassB 1" << std::endl; }
  void Function2() override { std::cout << "ConcreteClassB 2" << std::endl; }
  void Function3() override { std::cout << "ConcreteClassB 3" << std::endl; }
};

void Client() {
  std::cout << "***"
            << "TemplateMethod"
            << "***" << std::endl;
  TempClass *class1 = new ConcreteClassA;
  TempClass *class2 = new ConcreteClassB;
  class1->TemplateMethod();
  class2->TemplateMethod();
  std::cout << "***"
            << "TemplateMethod"
            << "***" << std::endl;
}
};  // namespace TemplateMethod

#endif  // TEMPLATEMETHOD_H
