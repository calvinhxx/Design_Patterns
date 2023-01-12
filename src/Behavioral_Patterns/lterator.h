#ifndef ITERATOR_H
#define ITERATOR_H

#include <iostream>
#include <vector>

namespace Lterator {
template <typename Item> class Iterator {
public:
  Iterator() {}
  virtual Item Next() = 0;
  virtual bool HasNext() = 0;
};

template <typename Item> class Aggregate {
public:
  Aggregate() {}
  virtual Iterator<Item> *CreatorIterator() = 0;
};

template <typename Item> class ConcreteIterator : public Iterator<Item> {
public:
  ConcreteIterator(std::vector<Item> vec) : vec_(vec) {}
  Item Next() override { return vec_.at(index_++); }

  bool HasNext() override { return index_ < vec_.size(); }

private:
  std::vector<Item> vec_;
  int index_ = 0;
};

template <typename Item> class ConcreteAggregate : public Aggregate<Item> {
public:
  ConcreteAggregate() {}
  Iterator<Item> *CreatorIterator() override {
    return new ConcreteIterator<Item>(items_);
  }

  void PushBack(Item item) { items_.push_back(item); }

  Item &operator[](int index) { return items_.at(index); }

private:
  std::vector<Item> items_;
};

void Client() {
  std::cout << "***"
            << "Lterator"
            << "***" << std::endl;
  ConcreteAggregate<int> *aggreate = new ConcreteAggregate<int>();
  aggreate->PushBack(1);
  aggreate->PushBack(2);
  aggreate->PushBack(3);
  Iterator<int> *iterator = aggreate->CreatorIterator();
  while (iterator->HasNext()) {
    std::cout << iterator->Next() << std::endl;
  }
  std::cout << "***"
            << "Lterator"
            << "***" << std::endl;
}
}; // namespace Lterator

#endif // ITERATOR_H
