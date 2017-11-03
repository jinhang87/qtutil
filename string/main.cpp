#include <QCoreApplication>
#include "iso8601format.h"
#include <sstream>

int int_from_string(const string &in, bool *ok = nullptr)
{
    std::stringstream ss(in);
    int num = 0;
    char c = 0;
    if(!(ss >> num)){
        if(ok) *ok = false;
        return 0;
    }
    if(ss >> c) {
        if(ok) *ok = false;
        return 0;
    }
    if(ok) *ok = true;
    return num;
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    {
        std::time_t t = std::time(nullptr);
        std::tm* tm = std::localtime(&t);
        std::cout << Iso8601Format::to_string(*tm);
    }

    {
        std::tm tm = Iso8601Format::from_string("2017-11-03T22:22:22");
        std::cout << std::setw(4) << std::setfill('0') << tm.tm_year + 1900 << "-"
                  << std::setw(2) << std::setfill('0') << tm.tm_mon + 1 << "-"
                  << std::setw(2) << std::setfill('0') << tm.tm_mday << 'T'
                  << std::setw(2) << std::setfill('0') << tm.tm_hour << ":"
                  << std::setw(2) << std::setfill('0') << tm.tm_min << ":"
                  << std::setw(2) << std::setfill('0') << tm.tm_sec;
    }
    {
        bool ok = false;
        int ret = int_from_string("12332" , &ok);
        std::cout << "num : " << ret << " ok : " << ok;
    }

    return a.exec();
}
