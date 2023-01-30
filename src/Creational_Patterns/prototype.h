// # Copyright 2022 CalvinHxx. All rights reserved.
#ifndef PROTOTYPE_H
#define PROTOTYPE_H

#include <iostream>
#include <string>

namespace Prototype {
class AbstractPrototype {
 public:
  explicit AbstractPrototype(std::string p1) : complexproperty1_(p1) {}
  virtual AbstractPrototype *Clone() = 0;

 protected:
  std::string complexproperty1_;
};

class ConcretePrototype : public AbstractPrototype {
 public:
  explicit ConcretePrototype(std::string p1) : AbstractPrototype(p1) {}
  AbstractPrototype *Clone() override { return new ConcretePrototype(*this); }
};

void Client() {
  std::cout << "***"
            << "TestPrototype"
            << "***" << std::endl;
  AbstractPrototype *pro = new ConcretePrototype("s1");
  AbstractPrototype *pro_copy = pro->Clone();
  assert(pro != pro_copy);
  std::cout << "***"
            << "TestPrototype  Suc"
            << "***" << std::endl;
  std::cout << "***"
            << "TestPrototype"
            << "***" << std::endl;
}
}  // namespace Prototype

#endif  // PROTOTYPE_H
