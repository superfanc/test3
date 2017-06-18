#include "qtdelete.h"
#include "ui_qtdelete.h"
#include <QtGui>

Qtdelete::Qtdelete(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Qtdelete)
{
    ui->setupUi(this);
}

void Qtdelete::setDb(QSqlDatabase db)
{
    this->db = db;
}

Qtdelete::~Qtdelete()
{
    delete ui;
}

void Qtdelete::on_toolBox_currentChanged(int index)
{
    ui->stackedWidget->setCurrentIndex(index);
}


void Qtdelete::on_pushButton_clicked()
{
    this->close();
}

void Qtdelete::on_pushButton_2_clicked()
{
    QSqlQuery query(db);
    if (db.open()) qDebug()<<"open db success!";
    else qDebug()<<"cannot open";
    int index = ui->stackedWidget->currentIndex();
    QString sqlquery;   //sql语句
    switch (index){
    case 0:{
        variable1 = ui->lineEdit->text();
        sqlquery = QObject::tr("delete from 部门表 where 部门编号 = '%1'").arg(variable1);
        qDebug()<<sqlquery;
        int i= query.exec(sqlquery);
        if(!i) {
            QMessageBox::information(this, "警告", "删除失败");
            qDebug()<<query.lastError();
        }
        else {QMessageBox::information(this, "恭喜", "删除成功!");}
        ui->lineEdit->clear();
        break;
    }
    case 1:{
        variable1 = ui->lineEdit_2->text();
        sqlquery = QObject::tr("delete from 工种表 where 工种编号 = '%1'").arg(variable1);
        qDebug()<<sqlquery;
        int i= query.exec(sqlquery);
        if(!i) {
            QMessageBox::information(this, "警告", "删除失败");
            qDebug()<<query.lastError();
        }
        else {QMessageBox::information(this, "恭喜", "删除成功!");}
        ui->lineEdit_2->clear();
        break;
    }
    case 2:{
        variable1 = ui->lineEdit_3->text();
        sqlquery = QObject::tr("delete from 员工表 where 员工编号 = '%1'"
                               "drop login %1;"
                               "drop user %1;").arg(variable1);
        qDebug()<<sqlquery;
        int i= query.exec(sqlquery);
        if(!i) {
            QMessageBox::information(this, "警告", "删除失败");
            qDebug()<<query.lastError();
        }
        else {QMessageBox::information(this, "恭喜", "删除成功!");}
        ui->lineEdit_3->clear();
        break;
    }
    case 3:{
        variable1 = ui->lineEdit_4->text();
        variable2 = ui->dateEdit->text();
        sqlquery = QObject::tr("delete from 考勤表 where 员工编号 = '%1' and 考勤时间 = '%2'").arg(variable1,variable2);
        qDebug()<<sqlquery;
        int i= query.exec(sqlquery);
        if(!i) {
            QMessageBox::information(this, "警告", "删除失败");
            qDebug()<<query.lastError();
        }
        else {QMessageBox::information(this, "恭喜", "删除成功!");}
        ui->lineEdit_4->clear();
        break;
    }
    case 4:{
        variable1 = ui->lineEdit_6->text();
        variable2 = ui->dateEdit_2->text();
        sqlquery = QObject::tr("delete from 加班表 where 员工编号 = '%1' and 加班时间 = '%2'").arg(variable1,variable2);
        qDebug()<<sqlquery;
        int i= query.exec(sqlquery);
        if(!i) {
            QMessageBox::information(this, "警告", "删除失败");
            qDebug()<<query.lastError();
        }
        else {QMessageBox::information(this, "恭喜", "删除成功!");}
        ui->lineEdit_6->clear();
        break;
    }
    }//end of switch
}
