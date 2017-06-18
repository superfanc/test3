#ifndef QSELECT_H
#define QSELECT_H

#include <QDialog>
#include <QDataStream>
#include <QSqlDatabase>
#include <QtSql>
#include <QDebug>
#include <QMessageBox>

namespace Ui {
class qselect;
}

class qselect : public QDialog
{
    Q_OBJECT

public:
    explicit qselect(QWidget *parent = 0);
    ~qselect();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_8_clicked();

private:
    Ui::qselect *ui;
    QSqlDatabase db;
    QString SelectKey;
};

#endif // QSELECT_H
