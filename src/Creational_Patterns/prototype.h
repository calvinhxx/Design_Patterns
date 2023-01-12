#ifndef PROTOTYPE_H
#define PROTOTYPE_H

#include <iostream>
#include <string>
#include <vector>
///
/// \brief The Prototype class
///

namespace Prototype {
class AbstractPrototype {
public:
  AbstractPrototype() {}
  virtual AbstractPrototype *Clone() = 0;
  virtual void Print() = 0;
};

class ConcretePrototype1 : public AbstractPrototype {
public:
  ConcretePrototype1(int property = 0) : property_(property) {}
  ConcretePrototype1(ConcretePrototype1 *prob) { property_ = prob->property_; }
  virtual AbstractPrototype *Clone() override {
    return new ConcretePrototype1(this);
  }
  virtual void Print() override {
    std::cout << "property_=" << property_ << std::endl;
  }

private:
  int property_ = 0;
};

class ConcretePrototype2 : public AbstractPrototype {
public:
  ConcretePrototype2(std::string property = "") : property_(property) {}
  ConcretePrototype2(ConcretePrototype2 *prob) { property_ = prob->property_; }
  virtual AbstractPrototype *Clone() override {
    return new ConcretePrototype2(this);
  }
  virtual void Print() override {
    std::cout << "property_=" << property_ << std::endl;
  }

private:
  std::string property_ = std::string();
};

void Client() {
  std::cout << "***"
            << "TestPrototype"
            << "***\n";
  AbstractPrototype *protype0 = new ConcretePrototype1();
  AbstractPrototype *protype1 = new ConcretePrototype1(1);
  AbstractPrototype *protype2 = new ConcretePrototype1(2);
  AbstractPrototype *protypeA = new ConcretePrototype2("a");
  AbstractPrototype *protypeB = new ConcretePrototype2("b");
  AbstractPrototype *protypeC = new ConcretePrototype2("c");
  std::vector<AbstractPrototype *> prototypeVec;
  prototypeVec.push_back(protype0);
  prototypeVec.push_back(protype1);
  prototypeVec.push_back(protype2);
  prototypeVec.push_back(protypeA);
  prototypeVec.push_back(protypeB);
  prototypeVec.push_back(protypeC);
  std::vector<AbstractPrototype *> prototypeVecCopy;
  for (auto prob : prototypeVec) {
    prototypeVecCopy.push_back(prob->Clone());
  }
  for (auto prob : prototypeVecCopy) {
    prob->Print();
  }
  std::cout << "***"
            << "TestPrototype"
            << "***\n";
}
} // namespace Prototype

#endif // PROTOTYPE_H
