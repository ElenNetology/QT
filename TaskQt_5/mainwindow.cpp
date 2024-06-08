#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "stopwatch.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    sw = new Stopwatch(this);
    ui->setupUi(this);

    ui->pb_start_stop->setCheckable(true);
    ui->pb_start_stop->setText("Старт");
    ui->pb_circle->setText("Круг");
    ui->pb_clear->setText("Очистить");
    ui->pb_circle->setEnabled(false);

    connect(sw, &Stopwatch::sig_updateTime, this, &MainWindow::rcv_updateTime);
    connect(this, &MainWindow::sig_circleTime, sw, &Stopwatch::rcv_circleTime);
    connect(this, &MainWindow::sig_clearTime, sw, &Stopwatch::rcv_clearTime);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::rcv_updateTime(QString text)
{
    ui->lb_time->setText(text);
}

void MainWindow::on_pb_start_stop_clicked()
{
    if(ui->pb_start_stop->isChecked()){

        sw->startTimer();
        ui->pb_start_stop->setText("Стоп");
        ui->pb_circle->setEnabled(true);
    }else
    {
        sw->stopTimer();
        ui->pb_start_stop->setText("Старт");
        ui->pb_circle->setEnabled(false);
    }
}

void MainWindow::on_pb_circle_clicked()
{
    //emit sig_circleTime();
    sw->rcv_circleTime();
    QString text = sw->strCircleTime;
    ui->tB_circles->append(text);
}

void MainWindow::on_pb_clear_clicked()
{
    ui->lb_time->setText("00:00.0");
    sw->rcv_clearTime();
    //emit sig_clearTime();
}
