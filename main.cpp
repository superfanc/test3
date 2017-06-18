#include "logindialog.h"
#include "mainwindow.h"
#include <QApplication>

#include <QSqlDatabase>
#include <QSqlError>
#include <QMessageBox>
#include <qdebug.h>
#include <QtGui>
#include <QString>
#include <QTextCodec>
#include <QSqlDatabase>
#include <QtSql>
#include <QTableView>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QFile qss(":/qss/blue.css");
    qss.open(QFile::ReadOnly);
    w.setStyleSheet(qss.readAll());
    qss.close();
    w.show();
    return a.exec();
}
