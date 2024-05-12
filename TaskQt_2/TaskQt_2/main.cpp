#include "mainwindow.h"

#include <QApplication>
#include <QSqlDatabase>
#include <QTcpSocket>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    QTcpSocket* socket;
    w.show();
    return a.exec();
}
