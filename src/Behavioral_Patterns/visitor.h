#ifndef VISITOR_H
#define VISITOR_H

#include <iostream>
#include <list>

namespace Visitor {
class ConcreteElementA;
class ConcreteElementB;

class AbstractVisitor { // 访客
public:
  AbstractVisitor() {}
  virtual void visit(ConcreteElementA *element) = 0;
  virtual void visit(ConcreteElementB *element) = 0;
};

class ConcreteVisitorA : public AbstractVisitor { // 存钱
public:
  ConcreteVisitorA() {}
  void visit(ConcreteElementA *element) override {
    std::cout << "ConcreteVisitorA " << this << " visit " << element
              << " ConcreteElementA" << std::endl;
  }
  void visit(ConcreteElementB *element) override {
    std::cout << "ConcreteVisitorA " << this << " no visit " << element
              << " ConcreteElementB" << std::endl;
  }
};
class ConcreteVisitorB : public AbstractVisitor { // 取钱
public:
  ConcreteVisitorB() {}
  void visit(ConcreteElementA *element) override {
    std::cout << "ConcreteVisitorB " << this << " visit " << element
              << " ConcreteElementA" << std::endl;
  }
  void visit(ConcreteElementB *element) override {
    std::cout << "ConcreteVisitorB " << this << " no visit " << element
              << " ConcreteElementB" << std::endl;
  }
};

class ConcreteVisitorC : public AbstractVisitor { // 存钱+取钱
public:
  ConcreteVisitorC() {}
  void visit(ConcreteElementA *element) override {
    std::cout << "ConcreteVisitorC " << this << " visit " << element
              << " ConcreteElementA" << std::endl;
  }
  void visit(ConcreteElementB *element) override {
    std::cout << "ConcreteVisitorC " << this << " visit " << element
              << " ConcreteElementB" << std::endl;
  }
};

class AbstractElement { // 银行业务
public:
  AbstractElement() {}
  virtual void Accept(AbstractVisitor *visit) = 0;
};

class ConcreteElementA : public AbstractElement { // 取钱业务
public:
  ConcreteElementA() {}
  void Accept(AbstractVisitor *visit) override {
    std::cout << "ConcreteElementA"
              << " Accept " << visit << " visit" << std::endl;
    visit->visit(this);
  }
};

class ConcreteElementB : public AbstractElement { // 存钱业务
public:
  ConcreteElementB() {}
  void Accept(AbstractVisitor *visit) override {
    std::cout << "ConcreteElementB"
              << " Accept " << visit << " visit" << std::endl;
    visit->visit(this);
  }
};

class ObjectStructure { // 银行
public:
  ObjectStructure() {}
  void Append(AbstractElement *element) { elements_.emplace_back(element); }
  void Remove(AbstractElement *element) { elements_.remove(element); }
  void Accept(AbstractVisitor *visitor) {
    for (auto x : elements_) {
      x->Accept(visitor);
    }
  }

private:
  std::list<AbstractElement *> elements_;
};
void Client() {
  std::cout << "***"
            << "Visitor"
            << "***" << std::endl;
  ObjectStructure *ob = new ObjectStructure;
  AbstractElement *element1 = new ConcreteElementA;
  AbstractElement *element2 = new ConcreteElementB;
  ob->Append(element1);
  ob->Append(element2);
  AbstractVisitor *visitor1 = new ConcreteVisitorA;
  AbstractVisitor *visitor2 = new ConcreteVisitorB;
  AbstractVisitor *visitor3 = new ConcreteVisitorC;
  ob->Accept(visitor1);
  ob->Accept(visitor2);
  ob->Accept(visitor3);
  std::cout << "***"
            << "Visitor"
            << "***" << std::endl;
}
}; // namespace Visitor

#endif // VISITOR_H
