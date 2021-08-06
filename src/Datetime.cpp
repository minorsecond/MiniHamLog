//
// Created by Ross Wardrup on 8/6/21.
//

#include "Datetime.h"
#include "Utilities.h"

std::string Datetime::get_timestamp() const {
    const std::string zp_month {Utilities::zero_pad_integer(2, month)};
    const std::string zp_day {Utilities::zero_pad_integer(2, day)};
    const std::string zp_hour {Utilities::zero_pad_integer(2, hour)};
    const std::string zp_minute {Utilities::zero_pad_integer(2, minute)};
    const std::string zp_sec {Utilities::zero_pad_integer(2, second)};

    return std::to_string(year) + zp_month + zp_day + zp_hour + zp_minute + zp_sec;
}

Datetime::Datetime() = default;