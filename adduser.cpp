#include "adduser.h"
#include "ui_adduser.h"
#include <QMessageBox>

addUser::addUser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addUser)
{
    ui->setupUi(this);
}

void addUser::setDb(QSqlDatabase db)
{
    this->db = db;
}

void addUser::initview()
{
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear(); //清空密码
    ui->lineEdit->setFocus();//将光标转到用户名输入框
}

addUser::~addUser()
{
    delete ui;
}

void addUser::on_pushButton_clicked()
{
    user = ui->lineEdit->text();
    psw = ui->lineEdit_2->text();
    Repsw = ui->lineEdit_3->text();
    if(user.isEmpty())
    {
        QMessageBox::information(this, "警告", "有户名不能为空",QMessageBox::Yes);
        initview();
        return;
    }
    if(psw.isEmpty()|Repsw.isEmpty())
    {
        QMessageBox::information(this, "警告", "密码不能为空");
        initview();
        return;
    }
    if(psw != Repsw)
    {
        QMessageBox::information(this, "警告", "两次密码不匹配，重新输入！");
        initview();
        return;
    }
    QSqlQuery query(db);
    qDebug()<<db;
    if (db.open()) qDebug()<<"open db success!";
    else qDebug()<<"cannot open";
    QString sqlquery;
    sqlquery = QObject::tr("create login %1 with password='%2',default_database=WageManager;"
                           "create user %1 for login %1 with default_schema=dbo;"
                           "grant select on 员工表 to %1;"
                           "grant select on 考勤表 to %1;"
                           "grant select on 加班表 to %1;"
                           "grant select on 工资表 to %1;"
                           )
            .arg(user,psw);
    qDebug()<<sqlquery;
    int i= query.exec(sqlquery);
    if(!i) {
        QMessageBox::information(this, "警告", "用户创建失败");
        qDebug()<<query.lastError();
    }
    else {QMessageBox::information(this, "恭喜", "用户创建成功!");}
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
}

void addUser::on_pushButton_2_clicked()
{
    this->close();
}
