#include <iostream>
#include <vector>
using namespace std;

/*
//requires refinement
template<typename Container, typename Index>
auto authAndAccess(Container& c, Index i) -> decltype(c[i])
{
    return c[i];
}
*/

/*
//c++ 14 needed
template<typename Container, typename Index>
decltype(auto) authAndAccess(Container& c, Index i)
{
    return c[i];
}
*/

template<typename Container, typename Index>
auto authAndAccess(Container&& c, Index i)
    -> decltype(std::forward<Container>(c)[i])
{
    return std::forward<Container>(c)[i];
}

int main()
{
    std::vector<int> v({1, 2, 3});
    authAndAccess(std::move(v), 2) = 4;
    cout << v[2] << endl;
    return 0;
}
