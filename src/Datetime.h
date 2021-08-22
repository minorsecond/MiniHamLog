//
// Created by Ross Wardrup on 8/6/21.
//

#ifndef MINIHAMLOG_DATETIME_H
#define MINIHAMLOG_DATETIME_H

#include <string>
#include <utility>


class Datetime {
private:
    int year{};
    int month{};
    int day{};
    int hour{};
    int minute{};
    int second{};
    std::string tz{};

public:
    Datetime();
    Datetime(int year, int month, int day, int hour, int min, int sec, std::string tz)
        : year{year}, month{month}, day{day}, hour{hour}, minute{min}, second{sec}, tz{std::move(tz)}{};
    std::string get_timestamp(std::string tz) const;
    void from_std_string(const std::string& datetime_string);
    bool operator<(Datetime &dtobj) const;
};


#endif //MINIHAMLOG_DATETIME_H
