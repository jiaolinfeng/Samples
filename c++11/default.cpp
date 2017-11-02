#include <iostream>

class Base
{
public:
    virtual ~Base()
    {
    }

    Base() = default;

    Base(const Base& b) = default;

    Base(Base&& b) = default;
};

int main()
{
    Base b;
    Base bb{b};
    return 0;
}
