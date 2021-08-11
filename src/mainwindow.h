//
// Created by Ross Wardrup on 8/8/21.
//

#ifndef MINIHAMLOG_MAINWINDOW_H
#define MINIHAMLOG_MAINWINDOW_H

#include <QMainWindow>
#include "Contact.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;
private:
    Ui::MainWindow *ui;
    void write_to_db(Contact contact);  // TODO: This and read_db_rows() should be in separate DB class
    std::vector<Contact> read_db_rows();

private slots:
    void submit_button_clicked();
};

#endif //MINIHAMLOG_MAINWINDOW_H
