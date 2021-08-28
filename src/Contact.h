//
// Created by Ross Wardrup on 8/6/21.
//

#ifndef MINIHAMLOG_CONTACT_H
#define MINIHAMLOG_CONTACT_H

#include <utility>
#include "Datetime.h"

class Contact {
    friend auto initStorage(const std::string& file_name);

protected:
    std::string contact_date{};
    std::string their_callsign{};
    std::string their_rst{};
    std::string their_grid{};
    std::string mode{};
    std::string their_name{};
    std::string their_addy{};
    std::string their_city{};
    std::string their_state{};
    std::string their_zip{};
    std::string their_country{};
    bool qsl_sent {false};
    bool qsl_recd {false};
    size_t id{};

public:
    Contact() = default;
    Contact(std::string qso_datetime, std::string their_call, std::string their_rst, std::string their_grid,
            std::string mode, std::string name, std::string addy, std::string city, std::string state, std::string zip,
            std::string country)
        : contact_date{std::move(qso_datetime)}, their_callsign{std::move(their_call)}, their_rst{std::move(their_rst)},
          their_grid{std::move(their_grid)}, mode{std::move(mode)}, their_name{std::move(name)},
          their_addy{std::move(addy)}, their_city{std::move(city)}, their_state{std::move(state)},
          their_zip{std::move(zip)}, their_country{std::move(country)}{};
    void set_qso_sent(bool status);
    void set_qso_recd(bool status);
    std::string get_datetime() const {return contact_date;};
    std::string get_callsign() const {return their_callsign;};
    std::string get_rst() const {return their_rst;};
    std::string get_grid() const {return their_grid;};
    std::string get_name() const {return their_name;};
    std::string get_addy() const {return their_addy;};
    std::string get_city() const {return their_city;};
    std::string get_state() const {return their_state;};
    std::string get_zip() const {return their_zip;};
    std::string get_country() const {return their_country;};
    std::string get_full_addy() const;
    bool get_qsl_sent() const {return qsl_sent;};
    bool get_qsl_recd() const {return qsl_recd;};
};


#endif //MINIHAMLOG_CONTACT_H
