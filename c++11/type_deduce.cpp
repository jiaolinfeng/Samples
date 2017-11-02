#include <iostream>
#include <typeinfo>
using namespace std;

#define _BOOST_
#ifdef _BOOST_
#include <boost/type_index.hpp>
using boost::typeindex::type_id_with_cvr;
#endif

// case one: reference or pointer
template<typename T>
void dog(T& param)
{
    cout << "T& :" << '\n';
    cout << "T(typeid) = " << typeid(T).name() << '\n';
    cout << "param(typeid) = " << typeid(param).name() << '\n';
#ifdef _BOOST_
    cout << "T(boost) = " << type_id_with_cvr<T>().pretty_name() << '\n';
    cout << "param(boost)= "
         << type_id_with_cvr<decltype(param)>().pretty_name() << '\n';
#endif
    cout << '\n';
}

template<typename T>
void cat(const T& param)
{
    cout << "const T& :" << '\n';
    cout << "T(typeid) = " << typeid(T).name() << '\n';
    cout << "param(typeid) = " << typeid(param).name() << '\n';
#ifdef _BOOST_
    cout << "T(boost) = " << type_id_with_cvr<T>().pretty_name() << '\n';
    cout << "param(boost)= "
         << type_id_with_cvr<decltype(param)>().pretty_name() << '\n';
#endif
    cout << '\n';
}

// case two: universal reference (perfect forward)
template<typename T>
void pig(T&& param)
{
    cout << "T&& :" << '\n';
    cout << "T(typeid) = " << typeid(T).name() << '\n';
    cout << "param(typeid) = " << typeid(param).name() << '\n';
#ifdef _BOOST_
    cout << "T(boost) = " << type_id_with_cvr<T>().pretty_name() << '\n';
    cout << "param(boost)= "
         << type_id_with_cvr<decltype(param)>().pretty_name() << '\n';
#endif
    cout << '\n';
}

//case three: non-reference and non-pointer
template<typename T>
void fox(T param)
{
    cout << "T :" << '\n';
    cout << "T(typeid) = " << typeid(T).name() << '\n';
    cout << "param(typeid) = " << typeid(param).name() << '\n';
#ifdef _BOOST_
    cout << "T(boost) = " << type_id_with_cvr<T>().pretty_name() << '\n';
    cout << "param(boost)= "
         << type_id_with_cvr<decltype(param)>().pretty_name() << '\n';
#endif
    cout << '\n';
}

void someFunc()
{
}

int main()
{
    int x = 1;
    // case one
    dog(x); // T => int, ParamType => int&
    int&& rrx = std::move(x);
    cat(x); // T => int, ParamType => const int&
    cat(rrx); // T => int, ParamType => const int&
    cat(std::move(x)); // T => int, ParamType => const int&
    // dog(1); // error: T => int, 1 cannot passed to int&
    cat(1); // T => int, ParamType => const int&

    // case two
    pig(x); // T => int&, ParamType => int&
    int& y = x;
    pig(rrx); // T => int&, ParamType => int&
    const int zz = 10;
    pig(y); // T => int&, ParamType => int&
    pig(std::move(x)); // T => int,  ParamType => int&&
    pig(zz);// T => const int&, ParamType => const int&

    // case three
    // reference, const, volatile are ignored
    const int o = 2;
    volatile int p = 3;
    const int &q = x;
    const char* const str = "hello";
    fox(o); // T => int, ParamType => int
    fox(p); // T => int, ParamType => int
    fox(q); // T => int, ParamType => int
    fox(str); // T, ParamType => const char*, constness of str self is ignored

    int arr[] = {1, 2, 3};
    fox(arr); // T => int*, ParamType => int*
    dog(arr); // T => int [3], ParamType => int (&)[3]

    fox(someFunc); // T, ParamType => void (*)()
    dog(someFunc); // T => void(), ParamType => void (&)()

    return 0;
}
