#include <iostream>
#include <string>

class Base 
{
public:
    Base(const std::string& str)
    {
        std::cout << "base constructor " << str << std::endl;
    }

    virtual ~Base()
    {
        std::cout << "base destructor" << std::endl;
    }
};

class Child : public Base
{
public:
    Child() : Base("base"), base_("member")
    {
        std::cout << "child constructor" << std::endl;
    }

    virtual ~Child()
    {
        std::cout << "child destructor" << std::endl;
    }
private:
    Base base_;
};

int main()
{
    char *str = new char[sizeof(Child)];
    Base* b = new(str) Child;
    std::cout << sizeof(Base) << std::endl;
    b->~Base();
    delete[] str;
    return 0;
}
