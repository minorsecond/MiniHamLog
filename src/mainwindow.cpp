//
// Created by Ross Wardrup on 8/8/21.
//

#include "mainwindow.h"
#include "../ui/ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
: QMainWindow(parent)
, ui(new Ui::MainWindow)
{
    /*
     * Set up the main window
     */

    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}