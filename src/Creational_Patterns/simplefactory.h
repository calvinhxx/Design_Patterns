#ifndef SIMPLEFACTORY_H
#define SIMPLEFACTORY_H

#include <iostream>

///
/// 提供一个创建对象的工厂方法, 形参决定返回的对象。
///

namespace  SimpleFactory
{
    class Product
    {
    public:
        virtual void User() = 0;
    };

    class ConcreteProductA : public Product
    {
    public:
        void User() override
        {
            std::cout << "ConcreteProductA\n";
        };
    };

    class ConcreteProductB : public Product
    {
    public:
        void User() override
        {
            std::cout << "ConcreteProductB\n";
        };
    };

    class SimpleFactory
    {
    public:
        SimpleFactory()
        {

        };
        enum ProductType
        {
            A,
            B
        };
        Product* CreateProduct(ProductType type)
        {
            if(type == A)
            {
                return new ConcreteProductA();
            }
            else if(type == B)
            {
                return new ConcreteProductB();
            }
            else
            {
                return nullptr;
            }
        }
    };

    void Client()
    {
        std::cout << "***" << "TestSimpleFactory" << "***\n";

        auto simpleFactory = new SimpleFactory();
        simpleFactory->CreateProduct(SimpleFactory::ProductType::A)->User();
        simpleFactory->CreateProduct(SimpleFactory::ProductType::B)->User();

        std::cout << "***" << "TestSimpleFactory" << "***\n";
        std::cout << "";
    }
}

#endif // SIMPLEFACTORY_H
