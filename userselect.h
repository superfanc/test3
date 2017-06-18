#ifndef USERSELECT_H
#define USERSELECT_H

#include <QDialog>
#include <QDataStream>
#include <QSqlDatabase>
#include <QtSql>
#include <QDebug>
#include <QMessageBox>

namespace Ui {
class userselect;
}

class userselect : public QDialog
{
    Q_OBJECT

public:
    explicit userselect(QWidget *parent = 0);
    void setUser(QString user);
    ~userselect();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_clicked();

private:
    Ui::userselect *ui;
    QString user;
};

#endif // USERSELECT_H
