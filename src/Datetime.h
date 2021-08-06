//
// Created by Ross Wardrup on 8/6/21.
//

#ifndef MINIHAMLOG_DATETIME_H
#define MINIHAMLOG_DATETIME_H

#include <string>


class Datetime {
private:
    int year{};
    int month{};
    int day{};
    int hour{};
    int minute{};
    int second{};

public:
    Datetime();
    Datetime(int year, int month, int day, int hour, int min, int sec)
        : year{year}, month{month}, day{day}, hour{hour}, minute{min}, second{sec} {};
    std::string get_timestamp() const ;
};


#endif //MINIHAMLOG_DATETIME_H
