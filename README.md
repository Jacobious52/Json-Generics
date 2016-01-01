# Generics
Classes to provide json serializable generic support for common C++ data types.

Allows for having mixed types in other generic types.
Built in json serialization behaviour using streams

e.g Have a map with a string and a vector, which has a float and a string and another map inside, with an int... etc

#Really Basic Reading From File Usage
This uses a json helper to avoid messing with pointers and generic types

```
Json json = Json::load("imaginary_users_list_or_something.json");
std::string email = json["users"]["jayp"]["email"].asString();
int something = json["stuff"][0]["things"]["deeper"][32].asInt();
```

`Generic - base class`

`GNumber - int \ float`

`GString - std::string`

`GArray - std::vector<Generic *>`

`GDict - std::map<std::string, Generic *>`
____
`GConfig` - Wrapper around a `GDict`
Used for writing and reading from a file. In a json format
