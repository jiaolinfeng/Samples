#include <vector>
#include <iostream>
#include <functional>
#include <memory>

template <typename F>
class Signal;

template <typename R, typename... Ts>
class Signal<R(Ts...)>
{
public:
    using Func = std::function<void(Ts...)>;

    void connect(Func&& f)
    {
        funcs_.push_back(std::forward<Func>(f));
    }

    void call(Ts&&... ts)
    {
        for (const auto& f : funcs_)
        {
            f(ts...);
        }
    }

private:
    std::vector<Func> funcs_;
};

void test(int i, int j)
{
    std::cout << i << ' ' << j << '\n';
}

void test_void()
{
    std::cout << "test void" << '\n';
}

int main()
{
    using Test = Signal<void(int, int)>;
    std::unique_ptr<Test> pb(new Test());
    pb->connect(test);
    pb->call(10, 20);
    return 0;
}
