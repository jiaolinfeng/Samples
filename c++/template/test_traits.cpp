#include <iostream>
#include <iostream>
#include <cstdio>

template <typename T>
struct is_void_mine
{
    static const bool value = false;
};

template <>
struct is_void_mine<void>
{
    static const bool value = true;
};

template <typename T, T t>
struct integer_constant
{
    static const T value = t;
    typedef T value_type;
    typedef integer_constant<T, t> type;
    operator value_type() // convention function
    {
        return value;
    }
};

int main()
{
    using namespace std;
    cout << is_void_mine<int>::value << endl;
    cout << is_void_mine<void>::value << endl;
    cout << integer_constant<int, 10>::value << endl;
    integer_constant<int, 0>::value_type i = 10;
    cout << i << endl;
    auto ki = integer_constant<int, 20>(); // konst(const) int
    cout << static_cast<integer_constant<int, 0>::value_type>(ki) << endl;
    return 0;
}
