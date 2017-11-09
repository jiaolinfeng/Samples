#include <vector>
#include <iostream>
#include <functional>
#include <memory>

template <typename... Ts>
class Signal
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

void test(int i)
{
    std::cout << i << '\n';
}

int main()
{
    using Test = Signal<int>;
    std::unique_ptr<Test> pb(new Test());
    pb->connect(test);
    pb->call(10);
    pb->call(20);
    return 0;
}
