// # Copyright 2022 CalvinHxx. All rights reserved.
#ifndef COMPOSITE_H
#define COMPOSITE_H

#include <iostream>
#include <list>
#include <string>

namespace Composite {
class Component {
 public:
  explicit Component(const std::string &str) : name_(str) {}
  virtual void Show(int depth) = 0;

 protected:
  std::string name_;
};

class Leaf : public Component {
 public:
  explicit Leaf(const std::string &str) : Component(str) {}

  void Show(int depth) override {
    for (int i = 0; i < depth; i++) {
      std::cout << "    ";
    }
    std::cout << name_ << std::endl;
  }
};

class Composite : public Component {
 public:
  explicit Composite(const std::string &str) : Component(str) {}
  virtual void AddComponent(Component *component) {
    child_.push_back(component);
  }
  virtual void RemoveComponent(Component *component) {
    child_.remove(component);
  }
  void Show(int depth) override {
    for (int i = 0; i < depth; i++) {
      std::cout << "    ";
    }
    std::cout << name_ << ":" << std::endl;
    for (auto &x : child_) {
      x->Show(depth + 1);
    }
  }

 private:
  std::list<Component *> child_;
};

void Client() {
  std::cout << "***"
            << "Composite"
            << "***\n";
  Composite *folderLevel2 = new Composite("Notes Folder");
  folderLevel2->AddComponent(new Leaf("jvm.ppt"));
  folderLevel2->AddComponent(new Leaf("redis.txt"));
  Composite *folderLevel1 = new Composite("Weekly Report Folder");
  folderLevel1->AddComponent(new Leaf("20210101-Report"));
  folderLevel1->AddComponent(folderLevel2);
  Composite *folderRoot = new Composite("Memo Folder");
  folderRoot->AddComponent(new Leaf("word.word"));
  folderRoot->AddComponent(new Leaf("ppt.ppt"));
  folderRoot->AddComponent(folderLevel1);
  folderRoot->AddComponent(new Leaf("Demand.txt"));
  Leaf *leaf = new Leaf("bug-list.txt");
  folderRoot->AddComponent(leaf);
  folderRoot->RemoveComponent(leaf);
  folderRoot->Show(0);
  std::cout << "***"
            << "Composite"
            << "***\n";
}
}  // namespace Composite

#endif  // COMPOSITE_H
