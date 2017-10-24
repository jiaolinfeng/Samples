/**
 * @file simple_factory.cpp
 * @brief simple factory
 * @author JiaoLinfeng, jiaolinfeng@esunny.cc
 * @version 1.0
 * @date 2017-10-24
 */
#include <iostream>
#include <string>
using namespace std;

class AbstractObject
{
public:
    virtual ~AbstractObject()
    {

    }

    virtual void print() = 0;
};

class ConcreteObjectA : public AbstractObject
{
public:
    virtual ~ConcreteObjectA()
    {

    }

    virtual void print() override
    {
        std::cout << "Concrete Object A!" << std::endl;
    }
};

class ConcreteObjectB : public AbstractObject
{
public:
    virtual ~ConcreteObjectB()
    {

    }

    virtual void print() override
    {
        std::cout << "Concrete Object B!" << std::endl;
    }
};

class SimpleFactory
{
public:
    static AbstractObject* createObject(const std::string &obj_name)
    {
        if (!obj_name.compare("ConcreteObjectA"))
        {
            return new(std::nothrow) ConcreteObjectA;
        }
        else if (!obj_name.compare("ConcreteObjectB"))
        {
            return new(std::nothrow) ConcreteObjectB;
        }
        else
            return nullptr;
    }
};

int main()
{
    AbstractObject* obj = SimpleFactory::createObject("ConcreteObjectA");
    if (obj)
    {
        obj->print();
        delete obj;
        obj = nullptr;
    }
    obj = SimpleFactory::createObject("ConcreteObjectB");
    if (obj)
    {
        obj->print();
        delete obj;
        obj = nullptr;
    }
    return 0;
}
