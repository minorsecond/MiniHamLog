//
// Created by Ross Wardrup on 8/6/21.
//

#include "Datetime.h"
#include "Utilities.h"
#include <iostream>
#include <unordered_map>

std::string Datetime::get_timestamp(std::string tz) const {

    std::unordered_map<std::string, int> timezones {{"UTC", 0}};

    auto it {timezones.begin()};


    const std::string zp_month {Utilities::zero_pad_integer(2, month)};
    const std::string zp_day {Utilities::zero_pad_integer(2, day)};
    const std::string zp_hour {Utilities::zero_pad_integer(2, hour)};
    const std::string zp_minute {Utilities::zero_pad_integer(2, minute)};
    const std::string zp_sec {Utilities::zero_pad_integer(2, second)};

    return std::to_string(year) + zp_month + zp_day + zp_hour + zp_minute + zp_sec;
}

bool Datetime::operator<(Datetime &dtobj) const {
    /*
     * Compare dates and determine if dtobj is less than lhs date.
     * @param &dtobj: a reference to a datetime object.
     * @return: True of dtobj is sooner than this date.
     */

    if (year < dtobj.year) {
        return true;
    } else if (year == dtobj.year) {
        if (month < dtobj.month) {
            return true;
        } else if (month == dtobj.month && day < dtobj.day) {
            return true;
        } else if (month == dtobj.month && day == dtobj.day && hour < dtobj.hour) {
            return true;
        } else if (month == dtobj.month && day == dtobj.day && hour == dtobj.hour && minute < dtobj.minute) {
            return true;
        } else if (month == dtobj.month && day == dtobj.day && hour == dtobj.hour && minute == dtobj.minute && second < dtobj.second) {
            return true;
        }
    }
    return false;
}

void Datetime::from_std_string(const std::string& datetime_string) {
    /*
     * Converts datetime from string into datetime object
     * @param datetime_string: String in format  YYYYMMDD HH:MM:SS
     */

    year = std::stoi(datetime_string.substr(0, 4));
    month = std::stoi(datetime_string.substr(4, 2));
    day = std::stoi(datetime_string.substr(6, 2));
    hour = std::stoi(datetime_string.substr(8, 2));
    minute = std::stoi(datetime_string.substr(10, 2));
    second = std::stoi(datetime_string.substr(12, 2));
}

Datetime::Datetime() = default;