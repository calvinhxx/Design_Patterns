// # Copyright 2022 CalvinHxx. All rights reserved.
#ifndef OBSERVER_H
#define OBSERVER_H

#include <iostream>
#include <list>
#include <string>

namespace Observer {
class AbstractSubject;
class AbstractObserver {
 public:
  explicit AbstractObserver(AbstractSubject *subject) : subject_(subject) {}
  virtual void update() = 0;

 protected:
  AbstractSubject *subject_;
};

class AbstractSubject {
 public:
  AbstractSubject() {}
  virtual void RegisterObserver(AbstractObserver *observer) = 0;
  virtual void RemoveObserver(AbstractObserver *observer) = 0;
  virtual void NotifyObservers() = 0;

  void SaveValue(const std::string &date) { data_ = date; }
  const std::string &TakeValue() { return data_; }

 protected:
  std::string data_;
};

class ConcreteObserver : public AbstractObserver {
 public:
  explicit ConcreteObserver(AbstractSubject *subject)
      : AbstractObserver(subject) {}
  void update() override {
    std::cout << this << " " << subject_->TakeValue() << std::endl;
  }
};

class ConcreteSubject : public AbstractSubject {
 public:
  ConcreteSubject() {}
  void RegisterObserver(AbstractObserver *observer) override {
    observers_.push_back(observer);
  }
  void RemoveObserver(AbstractObserver *observer) override {
    observers_.remove(observer);
  }
  void NotifyObservers() override {
    for (auto &&x : observers_) {
      x->update();
    }
  }

 private:
  std::list<AbstractObserver *> observers_;
};

void Client() {
  std::cout << "***"
            << "Observer"
            << "***" << std::endl;
  AbstractSubject *subject = new ConcreteSubject;
  AbstractObserver *observer_1 = new ConcreteObserver(subject);
  AbstractObserver *observer_2 = new ConcreteObserver(subject);
  subject->RegisterObserver(observer_1);
  subject->RegisterObserver(observer_2);
  subject->SaveValue("Get Infomation!!!");
  subject->NotifyObservers();
  std::cout << "***"
            << "Observer"
            << "***" << std::endl;
}
};  // namespace Observer

#endif  // OBSERVER_H
