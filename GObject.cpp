/************************************\
|*   Copyright 2015 Jacob Gonzalez  *|
|*             a1687803             *|
|* -------------------------------- *|
|*          (╯°□°）╯︵ ┻━┻           *|
\************************************/

#include "GObject.h"

GObject::GObject(Generic *raw)
{
    _raw = raw;
}

GObject::~GObject()
{}


GObject GObject::operator[](size_t index)
{
    return GObject(_raw->as<GArray>()->at<Generic>(index));
}

GObject GObject::operator[](std::string key)
{
    return GObject(_raw->as<GDict>()->get(key));
}

