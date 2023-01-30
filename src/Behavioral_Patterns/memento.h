// # Copyright 2022 CalvinHxx. All rights reserved.
#ifndef MEMENTO_H
#define MEMENTO_H

#include <iostream>
#include <string>
#include <unordered_map>

///
/// Also known as: Snapshot
///

namespace Memento {
class Memento {
 public:
  explicit Memento(int value) : value_(value) {}

  int Value() const { return value_; }

 private:
  int value_;
};

class Originator {
 public:
  explicit Originator(int value) : value_(value) {}

  void SetValue(int value) { value_ = value; }

  void PrintValue() const { std::cout << "value_ = " << value_ << std::endl; }

  void Load(const Memento &memento) { value_ = memento.Value(); }

  Memento CreateMemento() { return Memento(value_); }

 private:
  int value_;
};

class Caretaker {
 public:
  Caretaker() {}
  void SaveState(const std::string &str, const Memento &memento) {
    mementos_.try_emplace(str, memento);
  }
  const Memento &TakeState(const std::string &str) { return mementos_.at(str); }

 private:
  std::unordered_map<std::string, const Memento &> mementos_;
};

void Client() {
  std::cout << "***"
            << "Memento"
            << "***" << std::endl;
  Caretaker caretaker;
  Originator originator(1);
  caretaker.SaveState("1", originator.CreateMemento());
  originator.SetValue(2);
  caretaker.SaveState("2", originator.CreateMemento());
  originator.SetValue(3);
  caretaker.SaveState("3", originator.CreateMemento());

  originator.Load(caretaker.TakeState("1"));
  originator.PrintValue();
  originator.Load(caretaker.TakeState("2"));
  originator.PrintValue();
  originator.Load(caretaker.TakeState("3"));
  originator.PrintValue();
  std::cout << "***"
            << "Memento"
            << "***" << std::endl;
}
}  // namespace Memento

#endif  // MEMENTO_H
