//
// Created by Ross Wardrup on 8/6/21.
//

#include "Utilities.h"
#include <iomanip>
#include <sstream>

std::string Utilities::zero_pad_integer(int length, int input) {
    /*
     * Add zeros to front of integer until it reaches desired length
     * @param length: Desired length of string
     * @param input: integer to zero-pad
     */

    std::ostringstream ss;
    ss << std::setw(length) << std::setfill('0') << input;
    return ss.str();
}