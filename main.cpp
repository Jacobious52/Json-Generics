#include "GConfig.h"
#include <fstream>
#include <sstream>

int main()
{
    GConfig config = GConfig::read("test.txt");
    std::cout << config.getDict() << std::endl;

    // this is the safe way
    GNumber *num = config.getAs<GNumber>("global_height");
    if (num != 0)
    {
        std::cout << "float " << num << std::endl;
        // or
        std::cout << "int " << num->asInt() << std::endl;
    }

    // add another dict
    GDict *inner = GDictMake();
    inner->set("hello", GStringMake("that thing"));
    inner->set("goodbye", GStringMake("nested"));

    config.set("d2", inner);

    config.write("test2.txt");

    return 0;
}
