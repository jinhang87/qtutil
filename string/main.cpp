#include <QCoreApplication>
#include "iso8601format.h"


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
    return a.exec();
}
