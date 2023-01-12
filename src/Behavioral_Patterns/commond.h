#ifndef COMMOND_H
#define COMMOND_H

#include <iostream>

namespace Commond {
class Light {
public:
  Light(){};
  void On() { std::cout << "light is on!!!" << std::endl; }
  void Off() { std::cout << "light is off!!!" << std::endl; }
};

class Commond {
public:
  Commond(){};
  virtual void Execute() = 0;
};

class LightOnCommond : public Commond {
public:
  LightOnCommond(Light light) : light_(light) {}
  void Execute() override { light_.On(); }

private:
  Light light_;
};

class LightOffCommond : public Commond {
public:
  LightOffCommond(Light light) : light_(light) {}
  void Execute() override { light_.Off(); }

private:
  Light light_;
};

class Invoker {
public:
  Invoker(){};
  void Submit(Commond *cmd) { cmd->Execute(); }
};

void Client() {
  std::cout << "***"
            << "Commond"
            << "***" << std::endl;
  Light light;
  Commond *cmd_on = new LightOnCommond(light);
  Commond *cmd_off = new LightOffCommond(light);
  Invoker invoker;
  invoker.Submit(cmd_on);
  invoker.Submit(cmd_off);
  std::cout << "***"
            << "Commond"
            << "***" << std::endl;
}
}; // namespace Commond

#endif // COMMOND_H
