#ifndef GENERICS_H
#define GENERICS_H


#include "Generic.h"
#include "GNumber.h"
#include "GString.h"
#include "GArray.h"
#include "GDict.h"

#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <map>

// helpers for GNumber
static inline GNumber *GNumberMake()
{
    return Generic::make<GNumber>();
}

static inline GNumber *GNumberMake(float v)
{
    return Generic::make<GNumber>(v);
}

static inline GNumber *GNumberMake(int v)
{
    return Generic::make<GNumber>(v);
}

// helpers for GString
static inline GString *GStringMake(std::string v)
{
    return Generic::make<GString>(v);
}

static inline GString *GStringMake(const char *v)
{
    return Generic::make<GString>(std::string(v));
}

// helpers for array
static inline GArray *GArrayMake()
{
    return Generic::make<GArray>();
}

static inline GArray *GArrayMake(std::vector<Generic *> v)
{
    return Generic::make<GArray>(v);
}

// helpers for dicts
static inline GDict *GDictMake()
{
    return Generic::make<GDict>();
}

static inline GDict *GDictMake(std::map<std::string, Generic *> v)
{
    return Generic::make<GDict>(v);
}



#endif // GENERICS_H

