/**
 * @file thread.cpp
 * @brief thread test
 * @author JiaoLinfeng, jiaolinfeng@esunny.cc
 * @version 1.0
 * @date 2017-11-07
 */

#include <iostream>
#include <thread>
#include <unistd.h>

void func(int param1, double param2)
{
    using std::cout;
    cout << "thread print " << param1 << ", " << param2 << '\n';
}

int main()
{
    std::cout << "hardware thread num is "
              << std::thread::hardware_concurrency() << '\n';

    std::thread thd(func, 10, 100.0);
    std::cout << "main print" << '\n';
    usleep(500);
    std::cout << "current thread id is " << thd.get_id() << '\n';
    thd.join();
    return 0;
}

