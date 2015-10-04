#include "GConfig.h"

int main()
{
    // example of loading in a json file to Generic Objects
    GConfig config = GConfig::read("test.json");
    std::cout << config.getDict() << std::endl;

    // get the biomes, forest, and freq separately
    GDict *biomes = GDictFromDict(config.getDict(), "biomes");
    GDict *forest = GDictFromDict(biomes, "forest");
    GNumber *freq = GNumberFromDict(forest, "freq");

    std::cout << "freq " << freq << std::endl;

    // get the door in one go
    GArray *door = GArrayFromDict(GDictFromDict(config.getDict(), "tiles"), "door");

    std::cout << door << std::endl;

    // Get the 3rd String from the array
    std::cout << GStringFromArray(door, 2) << std::endl;

    return 0;
}
