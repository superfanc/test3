#ifndef USERPSW_H
#define USERPSW_H

#include <QDialog>
#include <QDataStream>
#include <QSqlDatabase>
#include <QtSql>
#include <QDebug>
#include <QMessageBox>

namespace Ui {
class userpsw;
}

class userpsw : public QDialog
{
    Q_OBJECT

public:
    explicit userpsw(QWidget *parent = 0);
    void setUser(QString user);
    void setDb(QSqlDatabase db);
    ~userpsw();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::userpsw *ui;
    QString user;
    QSqlDatabase db;
};

#endif // USERPSW_H
