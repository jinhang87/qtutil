#ifndef ISO8601FORMAT_H
#define ISO8601FORMAT_H

#include <string>
#include <iostream>
#include <iomanip>
#include <ctime>

using std::string;

class Iso8601Format
{
public:
    Iso8601Format();
    static std::tm from_string(const string & in, bool *ok = nullptr);
    static string to_string(const tm &tm);
};

#endif // ISO8601FORMAT_H
