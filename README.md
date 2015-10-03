# Generics
Classes to provide Generic like support for common C++ data types.

Allows for having mixed types in other Generic types.
Built in plain text serialization behaviour using streams

e.g have a map with a string and an vector which has a float and a string

####Generic - base class
####GNumber - int, float
####GString - std::string
####GArray - std::vector<Generic *>
####GDict - std::map<std::string, Generic *>
____
#### GConfig - Wrapper around a GDict
Used for writing and reading from a file. In a json like format
