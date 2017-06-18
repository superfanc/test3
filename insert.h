#ifndef INSERT_H
#define INSERT_H

#include <QDialog>
#include <QDataStream>
#include <QSqlDatabase>
#include <QtSql>
#include <QDebug>
#include <QMessageBox>

namespace Ui {
class insert;
}

class insert : public QDialog
{
    Q_OBJECT

public:
    explicit insert(QWidget *parent = 0);
    void setDb(QSqlDatabase db);
    ~insert();

private slots:


    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_toolBox_currentChanged(int index);

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_comboBox_2_currentIndexChanged(int index);

    void on_radioButton_3_clicked();

    void on_radioButton_4_clicked();

    void on_radioButton_5_clicked();

private:
    Ui::insert *ui;
    QSqlDatabase db;
    QString variable1;
    QString variable2;
    QString variable3;
    QString variable4;
    QString variable5;
    QString Sex;
    QString variableD = "D1";
    QString variableP = "P1";
    int OverType = 1;  //加班编号，默认为1
    QString InsertDate;
};

#endif // INSERT_H
