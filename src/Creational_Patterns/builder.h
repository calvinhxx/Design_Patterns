#ifndef BUILDER_H
#define BUILDER_H

#include <iostream>

///
/// 分步骤创建复杂对象，使用相同代码生成不同类型、形式的对象。
///

namespace Builder
{
    class AbstractProduct
    {
    public:
        AbstractProduct() {}
        virtual void Setfeature1() = 0;
        virtual void Setfeature2() = 0;
        virtual void Setfeature3() = 0;
    };
    ///
    /// \brief The Product1 class ***feature的具体实现为打印
    ///
    class Product1 : public AbstractProduct
    {
    public:
        Product1() {}
        virtual void Setfeature1() override
        {
            std::cout << "P1 F1\n";
        }
        virtual void Setfeature2() override
        {
            std::cout << "P1 F2\n";
        }
        virtual void Setfeature3() override
        {
            std::cout << "P1 F3\n";
        }
    };
    ///
    /// \brief The Product2 class  ***feature的具体实现为属性赋值
    ///
    class Product2 : public AbstractProduct
    {
    public:
        Product2() {}
        virtual void Setfeature1() override
        {
            f1_ = true;
        }
        virtual void Setfeature2() override
        {
            f2_ = true;
        }
        virtual void Setfeature3() override
        {
            f3_ = true;
        }
        void Print()
        {
            if( f1_ )
            {
                std::cout << "P2 F1\n";
            }
            else if ( f2_ )
            {
                std::cout << "P2 F2\n";
            }
            else if ( f3_ )
            {
                std::cout << "P2 F3\n";
            }
        }
    private:
        bool f1_ = false;
        bool f2_ = false;
        bool f3_ = false;
    };

    class Builder
    {
    public:
        Builder(){}
        virtual ~Builder(){}
        virtual void Reset() = 0;
        virtual void BuildStepA() = 0;
        virtual void BuildStepB() = 0;
        virtual void BuildStepC() = 0;
    };

    class ConcreteBuilder1 : public Builder
    {
    public:
        ConcreteBuilder1() {}

        virtual void Reset()
        {
            delete product_;
            product_ = new Product1;
        }
        virtual void BuildStepA()
        {
            product_->Setfeature1();
        }
        virtual void BuildStepB()
        {
            product_->Setfeature2();
        }
        virtual void BuildStepC()
        {
            product_->Setfeature3();
        }

        Product1* GetResult()
        {
            return product_;
        }

    private:
        Product1* product_ = nullptr;
    };

    class ConcreteBuilder2 : public Builder
    {
    public:
        ConcreteBuilder2() {}

        virtual void Reset()
        {
            delete product_;
            product_ = new Product2;
        }
        virtual void BuildStepA()
        {
            product_->Setfeature1();
        }
        virtual void BuildStepB()
        {
            product_->Setfeature1();
            product_->Setfeature2();
        }
        virtual void BuildStepC()
        {
            product_->Setfeature1();
            product_->Setfeature2();
            product_->Setfeature3();
        }

        Product2* GetResult()
        {
            return product_;
        }

    private:
        Product2* product_ = nullptr;
    };

    class Director
    {
    public:
        enum BuilderType
        {
            Simple,
            Complex
        };

        Director(Builder* build): builder_(build){}
        void ChangeBuilder(Builder* build)
        {
            delete builder_;
            builder_ = build;
        }
        void Make(BuilderType type)
        {
            builder_->Reset();
            if(type == Simple)
            {
                builder_->BuildStepA();
            }
            else if(type == Complex)
            {
                builder_->BuildStepA();
                builder_->BuildStepB();
                builder_->BuildStepC();
            }
        }
    private:
        Builder* builder_;
    };

    void Client()
    {
        std::cout << "***" << "TestBuild" << "***\n";

        auto b1 = new ConcreteBuilder1;
        auto b2 = new ConcreteBuilder2;
        auto director1 = new Director(b1);
        director1->Make(Director::Complex);
        b1->GetResult();
        auto director2 = new Director(b2);
        director2->Make(Director::Simple);
        b2->GetResult()->Print();

        std::cout << "***" << "TestBuild" << "***\n";
    }
}

#endif // BUILDER_H
