#ifndef CHAINOFRESPONSIBILITY_H
#define CHAINOFRESPONSIBILITY_H

#include <iostream>
#include <string>

///
/// 通过责任链上的对象都有机会处理请求，解耦发送者与接收者。
///

namespace ChainOfResponsibility {
class Request {
public:
  Request(std::string name, std::string type) : name_(name), type_(type) {}
  std::string GetName() { return name_; }
  std::string GetType() { return type_; }

private:
  std::string name_;
  std::string type_;
};

class AbstractHandler {
public:
  AbstractHandler(AbstractHandler *successor) : successor_(successor) {}
  virtual void HandlerRequest(Request request) = 0;

protected:
  AbstractHandler *successor_;
};

class ConcreteHandler1 : public AbstractHandler {
public:
  ConcreteHandler1(AbstractHandler *successor) : AbstractHandler(successor) {}
  void HandlerRequest(Request request) override {
    if (request.GetType() == "1") {
      std::cout << request.GetName() << " is handle by ConcreteHandler1"
                << std::endl;
      return;
    }
    if (successor_ != nullptr) {
      successor_->HandlerRequest(request);
    }
  }
};

class ConcreteHandler2 : public AbstractHandler {
public:
  ConcreteHandler2(AbstractHandler *successor) : AbstractHandler(successor) {}
  void HandlerRequest(Request request) override {
    if (request.GetType() == "2") {
      std::cout << request.GetName() << " is handle by ConcreteHandler2"
                << std::endl;
      return;
    }
    if (successor_ != nullptr) {
      successor_->HandlerRequest(request);
    }
  }
};

void Client() {
  std::cout << "***"
            << "ChainOfResponsibility"
            << "***" << std::endl;
  Request request1("request1", "1");
  Request request2("request2", "2");
  AbstractHandler *handler1 = new ConcreteHandler1(nullptr);
  AbstractHandler *handler2 = new ConcreteHandler2(handler1);
  handler2->HandlerRequest(request1);
  handler2->HandlerRequest(request2);
  std::cout << "***"
            << "ChainOfResponsibility"
            << "***" << std::endl;
}
}; // namespace ChainOfResponsibility

#endif // CHAINOFRESPONSIBILITY_H
