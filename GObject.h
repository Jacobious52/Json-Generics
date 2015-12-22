/************************************\
|*   Copyright 2015 Jacob Gonzalez  *|
|*             a1687803             *|
|* -------------------------------- *|
|*          (╯°□°）╯︵ ┻━┻           *|
\************************************/

#ifndef G_OBJECT_H
#define G_OBJECT_H

#include "Generics.h"

class GObject
{
public:
    GObject(Generic *raw);
    ~GObject();

    GObject operator[](size_t index);
    GObject operator[](std::string key);

    template <typename T>
    auto raw() -> decltype(T)
    {
        switch (_raw->type)
        {
            case Generic::kDict:
            return _raw->as<GDict>();
            case Generic::kArray:
            return _raw->as<GArray>();
            case Generic::kString:
            return _raw->as<GString>();
            case Generic::kNumber:
            return _raw->as<GNumber>();
            default:
            return nullptr;
        }
    }
private:
    Generic *_raw;
};

#endif // G_OBJECT_H
