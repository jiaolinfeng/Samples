#include "test.helloworld.pb.h"
#include <fstream>

int main()
{
    test::helloworld msg;
    {
        using std::fstream;
        using std::ios;
        fstream input("log", ios::in | ios::binary);
        if (!msg.ParseFromIstream(&input))
        {
            std::cerr << "Failed to parse!" << std::endl;
            return -1;
        }
    }
    std::cout << msg.id() << std::endl;
    std::cout << msg.str() << std::endl;
    std::cout << msg.opt() << std::endl;

    return 0;
}
