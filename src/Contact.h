//
// Created by Ross Wardrup on 8/6/21.
//

#ifndef MINIHAMLOG_CONTACT_H
#define MINIHAMLOG_CONTACT_H

#include "Datetime.h"

class Contact {
private:
    Datetime contact_date{};
    std::string their_callsign{};
    std::string their_rst{};
    std::string their_grid{};
    bool qso_sent {false};
    bool qso_recd {false};

public:
    Contact();
    Contact(Datetime qso_datetime, std::string their_call, std::string their_rst, std::string their_grid)
        : contact_date{qso_datetime}, their_callsign{their_call}, their_rst{their_rst}, their_grid{their_grid} {};
    void set_qso_sent(bool status);
    void set_qso_recd(bool status);
    std::string get_datetime() {return contact_date.get_timestamp()};
    std::string get_their_callsign() {return their_callsign};
    std::string get_their_rst() {return their_rst};
    std::string get_their_grid() {return their_grid};
    bool get_qso_sent() {return qso_sent};
    bool get_qso_recd() {return qso_recd};
};


#endif //MINIHAMLOG_CONTACT_H
