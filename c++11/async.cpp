/**
 * @file async.cpp
 * @brief async test
 * @author JiaoLinfeng, jiaolinfeng@esunny.cc
 * @version 1.0
 * @date 2017-11-07
 */

#include <iostream>
#include <future>
#include <type_traits>

int calc(int x, int y)
{
    return x + y;
}

template <typename F, typename... Ts>
std::future<typename std::result_of<F(Ts...)>::type>
realAsync(F&& f, Ts&&... params)
{
    return std::async(std::launch::async, std::forward<F>(f),
        std::forward<Ts>(params)...);
}

int main()
{
    auto f = std::async(calc, 10, 20);
    auto res = f.get();
    std::cout << res << '\n';

    f = realAsync([res](){ return res - 10;});
    std::cout << f.get() << '\n';



    return 0;
}
