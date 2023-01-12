// # Copyright 2022 CalvinHxx. All rights reserved.
#ifndef SRC_CREATIONAL_PATTERNS_FACTORYMETHOD_H_
#define SRC_CREATIONAL_PATTERNS_FACTORYMETHOD_H_

#include <iostream>

///
/// 通过继承,子类实现工厂方法, 符合开闭方便扩展
///

namespace FactoryMethod {
class AbstractProduct {
public:
  AbstractProduct() {}
  virtual void Print() = 0;
};

class ConcreteProductA : public AbstractProduct {
public:
  ConcreteProductA() {}
  void Print() override { std::cout << "ConcreteProductA\n"; }
};

class ConcreteProductB : public AbstractProduct {
public:
  ConcreteProductB() {}
  void Print() override { std::cout << "ConcreteProductB\n"; }
};

class Factory {
public:
  Factory() {}
  virtual AbstractProduct *CreateProduct() = 0;
};

class FactoryA : public Factory {
public:
  FactoryA() {}
  AbstractProduct *CreateProduct() override { return new ConcreteProductA; }
};

class FactoryB : public Factory {
public:
  FactoryB() {}
  AbstractProduct *CreateProduct() override { return new ConcreteProductB; }
};

void Client() {
  std::cout << "***"
            << "TestFactoryMethod"
            << "***\n";
  Factory *factoryA = new FactoryA;
  factoryA->CreateProduct()->Print();
  Factory *factoryB = new FactoryB;
  factoryB->CreateProduct()->Print();
  std::cout << "***"
            << "TestFactoryMethod"
            << "***\n";
}
} // namespace FactoryMethod
#endif // SRC_CREATIONAL_PATTERNS_FACTORYMETHOD_H_
