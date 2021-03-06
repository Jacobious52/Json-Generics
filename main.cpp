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

    Json json = Json::fromFile("test.json");

    // using has to check
    if (json["biomes"]["forest"].has("smell")) {
        // now get the value
        std::cout << json["biomes"]["forest"]["smell"].asString() << std::endl;
    } else {
        std::cout << "not found" << std::endl;
    }

    // using tryGet with lambdas and type function
    json["biomes"]["forest"].tryGet("smell", asString, [](std::string value) {
        // use the value of type ~~~~~~~~~~~~~~^^^ passed into ~~~~~~~~^^^
        std::cout << value << std::endl;
    }, [](){
        // else lambda
        std::cout << "not found" << std::endl;
    });

    /*std::cout << json["biomes"]["forest"]["smell"].asString() << std::endl;
    std::cout << json["tiles"]["wood"][2].asString() << std::endl;

    std::cout << "[enumerating an array]" << std::endl;
    json["tiles"]["door"].iter([](Json g){
        std::cout << g.asGeneric() << std::endl;
    });

    std::cout << "[enumerating a dict of ints]" << std::endl;
    json["test"].zip([](std::string key, int i){
        std::cout << key << " = " << i << std::endl;
    }, asInt);

    // say i want the plains biome as a map

    //auto plains = json["biomes"]["plains"].asDict();
     // or
    auto plains = asDict(json["biomes"]["plains"].asGeneric());

    // now it's a map we have to use the old ways (no json object)

    std::string smell = asString(plains["smell"]);
    std::cout << "plains smell like " << smell << std::endl;
*/
    return 0;
}
