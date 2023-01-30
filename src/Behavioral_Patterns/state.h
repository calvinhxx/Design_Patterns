// # Copyright 2022 CalvinHxx. All rights reserved.
#ifndef STATE_H
#define STATE_H

#include <iostream>

namespace State {
class AbstractState {
 public:
  AbstractState() {}
  virtual void Enter() = 0;
  virtual void Exit() = 0;
};

class AbstractTransition {
 public:
  AbstractTransition(AbstractState *state) : state_(state) {}
  virtual void StateTransfer(AbstractState *state) = 0;

 protected:
  AbstractState *state_;
};

class ConcreteState : public AbstractState {
 public:
  ConcreteState() {}
  void Enter() override { std::cout << this << "Enter" << std::endl; }
  void Exit() override { std::cout << this << "Exit" << std::endl; }
};

class ConcreteTransition : public AbstractTransition {
 public:
  ConcreteTransition(AbstractState *state) : AbstractTransition(state) {}
  void StateTransfer(AbstractState *state) {
    state_->Exit();
    state->Enter();
  }
};

void Client() {
  std::cout << "***"
            << "State"
            << "***" << std::endl;
  AbstractState *state1 = new ConcreteState();
  AbstractState *state2 = new ConcreteState();
  AbstractState *state3 = new ConcreteState();
  AbstractTransition *s1_to_s2 = new ConcreteTransition(state1);
  s1_to_s2->StateTransfer(state2);
  AbstractTransition *s2_to_s3 = new ConcreteTransition(state2);
  s2_to_s3->StateTransfer(state3);
  AbstractTransition *s3_to_s1 = new ConcreteTransition(state3);
  s3_to_s1->StateTransfer(state1);
  std::cout << "***"
            << "State"
            << "***" << std::endl;
}
};  // namespace State

#endif  // STATE_H
