#ifndef SINGLETON_H
#define SINGLETON_H

#include <cassert>
#include <iostream>

///
/// 一个类只有一个实例, 提供一个全局的访问节点。
///

namespace Singleton {
///
/// 1.参考cppreferencenote The rule of three/five/zero
/// c98三法则:析构、拷贝构造、拷贝赋值
/// c11五法则:析构、拷贝构造、移动构造、拷贝赋值、移动赋值
///
/*  2.参考CppCoreGuidelines 5+1
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
/// 模板版本
///
template <typename T> class SingletonTemp {
public:
  static T &Instance() {
    static T instance;
    return instance;
  }
  SingletonTemp(const T &) = delete;
  SingletonTemp(T &&) = delete;
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
            << "***\n";
  auto &a = Singleton::Instance();
  auto &b = Singleton::Instance();
  assert(&a == &b);
  std::cout << "***"
            << "TestSingleton  Suc"
            << "***\n";
  auto &c = SingletonTemp<A>::Instance();
  auto &d = SingletonTemp<A>::Instance();
  assert(&c == &d);
  std::cout << "***"
            << "SingletonTemp  Suc"
            << "***\n";
  std::cout << "***"
            << "TestSingleton"
            << "***\n";
}
} // namespace Singleton

#endif // SINGLETON_H
