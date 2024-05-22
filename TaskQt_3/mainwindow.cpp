#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    dialog = new Dialog(this);
    dialog->setFixedSize(dialog->geometry().width(),dialog->geometry().height());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_openDB_clicked()
{
    dialog->show();
}

