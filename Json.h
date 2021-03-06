/************************************\
|*   Copyright 2015 Jacob Gonzalez  *|
|*             a1687803             *|
|* -------------------------------- *|
|*          (╯°□°）╯︵ ┻━┻           *|
\************************************/

#ifndef JSON_H
#define JSON_H

#include "Generics.h"
#include <fstream>

class Json
{
public:
    // use this
    static Json fromFile(std::string filename);
    // or this
    static Json fromString(std::string str);

    static Json fromGeneric(Generic *g);

    Json(){}
    Json(Generic *object, int ref);

    // primitive reference counting so don't keep intermediate objects
    ~Json();

    // return a json from a dict type
    Json operator[](std::string key);

    // return a json from a array type
    Json operator[](size_t index);

    template <typename Func>
    void iter(Func f)
    {
        for (auto &g : asArray())
        {
            f(Json(g, refCount+1));
        }
    }

    template <typename Func, typename To>
    void iter(Func f, To t)
    {
        for (auto &g : asArray())
        {
            f(t(g));
        }
    }

    template <typename Func>
    void zip(Func f)
    {
        for (auto &g : asDict())
        {
            f(g.first, Json(g.second, refCount+1));
        }
    }

    template <typename Func, typename To>
    void zip(Func f, To t)
    {
        for (auto &g : asDict())
        {
            f(g.first, t(g.second));
        }
    }

    bool has(std::string key);

    template <typename Fail, typename To, typename Func>
    void tryGet(std::string key, To t, Func f, Fail e)
    {
        if (has(key))
        {
            f(t(asDict()[key]));
        }
        else
        {
            e();
        }
    }

    // same as global asArray()
    // no type checking. use at own risk
    std::vector<Generic *> asArray();

    // same as global asDict()
    // no type checking. use at own risk
    std::map<std::string, Generic *> asDict();

    // same as global asDict()
    // no type checking. use at own risk
    int asInt();

    // no type checking. use at own risk
    float asFloat();

    // same as global aString()
    // no type checking. use at own risk
    std::string asString();

    Generic *asGeneric();

private:
        Generic *gobject;
        int refCount;
};

#endif // JSON_H
