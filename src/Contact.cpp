//
// Created by Ross Wardrup on 8/6/21.
//

#include "Contact.h"

Contact::Contact() = default;

void Contact::set_qso_sent(bool status) {
    /*
     * Set QSO sent status
     */

    qso_sent = status;
}

void Contact::set_qso_recd(bool status) {
    /*
     * Set QSO Received status
     */

    qso_recd = status;
}
