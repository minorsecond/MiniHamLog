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

    // Populate modes dropdown
    std::set<std::string> modes {
        "AM",
        "CW",
        "MCW",
        "FM",
        "D-STAR",
        "DMR",
        "FreeDV",
        "ATV",
        "SSTV",
        "AMTOR",
        "Hell",
        "MT63",
        "JT6",
        "JT65",
        "Olivia",
        "Packet",
        "APRS",
        "PACTOR",
        "PSK63",
        "QPSK31",
        "QPSK63",
        "RTTY",
        "SSB",
        "PSK31",
        "FT8"
    };

    for (const auto& mode : modes) {
        ui->modeCBox->addItem(QString::fromStdString(mode));
    }

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

    const int year {std::stoi(ui->qsoDateInput->dateTime().toString("yyyy").toStdString())};
    const int month {std::stoi(ui->qsoDateInput->dateTime().toString("MM").toStdString())};
    const int day {std::stoi(ui->qsoDateInput->dateTime().toString("dd").toStdString())};
    const int hour {std::stoi(ui->qsoTimeInput->dateTime().toString("hh").toStdString())};
    const int minute {std::stoi(ui->qsoTimeInput->dateTime().toString("mm").toStdString())};
    const int second {std::stoi(ui->qsoTimeInput->dateTime().toString("ss").toStdString())};

    const Datetime datetime(year, month, day, hour, minute, second, tz);

    Contact new_contact(
            datetime.get_timestamp(tz),
            ui->rxCallEntry->text().toStdString(),
            ui->rxRSTEntry->text().toStdString(),
            ui->rxGridEntry->text().toStdString(),
            ui->modeCBox->currentText().toStdString(),
            ui->rxNameEntry->text().toStdString(),
            ui->rxAddyEntry->text().toStdString(),
            ui->rxCityEntry->text().toStdString(),
            ui->rxStateEntry->text().toStdString(),
            ui->postalCodeEntry->text().toStdString(),
            ui->rxCountryEntry->text().toStdString()
            );

    Database::write_qso(new_contact, storage);
}
