#include "test.helloworld.pb.h"
#include <fstream>

int main()
{
    test::helloworld msg;
    msg.set_id(100);
    msg.set_str("hello");
    //msg.set_opt(200);

    {
        using std::fstream;
        using std::ios;
        fstream output("log", ios::out | ios::trunc | ios::binary);
        if (!msg.SerializeToOstream(&output))
        {
            std::cerr << "Failed to write msg." << std::endl;
            return -1;
        }
    }
    return 0;
}
