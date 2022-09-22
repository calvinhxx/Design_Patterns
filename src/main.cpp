#include "Creational_Patterns/simplefactory.h"
#include "Creational_Patterns/factorymethod.h"
#include "Creational_Patterns/abstractfactory.h"
#include "Creational_Patterns/builder.h"
#include "Creational_Patterns/prototype.h"
#include "Creational_Patterns/singleton.h"

int main(int argc, char *argv[])
{
    SimpleFactory::Client();
    FactoryMethod::Client();
    AbstractFactory::Client();
    Builder::Client();
    Prototype::Client();
    Singleton::Client();
}
