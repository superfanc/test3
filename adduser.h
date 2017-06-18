#ifndef ADDUSER_H
#define ADDUSER_H

#include <QDialog>
#include <QDataStream>
#include <QSqlDatabase>
#include <QtSql>
#include <QDebug>
#include <QMessageBox>

namespace Ui {
class addUser;
}

class addUser : public QDialog
{
    Q_OBJECT

public:
    explicit addUser(QWidget *parent = 0);
    void setDb(QSqlDatabase db);
    void initview();
    ~addUser();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::addUser *ui;
    QSqlDatabase db;
    QString user;
    QString psw;
    QString Repsw;
};

#endif // ADDUSER_H
