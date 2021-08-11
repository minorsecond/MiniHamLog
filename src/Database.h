//
// Created by Ross Wardrup on 8/9/21.
//

#ifndef MINIHAMLOG_DATABASE_H
#define MINIHAMLOG_DATABASE_H

#include "../include/sqlite_orm.h"
#include "Contact.h"

inline auto initStorage(const std::string& file_name) {
    /*
     * Initialize the DB
     */

    auto table {sqlite_orm::make_table("qsos",
                                       sqlite_orm::make_column("id", &Contact::id, sqlite_orm::autoincrement(), sqlite_orm::primary_key()),
                                       sqlite_orm::make_column("datetime", &Contact::contact_date),
                                       sqlite_orm::make_column("their_call", &Contact::their_rst),
                                       sqlite_orm::make_column("their_grid", &Contact::their_grid),
                                       sqlite_orm::make_column("their_name", &Contact::their_name),
                                       sqlite_orm::make_column("their_addy", &Contact::their_addy),
                                       sqlite_orm::make_column("their_city", &Contact::their_city),
                                       sqlite_orm::make_column("their_state", &Contact::their_state),
                                       sqlite_orm::make_column("their_zip", &Contact::their_zip),
                                       sqlite_orm::make_column("their_country", &Contact::their_country),
                                       sqlite_orm::make_column("qso_sent", &Contact::qso_sent, sqlite_orm::default_value(false)),
                                       sqlite_orm::make_column("qso_recd", &Contact::qso_recd, sqlite_orm::default_value(false)))};
    return sqlite_orm::make_storage(file_name, table);
}

using Storage = decltype (initStorage(""));

class Database {
public:
    std::vector<Contact> read_rows();
    void write_qso(Contact contact);
};


#endif //MINIHAMLOG_DATABASE_H
