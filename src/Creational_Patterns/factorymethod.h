// # Copyright 2022 CalvinHxx. All rights reserved.
#ifndef SRC_CREATIONAL_PATTERNS_FACTORYMETHOD_H_
#define SRC_CREATIONAL_PATTERNS_FACTORYMETHOD_H_

#include <iostream>

namespace FactoryMethod {
class AbstractProduct {
 public:
  AbstractProduct() {}
  virtual void Func() = 0;
};

class ConcreteProductA : public AbstractProduct {
 public:
  ConcreteProductA() {}
  void Func() override { std::cout << "ConcreteProductA" << std::endl; }
};

class ConcreteProductB : public AbstractProduct {
 public:
  ConcreteProductB() {}
  void Func() override { std::cout << "ConcreteProductB" << std::endl; }
};

class AbstractFactory {
 public:
  AbstractFactory() {}
  virtual AbstractProduct *CreateProduct() = 0;
};

class ConcreteFactoryA : public AbstractFactory {
 public:
  ConcreteFactoryA() {}
  AbstractProduct *CreateProduct() override { return new ConcreteProductA; }
};

class ConcreteFactoryB : public AbstractFactory {
 public:
  ConcreteFactoryB() {}
  AbstractProduct *CreateProduct() override { return new ConcreteProductB; }
};

void Client() {
  std::cout << "***"
            << "TestFactoryMethod"
            << "***" << std::endl;
  AbstractFactory *factoryA = new ConcreteFactoryA;
  factoryA->CreateProduct()->Func();
  AbstractFactory *factoryB = new ConcreteFactoryB;
  factoryB->CreateProduct()->Func();
  std::cout << "***"
            << "TestFactoryMethod"
            << "***" << std::endl;
}
}  // namespace FactoryMethod
#endif  // SRC_CREATIONAL_PATTERNS_FACTORYMETHOD_H_
