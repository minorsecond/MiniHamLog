//
// Created by Ross Wardrup on 8/9/21.
//

#include "Database.h"
#include <QStandardPaths>
#include <filesystem>
#include <iostream>

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

Storage Database::get_storage() {
    /*
     * Gets the storage object.
     */

    std::cout << "Initializing storage" << std::endl;
    return initStorage(get_storage_path());
}

std::string Database::get_storage_path() {
    /*
     * Gets the path to the storage DB.
     */
    const std::string dir {QStandardPaths::standardLocations(QStandardPaths::AppDataLocation).at(0).toStdString()};
    std::string full_path {dir + "/minihamlog.db"};
    std::filesystem::create_directory(dir);

    std::cout << "Using DB located at: " << full_path << std::endl;

    return full_path;
}
