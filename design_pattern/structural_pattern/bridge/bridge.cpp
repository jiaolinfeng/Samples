/**
 * @file bridge.cpp
 * @brief bridge
 * @author JiaoLinfeng, jiaolinfeng@esunny.cc
 * @version 1.0
 * @date 2017-10-25
 */

#include <assert.h>
#include <iostream>
#include <string>
#include <memory>

class CleanTool
{
public:
    virtual void work() = 0;
};

class Broom : public CleanTool
{
public:
    virtual ~Broom() {}

    virtual void work() override
    {
        std::cout << "broom sweep" << std::endl;
    }
};

class Water : public CleanTool
{
public:
    virtual ~Water() {}

    virtual void work() override
    {
        std::cout << "water flush" << std::endl;
    }
};

class Cleaner
{
public:
    Cleaner(std::shared_ptr<CleanTool> tool) : tool_(tool) {}

    virtual ~Cleaner() {}

    virtual void clean()
    {
        auto tool = tool_.lock();
        if (tool.get())
        {
            tool->work();
        }
        std::cout << "clean done!" << std::endl;
    }
private:
    std::weak_ptr<CleanTool> tool_;
};

int main()
{
    std::shared_ptr<CleanTool> p_tool(new(std::nothrow) Water);
    assert(p_tool.get());

    std::shared_ptr<Cleaner> p_cleaner(new(std::nothrow) Cleaner(p_tool));
    assert(p_cleaner.get());

    p_cleaner->clean();

    return 0;
}
