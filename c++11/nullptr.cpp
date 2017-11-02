#include <iostream>

int inc(int i)
{
    return i + 1;
}

void test(int i)
{
    std::cout << "test integer " << i << std::endl;
}

void test(void* p)
{
    std::cout << "test pointer " << p << std::endl;
}

int main()
{
    inc((int)NULL);
    // inc(static_cast<int>(nullptr)); // error: can not cast

    // test(NULL); // error: call to test is ambigous
    test(nullptr);
    return 0;
}
