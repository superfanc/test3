#ifndef QTDELETE_H
#define QTDELETE_H

#include <QDialog>
#include <QDataStream>
#include <QSqlDatabase>
#include <QtSql>
#include <QDebug>
#include <QMessageBox>

namespace Ui {
class Qtdelete;
}

class Qtdelete : public QDialog
{
    Q_OBJECT

public:
    explicit Qtdelete(QWidget *parent = 0);
    void setDb(QSqlDatabase db);
    ~Qtdelete();

private slots:
    void on_toolBox_currentChanged(int index);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Qtdelete *ui;
    QSqlDatabase db;
    QString variable1;
    QString variable2;
    QString variable3;
};

#endif // QTDELETE_H
