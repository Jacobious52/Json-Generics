/************************************\
|*   Copyright 2015 Jacob Gonzalez  *|
|*             a1687803             *|
|* -------------------------------- *|
|*          (╯°□°）╯︵ ┻━┻           *|
\************************************/

#include "Json.h"

Json Json::fromFile(std::string filename)
{
    std::ifstream file(filename);
    GDict *jsonDict = GDictMake();
    file >> jsonDict;
    file.close();
    return Json(jsonDict, 0);
}

Json Json::fromString(std::string str)
{
    std::stringstream ss(str);
    GDict *jsonDict = GDictMake();
    ss >> jsonDict;
    return Json(jsonDict, 0);
}

Json Json::fromGeneric(Generic *g)
{
    return Json(g, 0);
}

Json::~Json()
{
    if (refCount == 0)
    {
        gobject->free();
    }
}

Json Json::operator[](std::string key)
{
    return Json(gobject->as<GDict>()->get(key), refCount+1);
}

Json Json::operator[](size_t index)
{
    return Json(gobject->as<GArray>()->at<Generic>(index), refCount+1);
}

std::vector<Generic *> Json::asArray()
{
    return gobject->as<GArray>()->value;
}

std::map<std::string, Generic *> Json::asDict()
{
    return gobject->as<GDict>()->value;
}

int Json::asInt()
{
    return gobject->as<GNumber>()->asInt();
}

float Json::asFloat()
{
    return gobject->as<GNumber>()->asFloat();
}

std::string Json::asString()
{
    return gobject->as<GString>()->value;
}

Generic *Json::asGeneric()
{
    return gobject;
}

Json::Json(Generic *object, int ref) : gobject(object), refCount(ref)
{}
