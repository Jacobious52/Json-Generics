#include "GConfig.h"
#include <fstream>
#include <sstream>

int main()
{
    // example of loading in a json file to Generic Objects
    GConfig config = GConfig::read("test.txt");
    std::cout << config.getDict() << std::endl;

    return 0;
}
