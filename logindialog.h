#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include <QDataStream>
#include <QHash>
#include <QtGui>
#include <QSqlDatabase>
#include <QtSql>

namespace Ui {
class logindialog;
}


class logindialog : public QDialog
{
    Q_OBJECT

public:
    explicit logindialog(QWidget *parent = 0);
     ~logindialog();
    QString getuser();
    QString getpsw();
    QSqlDatabase getdb();
    void initview();

private slots:
    void on_login_clicked();


    void on_userlist_currentIndexChanged(const QString &arg1);


    void on_delay_clicked();

private:
    QString user;
    QString psw;
    QString pswfile ="userinfo.dat";
    Ui::logindialog *ui;
    QDataStream *useinfo;
    QHash <QString,QString> userinfolist;
    QSqlDatabase db;
    //MainWindow mainw;
};

#endif // LOGINDIALOG_H
