//
// Created by Ross Wardrup on 8/6/21.
//

#include "Contact.h"

void Contact::set_qso_sent(bool status) {
    /*
     * Set QSO sent status
     */

    qsl_sent = status;
}

void Contact::set_qso_recd(bool status) {
    /*
     * Set QSO Received status
     */

    qsl_recd = status;
}

std::string Contact::get_full_addy() const {
    return their_name + ", " + their_callsign + '\n' + their_addy + '\n' + their_city + ", " + their_state + ' ' +
    their_zip + '\n' + their_country;
}
