# Generics
Classes to provide plain text serializable generic support for common C++ data types.

Allows for having mixed types in other generic types.
Built in plain text serialization behaviour using streams

e.g Have a map with a string and a vector, which has a float and a string and another map inside, with an int... etc

`Generic - base class`

`GNumber - int \ float`

`GString - std::string`

`GArray - std::vector<Generic *>`

`Dict - std::map<std::string, Generic *>`
____
`GConfig` - Wrapper around a `GDict`
Used for writing and reading from a file. In a json like format
