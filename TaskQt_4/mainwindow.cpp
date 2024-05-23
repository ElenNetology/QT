#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->rb_one->setText("Первая радиокнопка");
    ui->rb_two->setText("Вторая радиокнопка");

    int countElements = 10;
    for(int i = 0; i < countElements; ++i)
    {
        ui->cb_elements->addItem("Элемент: " + QString::number(i+1));
    }

    ui->pb_click->setText("Основная кнопка");

    ui->pb_click->setCheckable(true);

    ui->pBar_clicks->setMinimum(0);
    ui->pBar_clicks->setMaximum(10);
    ui->pBar_clicks->setValue(0);

    ui->pBar_clicks->setStyleSheet("QProgressBar {"
                                   "    text-align: center;"
                                   "}"
                                   "     QProgressBar::chunk {"
                                   "    background-color: skyblue;"
                                   "}");
    ui->gb_main->setTitle("");

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_click_clicked(bool checked)
{
    if (ui->pBar_clicks->value() < ui->pBar_clicks->maximum())
    {
        ui->pBar_clicks->setValue(ui->pBar_clicks->value() + 1);
    }
    else
    {
        ui->pBar_clicks->setValue(0);
    }

}


void MainWindow::on_pBar_clicks_valueChanged(int value)
{

}


