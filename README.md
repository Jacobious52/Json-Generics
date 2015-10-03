# Generics
Classes to provide Generic like support for common C++ data types.

Allows for having mixed types in other Generic types.

e.g have a map with a string and an vector which has a float and a string

####Generic - base class
####GNumber - int, float
####GString - std::string
####GArray - std::vector<Generic *>
####GDict = std::map<std::string, Generic *>
