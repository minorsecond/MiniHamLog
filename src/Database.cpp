//
// Created by Ross Wardrup on 8/9/21.
//

#include "Database.h"

void Database::write_qso(Contact &contact, Storage storage) {
    /*
     * Write a new QSO to the table
     * @param contact: A contact object to be written.
     */

    storage.insert(contact);
    flush_db_to_disk(storage);
}

void Database::flush_db_to_disk(Storage storage) {
    /*
     * Flush the DB to disk.
     */

    storage.sync_schema(true);
}
