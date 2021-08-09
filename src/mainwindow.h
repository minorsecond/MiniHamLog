//
// Created by Ross Wardrup on 8/8/21.
//

#ifndef MINIHAMLOG_MAINWINDOW_H
#define MINIHAMLOG_MAINWINDOW_H

#include <QMainWindow>

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
};

#endif //MINIHAMLOG_MAINWINDOW_H
