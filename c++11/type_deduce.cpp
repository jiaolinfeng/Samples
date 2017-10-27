#include <iostream>
using namespace std;

// case one: reference or pointer
template<typename T>
void dog(T& param)
{
}

template<typename T>
void cat(const T& param)
{
}

// case two: universal reference (perfect forward)
template<typename T>
void pig(T&& param)
{
}

//case three: non-reference and non-pointer
template<typename T>
void fox(T param)
{
}

void someFunc()
{
}

int main()
{
    int x = 1;
    // case one
    dog(x); // T => int, ParamType => int&
    cat(x); // T => int, ParamType => const int&
    // dog(1); // error: T => int, 1 cannot passed to int&
    cat(1); // T => int, ParamType => const int&

    // case two
    pig(x); // T => int&, ParamType => int&
    int& y = x;
    int&& z = std::move(x);
    const int zz = 10;
    pig(y); // T => int&, ParamType => int&
    pig(z); // T => int,  ParamType => int&&
    pig(zz);// T => const int, ParamType => const int&

    // case three
    // reference, const, volatile are ignored
    const int o = 2;
    volatile int p = 3;
    const int &q = x;
    const char* const str = "hello";
    fox(o); // T => int, ParamType => int
    fox(p); // T => int, ParamType => int
    fox(q); // T => int, ParamType => int
    fox(str); // T => const char*, constness of str self is ignored

    int arr[] = {1, 2, 3};
    fox(arr); // T => int*, ParamType => int*
    dog(arr); // T => int [3], ParamType => int (&)[3]

    fox(someFunc); // T, ParamType => void (*)()
    dog(someFunc); // T => void(), ParamType => void (&)()

    return 0;
}
