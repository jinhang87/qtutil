#include "iso8601format.h"
#include <sstream>

Iso8601Format::Iso8601Format()
{

}

std::tm Iso8601Format::from_string(const std::string &in, bool *ok)
{
    std::tm tm;

    if (in.length() < 19) {
        if(ok) *ok = false;
        return tm;
    }

    if (in[4] != '-' || in[7] != '-' || in[13] != ':' || in[16] != ':') {
        if(ok) *ok = false;
        return tm;
    }

    tm.tm_wday = 0;
    tm.tm_yday = 0;
    tm.tm_year = std::stoi(in.substr(0, 4)) - 1900;
    tm.tm_mon = std::stoi(in.substr(5, 2)) - 1;
    tm.tm_mday = std::stoi(in.substr(8, 2));
    tm.tm_hour = std::stoi(in.substr(11, 2));
    tm.tm_min = std::stoi(in.substr(14, 2));
    tm.tm_sec = std::stoi(in.substr(17, 2));
    tm.tm_isdst = 0;

    if(ok) *ok = true;
    return tm;
}

std::string Iso8601Format::to_string(const std::tm &tm)
{
    std::ostringstream oss;
    const char separator = 'T';

    oss << std::setw(4) << std::setfill('0') << tm.tm_year + 1900 << "-"
        << std::setw(2) << std::setfill('0') << tm.tm_mon + 1 << "-"
        << std::setw(2) << std::setfill('0') << tm.tm_mday << separator
        << std::setw(2) << std::setfill('0') << tm.tm_hour << ":"
        << std::setw(2) << std::setfill('0') << tm.tm_min << ":"
        << std::setw(2) << std::setfill('0') << tm.tm_sec;

    return oss.str();
}
