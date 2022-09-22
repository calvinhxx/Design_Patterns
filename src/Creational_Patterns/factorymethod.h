#ifndef FACTORYMETHOD_H
#define FACTORYMETHOD_H

#include <iostream>

///
/// 通过继承,子类实现工厂方法, 符合开闭方便扩展
///

namespace FactoryMethod
{
    class Product
    {
    public:
        Product() {}
        virtual void Print() = 0;
    };

    class ConcreteProductA : public Product
    {
    public:
        ConcreteProductA() {}
        virtual void Print() override
        {
            std::cout << "ConcreteProductA\n" ;
        }
    };

    class ConcreteProductB : public Product
    {
    public:
        ConcreteProductB() {}
        virtual void Print() override
        {
            std::cout << "ConcreteProductB\n" ;
        }
    };

    class Factory
    {
    public:
        Factory() {}
        virtual Product* CreateProduct() = 0;
    };

    class FactoryA : public Factory
    {
    public:
        FactoryA() {}
        virtual Product* CreateProduct() override
        {
            return new ConcreteProductA;
        }
    };

    class FactoryB : public Factory
    {
    public:
        FactoryB() {}
        virtual Product* CreateProduct() override
        {
            return new ConcreteProductB;
        }
    };

    void Client()
    {
        std::cout << "***" << "TestFactoryMethod" << "***\n";

        Factory* factoryA = new FactoryA;
        factoryA->CreateProduct()->Print();

        Factory* factoryB = new FactoryB;
        factoryB->CreateProduct()->Print();

        std::cout << "***" << "TestFactoryMethod" << "***\n";
    }
}

#endif // FACTORYMETHOD_H
