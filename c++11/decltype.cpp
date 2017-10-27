#include <iostream>
#include <vector>

template<typename Container, typename Index>
auto authAndAccess(Container& c, Index i) -> decltype(c[i])
{
    return c[i];
}

/*
//c++ 14 needed
template<typename Container, typename Index>
decltype(auto) authAndAccess(Container& c, Index i)
{
    return c[i];
}
*/

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
