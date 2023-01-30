// # Copyright 2022 CalvinHxx. All rights reserved.
#ifndef SINGLETON_H
#define SINGLETON_H

#include <cassert>
#include <iostream>

namespace Singleton {
///
/// 1.ref cppreferencenote The rule of three/five/zero
///
/*  2.ref CppCoreGuidelines 5+1
These functions control the lifecycle of objects: creation, copy, move, and
destruction. Define constructors to guarantee and simplify initialization of
classes.

These are default operations:
    a default constructor: X()
    a copy constructor: X(const X&)
    a copy assignment: operator=(const X&)
    a move constructor: X(X&&)
    a move assignment: operator=(X&&)
    a destructor: ~X()
    By default, the compiler defines each of these operations if it is used, but
the default can be suppressed.
*/

class Singleton {
 public:
  static Singleton &Instance() {
    static Singleton instance;
    return instance;
  }
  Singleton(const Singleton &) = delete;
  Singleton(Singleton &&) = delete;
  Singleton &operator=(const Singleton &) = delete;
  Singleton &operator=(Singleton &&) = delete;

 private:
  Singleton() = default;
  ~Singleton() = default;
};

///
/// temp version
///
template <typename T>
class SingletonTemp {
 public:
  static T &Instance() {
    static T instance;
    return instance;
  }
  explicit SingletonTemp(const T &) = delete;
  explicit SingletonTemp(T &&) = delete;
  T &operator=(const T &) = delete;
  T &operator=(T &&) = delete;

 private:
  SingletonTemp() = default;
  ~SingletonTemp() = default;
};

class A {};

void Client() {
  std::cout << "***"
            << "TestSingleton"
            << "***" << std::endl;
  auto &a = Singleton::Instance();
  auto &b = Singleton::Instance();
  assert(&a == &b);
  std::cout << "***"
            << "TestSingleton  Suc"
            << "***" << std::endl;
  auto &c = SingletonTemp<A>::Instance();
  auto &d = SingletonTemp<A>::Instance();
  assert(&c == &d);
  std::cout << "***"
            << "SingletonTemp  Suc"
            << "***" << std::endl;
  std::cout << "***"
            << "TestSingleton"
            << "***" << std::endl;
}
}  // namespace Singleton

#endif  // SINGLETON_H
