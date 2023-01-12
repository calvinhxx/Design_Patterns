#ifndef ABSTRACTFACTORY_H
#define ABSTRACTFACTORY_H

#include <iostream>

///
///
///

namespace AbstractFactory {
///
/// \brief The AbstractProductA class
///
class AbstractProductA {
public:
  AbstractProductA() {}
  virtual void PrintAbstractA() = 0;
};
class ConcreteProductAStyle1 : public AbstractProductA {
public:
  ConcreteProductAStyle1() {}
  virtual void PrintAbstractA() { std::cout << "ConcreteProductAStyle1\n"; }
};
class ConcreteProductAStyle2 : public AbstractProductA {
public:
  ConcreteProductAStyle2() {}
  virtual void PrintAbstractA() { std::cout << "ConcreteProductAStyle2\n"; }
};

///
/// \brief The AbstractProductB class
///
class AbstractProductB {
public:
  AbstractProductB() {}
  virtual void PrintAbstractB() = 0;
};
class ConcreteProductBStyle1 : public AbstractProductB {
public:
  ConcreteProductBStyle1() {}
  virtual void PrintAbstractB() { std::cout << "ConcreteProductBStyle1\n"; }
};
class ConcreteProductBStyle2 : public AbstractProductB {
public:
  ConcreteProductBStyle2() {}
  virtual void PrintAbstractB() { std::cout << "ConcreteProductBStyle2\n"; }
};

///
/// \brief The AbstractFactory class
///
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
            << "***\n";
  auto style1Factory = new ConcreteFactoryStyle1;
  style1Factory->CreateProductA()->PrintAbstractA();
  style1Factory->CreateProductB()->PrintAbstractB();
  auto style2Factory = new ConcreteFactoryStyle2;
  style2Factory->CreateProductA()->PrintAbstractA();
  style2Factory->CreateProductB()->PrintAbstractB();
  std::cout << "***"
            << "TestAbstractFactory"
            << "***\n";
}
} // namespace AbstractFactory

#endif // ABSTRACTFACTORY_H
