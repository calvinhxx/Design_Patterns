#ifndef STRATEGY_H
#define STRATEGY_H

#include <iostream>

namespace Strategy {

class AbstractStrategy {
public:
  AbstractStrategy() {}
  virtual void function() = 0;
};

class ConcreteStrategy1 : public AbstractStrategy {
public:
  ConcreteStrategy1() {}
  void function() override { std::cout << "ConcreteStrategy1" << std::endl; }
};

class ConcreteStrategy2 : public AbstractStrategy {
public:
  ConcreteStrategy2() {}
  void function() override { std::cout << "ConcreteStrategy2" << std::endl; }
};

class Context {
public:
  Context() {}
  void SetStrategy(AbstractStrategy *strate) { strategy_ = strate; }
  void ExecuteStrategy() { strategy_->function(); }

private:
  AbstractStrategy *strategy_;
};

void Client() {
  std::cout << "***"
            << "Strategy"
            << "***" << std::endl;
  AbstractStrategy *strategy1 = new ConcreteStrategy1();
  AbstractStrategy *strategy2 = new ConcreteStrategy2();
  Context *context = new Context();
  context->SetStrategy(strategy1);
  context->ExecuteStrategy();
  context->SetStrategy(strategy2);
  context->ExecuteStrategy();
  std::cout << "***"
            << "Strategy"
            << "***" << std::endl;
}
}; // namespace Strategy

#endif // STRATEGY_H
