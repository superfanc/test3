#ifndef QUPDATE_H
#define QUPDATE_H

#include <QDialog>
#include <QDataStream>
#include <QSqlDatabase>
#include <QtSql>
#include <QDebug>
#include <QMessageBox>

namespace Ui {
class Qupdate;
}

class Qupdate : public QDialog
{
    Q_OBJECT

public:
    explicit Qupdate(QWidget *parent = 0);
    void setDb(QSqlDatabase db);
    ~Qupdate();

private slots:
    void on_comboBox_currentIndexChanged(int index);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Qupdate *ui;
    QSqlDatabase db;
    QString variable1;
    QString variable2;
    QString variable3;
};

#endif // QUPDATE_H
