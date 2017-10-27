#include <iostream>
#include <vector>

int main()
{
    auto f = [] { return 5; };
    std::cout << f() << std::endl;
    int x = 10;
    auto func = [&x](int y)->int { return (x = y + x); };
    std:: cout << func(10) << std::endl;
    std:: cout << x << std::endl;

    return 0;
}
