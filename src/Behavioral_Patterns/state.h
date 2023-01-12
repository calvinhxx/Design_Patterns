#ifndef STATE_H
#define STATE_H

#include <iostream>

///
/// 涉及概念：
/// 1.有向图
/// 2.finite-state machine(有限状态机)
/// 状态机State、Transition 对应有向图Node、Link
/// 状态模式是借鉴了状态机State、Transition概念。
///

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
}; // namespace State

#endif // STATE_H
