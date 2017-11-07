/**
 * @file async.cpp
 * @brief async test
 * @author JiaoLinfeng, jiaolinfeng@esunny.cc
 * @version 1.0
 * @date 2017-11-07
 */

#include <iostream>
#include <future>

int calc(int x, int y)
{
    return x + y;
}

int main()
{
    auto f = std::async(calc, 10, 20);
    auto res = f.get();
    std::cout << res << '\n';

    f = std::async([res](){ return res - 10;});
    std::cout << f.get() << '\n';

    return 0;
}
