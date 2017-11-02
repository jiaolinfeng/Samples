/**
 * @file constexpr.cpp
 * @brief
 * @author JiaoLinfeng, jiaolinfeng@esunny.cc
 * @version 1.0
 * @date 2017-10-31
 */

#include <iostream>

constexpr int pow(int base, int exp) noexcept
{
    return exp == 0 ? 1 :
           (exp % 2 ?
           pow(base, exp/2) * pow(base, exp/2) * base :
           pow(base, exp/2) * pow(base, exp/2));

}

class Point
{
public:
    constexpr Point(double xVal = 0, double yVal = 0) noexcept
    : x(xVal), y(yVal)
    {}

    constexpr double xValue() const noexcept
    {
        return x;
    }

    constexpr double yValue() const noexcept
    {
        return y;
    }

    void setX(double newX) noexcept
    {
        x = newX;
    }

    void setY(double newY) noexcept
    {
        y = newY;
    }

private:
    double x, y;
};

template <int param>
struct Data
{
    int val;
    Data()
    {
        val = param;
    }
};

int main()
{
    constexpr int base = 2; // compile-time
    constexpr int exp = 10; // compile-time
    Data<pow(base, exp)> data;
    std::cout << data.val << std::endl;

    constexpr Point p(2.0, 4.0); // compile-time
    Data<static_cast<int>(p.xValue())> x_data;
    Data<static_cast<int>(p.yValue())> y_data;
    std::cout << x_data.val << ' ' << y_data.val << std::endl;

    int param = 10; // runtime
    // Data<param> data; // error:runtime expression can't instantiate templates
    return 0;
}
