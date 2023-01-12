#ifndef MEDIATOR_H
#define MEDIATOR_H

#include <iostream>
#include <string>
#include <vector>

namespace Mediator {
class Mediator;

class Component {
public:
  Component(Mediator *mediator) : mediator_(mediator) {}
  virtual void OnEvent(std::string event) = 0;

protected:
  Mediator *mediator_;
};

class Mediator {
public:
  Mediator() {}
  virtual void Notify(Component *sender, std::string event) = 0;
};

class Button : public Component {
public:
  Button(Mediator *mediator) : Component(mediator) {}
  void OnEvent(std::string event) override { mediator_->Notify(this, event); }
};

class Dialog : public Component {
public:
  Dialog(Mediator *mediator) : Component(mediator) {}
  void OnEvent(std::string event) override { mediator_->Notify(this, event); }
};

class CheckBox : public Component {
public:
  CheckBox(Mediator *mediator) : Component(mediator) {}
  void OnEvent(std::string event) override { mediator_->Notify(this, event); }
};

class ConcreteMediator : public Mediator {
public:
  ConcreteMediator() {}
  void Append(Component *component) { vec_.push_back(component); }
  virtual void Notify(Component *sender, std::string event) override {
    std::cout << "sender = " << sender << " event = " << event << std::endl;
  }

private:
  std::vector<Component *> vec_;
};

void Client() {
  std::cout << "***"
            << "Mediator"
            << "***" << std::endl;
  ConcreteMediator *mediator = new ConcreteMediator();
  Component *button = new Button(mediator);
  Component *dialog = new Dialog(mediator);
  Component *checkbox = new CheckBox(mediator);
  mediator->Append(button);
  mediator->Append(dialog);
  mediator->Append(checkbox);
  button->OnEvent("button");
  dialog->OnEvent("dialog");
  checkbox->OnEvent("checkbox");
  std::cout << "***"
            << "Mediator"
            << "***" << std::endl;
}
} // namespace Mediator

#endif // MEDIATOR_H
