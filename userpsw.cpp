#include "userpsw.h"
#include "ui_userpsw.h"


userpsw::userpsw(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::userpsw)
{
    ui->setupUi(this);
}

void userpsw::setUser(QString user)
{
    this->user = user;
}

void userpsw::setDb(QSqlDatabase db)
{
    this->db = db;
}

userpsw::~userpsw()
{
    delete ui;
}

void userpsw::on_pushButton_clicked()
{
    QSqlQuery query(db);
    qDebug()<<db;
    if (db.open()) qDebug()<<"open db success!";
    else qDebug()<<"cannot open";
    QString sqlquery;
    QString Oldpsw = ui->lineEdit_3->text();
    QString Newpsw = ui->lineEdit->text();
    QString Repsw = ui->lineEdit_2->text();
    if(Oldpsw.isEmpty()|Newpsw.isEmpty()|Repsw.isEmpty())
    {
        QMessageBox::information(this, "警告", "密码不能为空");
        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
        ui->lineEdit_3->clear();
        return;
    }
    if(Repsw != Newpsw)
    {
        QMessageBox::information(this, "警告", "两次密码不匹配，重新输入！");
        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
        ui->lineEdit_3->clear();
        return;
    }
    sqlquery = QObject::tr("alter login %1 with password='%2' old_password='%3'").arg(user,Newpsw,Oldpsw);
    int i= query.exec(sqlquery);
    if(!i) {
        QMessageBox::information(this, "警告", "修改失败");
        qDebug()<<query.lastError();
    }
    else {
        QMessageBox::information(this, "恭喜", "修改成功!");
    }
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
}

void userpsw::on_pushButton_2_clicked()
{
    this->close();
}
