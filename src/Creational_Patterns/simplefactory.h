// # Copyright 2022 CalvinHxx. All rights reserved.
#ifndef SIMPLEFACTORY_H
#define SIMPLEFACTORY_H

#include <iostream>

namespace SimpleFactory {
class AbstractProduct {
 public:
  virtual void Func() = 0;
};

class ConcreteProductA : public AbstractProduct {
 public:
  void Func() override { std::cout << "ConcreteProductA" << std::endl; };
};

class ConcreteProductB : public AbstractProduct {
 public:
  void Func() override { std::cout << "ConcreteProductB" << std::endl; };
};

class SimpleFactory {
 public:
  SimpleFactory() {}
  enum ProductType { A, B };
  AbstractProduct *CreateProduct(ProductType type) {
    if (type == A) {
      return new ConcreteProductA();
    } else if (type == B) {
      return new ConcreteProductB();
    } else {
      return nullptr;
    }
  }
};

void Client() {
  std::cout << "***"
            << "TestSimpleFactory"
            << "***" << std::endl;
  auto simpleFactory = new SimpleFactory();
  simpleFactory->CreateProduct(SimpleFactory::ProductType::A)->Func();
  simpleFactory->CreateProduct(SimpleFactory::ProductType::B)->Func();
  std::cout << "***"
            << "TestSimpleFactory"
            << "***" << std::endl;
}
}  // namespace SimpleFactory

#endif  // SIMPLEFACTORY_H
