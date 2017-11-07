#include <iostream>

class Widget
{
public:
    Widget() = default;

    Widget(Widget&& widget)
    {
        std::cout << "move" << '\n';
    }

    ~Widget() = default;
};

int test(Widget&& w)
{
    return 0;
}

int main()
{
    Widget w;
    test(std::move(ww));
    return 0;
}
