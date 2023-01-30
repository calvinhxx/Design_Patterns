// # Copyright 2022 CalvinHxx. All rights reserved.
#ifndef ABSTRACTFACTORY_H
#define ABSTRACTFACTORY_H

#include <iostream>

namespace AbstractFactory {
class AbstractProductA {
 public:
  AbstractProductA() {}
  virtual void FuncA() = 0;
};
class ConcreteProductAStyle1 : public AbstractProductA {
 public:
  ConcreteProductAStyle1() {}
  virtual void FuncA() { std::cout << "ConcreteProductAStyle1" << std::endl; }
};
class ConcreteProductAStyle2 : public AbstractProductA {
 public:
  ConcreteProductAStyle2() {}
  virtual void FuncA() { std::cout << "ConcreteProductAStyle2" << std::endl; }
};

class AbstractProductB {
 public:
  AbstractProductB() {}
  virtual void FuncB() = 0;
};
class ConcreteProductBStyle1 : public AbstractProductB {
 public:
  ConcreteProductBStyle1() {}
  virtual void FuncB() { std::cout << "ConcreteProductBStyle1" << std::endl; }
};
class ConcreteProductBStyle2 : public AbstractProductB {
 public:
  ConcreteProductBStyle2() {}
  virtual void FuncB() { std::cout << "ConcreteProductBStyle2" << std::endl; }
};

class AbstractFactory {
 public:
  AbstractFactory() {}
  virtual AbstractProductA *CreateProductA() = 0;
  virtual AbstractProductB *CreateProductB() = 0;
};
class ConcreteFactoryStyle1 : public AbstractFactory {
 public:
  ConcreteFactoryStyle1() {}
  virtual AbstractProductA *CreateProductA() {
    return new ConcreteProductAStyle1();
  }
  virtual AbstractProductB *CreateProductB() {
    return new ConcreteProductBStyle1();
  }
};
class ConcreteFactoryStyle2 : public AbstractFactory {
 public:
  ConcreteFactoryStyle2() {}
  virtual AbstractProductA *CreateProductA() {
    return new ConcreteProductAStyle2();
  }
  virtual AbstractProductB *CreateProductB() {
    return new ConcreteProductBStyle2();
  }
};

void Client() {
  std::cout << "***"
            << "TestAbstractFactory"
            << "***" << std::endl;
  auto style1Factory = new ConcreteFactoryStyle1;
  style1Factory->CreateProductA()->FuncA();
  style1Factory->CreateProductB()->FuncB();
  auto style2Factory = new ConcreteFactoryStyle2;
  style2Factory->CreateProductA()->FuncA();
  style2Factory->CreateProductB()->FuncB();
  std::cout << "***"
            << "TestAbstractFactory"
            << "***" << std::endl;
}
}  // namespace AbstractFactory

#endif  // ABSTRACTFACTORY_H
