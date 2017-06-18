#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "insert.h"
#include "qselect.h"
#include "qupdate.h"
#include "qtdelete.h"
#include "adduser.h"
#include "userselect.h"
//#include "userpsw.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void setUser(QString user);
    void showUser(QString user);
    QString getuser();
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_5_clicked();

    void on_select_clicked();

    void on_update_clicked();

    void on_delete_2_clicked();


    void on_help_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    insert Insert;
    Qupdate Update;
    qselect Select;
    Qtdelete Delete;
    //userpsw UserPsw;
    QSqlDatabase db;
    QString user;
    addUser AddUser;
    userselect UserSele;
    QFile qss;
    int index;//切换主题

};

#endif // MAINWINDOW_H
