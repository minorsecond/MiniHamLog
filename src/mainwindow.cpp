//
// Created by Ross Wardrup on 8/8/21.
//

#include "mainwindow.h"
#include "../ui/ui_mainwindow.h"
#include "../src/Datetime.h"
#include "Contact.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
: QMainWindow(parent)
, ui(new Ui::MainWindow)
{
    /*
     * Set up the main window
     */
    Database::flush_db_to_disk(storage);
    ui->setupUi(this);
    this->setFixedSize(this->width(), this->height());

    // Slots
    connect(ui->submitButton, &QPushButton::clicked, this, &MainWindow::submit_button_clicked);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::submit_button_clicked() {
    /*
     * Handles actions when user clicks the submit button
     */

    std::string tz {"UTC"};

    const int year {std::stoi(ui->dateTimeInput->dateTime().toString("yyyy").toStdString())};
    const int month {std::stoi(ui->dateTimeInput->dateTime().toString("MM").toStdString())};
    const int day {std::stoi(ui->dateTimeInput->dateTime().toString("dd").toStdString())};
    const int hour {std::stoi(ui->dateTimeInput->dateTime().toString("hh").toStdString())};
    const int minute {std::stoi(ui->dateTimeInput->dateTime().toString("mm").toStdString())};
    const int second {std::stoi(ui->dateTimeInput->dateTime().toString("ss").toStdString())};

    const Datetime datetime(year, month, day, hour, minute, second, tz);

    Contact new_contact(
            datetime.get_timestamp(tz),
            ui->rxCallEntry->text().toStdString(),
            ui->rxRSTEntry->text().toStdString(),
            ui->rxGridEntry->text().toStdString(),
            ui->rxNameEntry->text().toStdString(),
            ui->rxAddyEntry->text().toStdString(),
            ui->rxCityEntry->text().toStdString(),
            ui->rxStateEntry->text().toStdString(),
            ui->postalCodeEntry->text().toStdString(),
            ui->rxCountryEntry->text().toStdString()
            );

    Database::write_qso(new_contact, storage);
}
