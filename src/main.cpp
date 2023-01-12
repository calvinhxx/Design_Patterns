#include "Creational_Patterns/abstractfactory.h"
#include "Creational_Patterns/builder.h"
#include "Creational_Patterns/factorymethod.h"
#include "Creational_Patterns/prototype.h"
#include "Creational_Patterns/simplefactory.h"
#include "Creational_Patterns/singleton.h"

#include "Structural_Patterns/adapter.h"
#include "Structural_Patterns/bridge.h"
#include "Structural_Patterns/composite.h"
#include "Structural_Patterns/decorator.h"
#include "Structural_Patterns/facade.h"
#include "Structural_Patterns/flyweight.h"
#include "Structural_Patterns/proxy.h"

#include "Behavioral_Patterns/chain-of-responsibility.h"
#include "Behavioral_Patterns/commond.h"
#include "Behavioral_Patterns/lterator.h"
#include "Behavioral_Patterns/mediator.h"
#include "Behavioral_Patterns/memento.h"
#include "Behavioral_Patterns/observer.h"
#include "Behavioral_Patterns/state.h"
#include "Behavioral_Patterns/strategy.h"
#include "Behavioral_Patterns/template-method.h"
#include "Behavioral_Patterns/visitor.h"

///
/// 具体例子替换为抽象例子
///

int main(int argc, char *argv[]) {
  // creational
  SimpleFactory::Client();
  FactoryMethod::Client();
  AbstractFactory::Client();
  Builder::Client();
  Prototype::Client();
  Singleton::Client();
  // structural
  Adapter::Client();
  Bridge::Client();
  Composite::Client();
  Decorator::Client();
  Facade::Client();
  FlyWeight::Client();
  Proxy::Client();
  // behavioral
  ChainOfResponsibility::Client();
  Commond::Client();
  Lterator::Client();
  Mediator::Client();
  Memento::Client();
  Observer::Client();
  State::Client();
  Strategy::Client();
  TemplateMethod::Client();
  Visitor::Client();
}
