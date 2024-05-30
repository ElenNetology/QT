#include <QCoreApplication>
#include <QtSql/QSqlDatabase>
#include <QtNetwork/QtNetwork>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QSqlDatabase Sql;
    QHostAddress Network;

    return a.exec();
}
