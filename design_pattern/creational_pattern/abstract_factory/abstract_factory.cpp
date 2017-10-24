/**
 * @file abstract_factory.cpp
 * @brief abstract factory
 * @author JiaoLinfeng, jiaolinfeng@esunny.cc
 * @version 1.0
 * @date 2017-10-24
 */

#include <iostream>
#include <string>

class AbstractObjectA
{
public:
    virtual ~AbstractObjectA()
    {

    }
    virtual void print() = 0;
};

class AbstractObjectB
{
public:
    virtual ~AbstractObjectB()
    {

    }
    virtual void print() = 0;
};

class ConcreteObjectA1 : public AbstractObjectA
{
public:
    virtual ~ConcreteObjectA1()
    {

    }
    virtual void print() override
    {
        std::cout << "Concrete Object A1!" << std::endl;
    }
};

class ConcreteObjectB1 : public AbstractObjectB
{
public:
    virtual ~ConcreteObjectB1()
    {

    }
    virtual void print() override
    {
        std::cout << "Concrete Object B1!" << std::endl;
    }
};
class ConcreteObjectA2 : public AbstractObjectA
{
public:
    virtual ~ConcreteObjectA2()
    {

    }
    virtual void print() override
    {
        std::cout << "Concrete Object A2!" << std::endl;
    }
};

class ConcreteObjectB2 : public AbstractObjectB
{
public:
    virtual ~ConcreteObjectB2()
    {

    }
    virtual void print() override
    {
        std::cout << "Concrete Object B2!" << std::endl;
    }
};

class AbstractFactory
{
public:
    virtual ~AbstractFactory()
    {

    }

    virtual AbstractObjectA* createObjectA() = 0;

    virtual AbstractObjectB* createObjectB() = 0;
};

class ConcreteFactory1 : public AbstractFactory
{
public:
    virtual ~ConcreteFactory1()
    {

    }

    virtual AbstractObjectA* createObjectA() override
    {
        return new(std::nothrow) ConcreteObjectA1;
    }

    virtual AbstractObjectB* createObjectB() override
    {
        return new(std::nothrow) ConcreteObjectB1;
    }
};

class ConcreteFactory2 : public AbstractFactory
{
public:
    virtual ~ConcreteFactory2()
    {

    }

    virtual AbstractObjectA* createObjectA() override
    {
        return new(std::nothrow) ConcreteObjectA2;
    }

    virtual AbstractObjectB* createObjectB() override
    {
        return new(std::nothrow) ConcreteObjectB2;
    }
};

int main()
{
    AbstractFactory* factory = nullptr;
    for (int i = 0; i < 2; ++i)
    {
        if (i % 2 == 0)
            factory = new(std::nothrow) ConcreteFactory1;
        else
            factory = new(std::nothrow) ConcreteFactory2;
        if (!factory)
        {
            std::cerr << "create factory error" << std::endl;
            return -1;
        }
        AbstractObjectA* objecta = factory->createObjectA();
        if (!objecta)
        {
            std::cerr << "create object a error" << std::endl;
            return -1;
        }
        objecta->print();
        delete objecta;
        objecta = nullptr;

        AbstractObjectB* objectb = factory->createObjectB();
        if (!objectb)
        {
            std::cerr << "create object b error" << std::endl;
            return -1;
        }
        objectb->print();
        delete objectb;
        objectb = nullptr;

        delete factory;
        factory = nullptr;
    }

    return 0;
}
