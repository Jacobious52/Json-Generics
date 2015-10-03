#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <string>
#include <streambuf>

// sam's code that I totally cut up and fixed and enhanced ;)
static inline std::vector<std::string> splitLine(std::string line, bool &good)
{
    std::vector<std::string> parts;
    std::string value = "";
    bool escaped = false;
    char escapeChar = '\0';

    if (line == "")
    {
        return parts;
    }

    for (unsigned i = 0; i < line.length(); i++)
    {
        if (line[i] == '[')
        {
            escapeChar = ']';
            escaped = true;
            // keep the [
            value += line[i];
        }
        else if (line[i] == '{')
        {
            escapeChar = '}';
            escaped = true;
            // keep the [
            value += line[i];
        }
        else if (line[i] == escapeChar)
        {
            escapeChar = '\0';
            escaped = false;
            // keep the ]
            value += line[i];
        }
        else if (line[i] == ',' && !escaped)
        {
            // Split by the comma (if not escaped)
            parts.push_back(value);
            value = "";
        }
        else
        {
            value += line[i];
        }
    }

    if (escaped)
    {
        std::cout << "Generic : missing inner " << escapeChar << std::endl;
        good = false;
    }

    // Add the last value
    parts.push_back(value);
    return parts;
}

static inline std::string flattern(std::string str)
{
    std::size_t nextPos = str.find_first_of("\t\n");
    while(nextPos != std::string::npos)
    {
        str.erase(nextPos, 1);
        nextPos = str.find_first_of("\t\n");
    }
    return str;
}

static inline std::string streamToString(std::istream &stream)
{
    return std::string((std::istreambuf_iterator<char>(stream)), std::istreambuf_iterator<char>());
}

#endif // UTILS_H
