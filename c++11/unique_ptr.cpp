#include <iostream>
#include <memory>
using namespace std;

class Widget
{
public:
    virtual ~Widget()
    {
        cout << "widget destructor\n";
    }
};

void showWidget(shared_ptr<Widget> pw)
{
    cout << pw.get() << '\n';
}

unique_ptr<Widget> makeWidget()
{
    auto pw = unique_ptr<Widget>(new Widget);
    return pw;
}

int main()
{
    auto pw = makeWidget();
    cout << pw.get() << '\n';
    //unique_ptr<Widget> pw1 = pw; // error
    unique_ptr<Widget> pw1 = std::move(pw);
    cout << pw.get() << ' ' << pw1.get() << '\n';
    // showWidget(pw1); error
    showWidget(makeWidget());

    shared_ptr<Widget> pw2 = std::move(pw1);
    cout << pw1.get() << ' ' << pw2.get() << '\n';
    shared_ptr<Widget> pw3 = makeWidget();
    cout << pw3.get() << endl;
    return 0;
}
