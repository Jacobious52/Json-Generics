/************************************\
|*   Copyright 2015 Jacob Gonzalez  *|
|*             a1687803             *|
|* -------------------------------- *|
|*          (╯°□°）╯︵ ┻━┻           *|
\************************************/

#include "GConfig.h"
#include "Json.h"

int main()
{
    //-old--stuff--//

   /* // example of loading in a json file to Generic Objects
    GConfig config = GConfig::read("test.json");
    // print it
    std::cout << config.getDict() << std::endl;

    // get the biomes dict
    // biomes is in the top level so we pas config.getDict()
    GDict *biomes = GDictFromDict(config.getDict(), "biomes");

    // forest is in the biomes dictionary
    // as forest is also a dictionary, get it like this
    GDict *forest = GDictFromDict(biomes, "forest");

    // freq is a number in forest dict
    // so get the number like so
    GNumber *freq = GNumberFromDict(forest, "freq");

    // print it
    std::cout << "freq " << freq << std::endl;

    // get the array door in one go which it in the tiles dict, which is on the first level
    GArray *door = GArrayFromDict(GDictFromDict(config.getDict(), "tiles"), "door");

    // print it
    std::cout << door << std::endl;

    // Get the 3rd String from the array door
    std::cout << GStringFromArray(door, 2) << std::endl;
*/

    //--new stuff---

    //--json--//

    Json json = Json::load("test.json");

    std::cout << json["biomes"]["forest"]["smell"].asString() << std::endl;
    std::cout << json["tiles"]["wood"][2].asString() << std::endl;

    std::cout << "[enumerating an array]" << std::endl;
    for (auto gobject : json["tiles"]["door"].asArray())
    {
        std::cout << gobject << std::endl;
    }

    // say i want the plains biome as a map

    //auto plains = json["biomes"]["plains"].asDict();
     // or
    auto plains = asDict(json["biomes"]["plains"].asGeneric());

    // now it's a map we have to use the old ways (no json object)

    std::string smell = asString(plains["smell"]);
    std::cout << "plains smell like " << smell << std::endl;

    return 0;
}
