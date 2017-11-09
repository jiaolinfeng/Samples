/**
 * @file atomic.cpp
 * @brief atomic test
 * @author JiaoLinfeng, jiaolinfeng@esunny.cc
 * @version 1.0
 * @date 2017-11-08
 */
#include <unistd.h>
#include <iostream>
#include <thread>
#include <atomic>

int main()
{
    int val = 0;
    //bool running;
    volatile bool running;
    //std::atomic<bool> running;
    running = true;

    std::thread t1([&running, &val] {
        while (running)
        {
        }
        std::cout << val << '\n';
    });

    std::thread t2([&running, &val] {
        val = 10;
        running = false;
    });

    t1.join();
    t2.join();

    return 0;
}
