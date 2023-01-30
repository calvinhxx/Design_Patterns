// # Copyright 2022 CalvinHxx. All rights reserved.
#ifndef BUILDER_H
#define BUILDER_H

#include <iostream>

namespace Builder {
class AbstractProduct {
 public:
  AbstractProduct() {}
  virtual void Setfeature1() = 0;
  virtual void Setfeature2() = 0;
  virtual void Setfeature3() = 0;
};
///
/// \brief The ConcreteProduct1 class *** The Feature is print
///
class ConcreteProduct1 : public AbstractProduct {
 public:
  ConcreteProduct1() {}
  void Setfeature1() override { std::cout << "P1 F1" << std::endl; }
  void Setfeature2() override { std::cout << "P1 F2" << std::endl; }
  void Setfeature3() override { std::cout << "P1 F3" << std::endl; }
};
///
/// \brief The ConcreteProduct2 class  *** The Feature is attribute copy value
///
class ConcreteProduct2 : public AbstractProduct {
 public:
  ConcreteProduct2() {}
  void Setfeature1() override { f1_ = true; }
  void Setfeature2() override { f2_ = true; }
  void Setfeature3() override { f3_ = true; }
  void Print() {
    if (f1_) {
      std::cout << "P2 F1" << std::endl;
    } else if (f2_) {
      std::cout << "P2 F2" << std::endl;
    } else if (f3_) {
      std::cout << "P2 F3" << std::endl;
    }
  }

 private:
  bool f1_ = false;
  bool f2_ = false;
  bool f3_ = false;
};

class AbstractBuilder {
 public:
  AbstractBuilder() {}
  virtual ~AbstractBuilder() {}
  virtual void Reset() = 0;
  virtual void BuildStepA() = 0;
  virtual void BuildStepB() = 0;
  virtual void BuildStepC() = 0;
};

class ConcreteBuilder1 : public AbstractBuilder {
 public:
  ConcreteBuilder1() {}

  void Reset() override {
    delete product_;
    product_ = new ConcreteProduct1;
  }
  void BuildStepA() override { product_->Setfeature1(); }
  void BuildStepB() override { product_->Setfeature2(); }
  void BuildStepC() override { product_->Setfeature3(); }

  ConcreteProduct1 *GetResult() { return product_; }

 private:
  ConcreteProduct1 *product_ = nullptr;
};

class ConcreteBuilder2 : public AbstractBuilder {
 public:
  ConcreteBuilder2() {}

  void Reset() override {
    delete product_;
    product_ = new ConcreteProduct2;
  }
  void BuildStepA() override { product_->Setfeature1(); }
  void BuildStepB() override {
    product_->Setfeature1();
    product_->Setfeature2();
  }
  void BuildStepC() override {
    product_->Setfeature1();
    product_->Setfeature2();
    product_->Setfeature3();
  }

  ConcreteProduct2 *GetResult() { return product_; }

 private:
  ConcreteProduct2 *product_ = nullptr;
};

class Director {
 public:
  enum BuilderType { Simple, Complex };

  explicit Director(AbstractBuilder *build) : builder_(build) {}
  void ChangeBuilder(AbstractBuilder *build) {
    delete builder_;
    builder_ = build;
  }
  void Make(BuilderType type) {
    builder_->Reset();
    if (type == Simple) {
      builder_->BuildStepA();
    } else if (type == Complex) {
      builder_->BuildStepA();
      builder_->BuildStepB();
      builder_->BuildStepC();
    }
  }

 private:
  AbstractBuilder *builder_;
};

void Client() {
  std::cout << "***"
            << "TestBuild"
            << "***" << std::endl;
  auto b1 = new ConcreteBuilder1;
  auto b2 = new ConcreteBuilder2;
  auto director1 = new Director(b1);
  director1->Make(Director::Complex);
  b1->GetResult();
  auto director2 = new Director(b2);
  director2->Make(Director::Simple);
  b2->GetResult()->Print();
  std::cout << "***"
            << "TestBuild"
            << "***" << std::endl;
}
}  // namespace Builder

#endif  // BUILDER_H
