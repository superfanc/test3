#include "qupdate.h"
#include "ui_qupdate.h"

Qupdate::Qupdate(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Qupdate)
{
    ui->setupUi(this);
}

void Qupdate::setDb(QSqlDatabase db)
{
    this->db=db;
}

Qupdate::~Qupdate()
{
    delete ui;
}

void Qupdate::on_comboBox_currentIndexChanged(int index)
{
    ui->stackedWidget->setCurrentIndex(index);
}


void Qupdate::on_pushButton_clicked()
{
    QSqlQuery query(db);
    qDebug()<<db;
    if (db.open()) qDebug()<<"open db success!";
    else qDebug()<<"cannot open";
    int index = ui->comboBox->currentIndex();
    QString sqlquery;   //sql语句
    switch (index) {
    case 0:{
       variable1 = ui->lineEdit->text();
       variable2 = ui->lineEdit_2->text();
       sqlquery = QObject::tr("update 部门表 set 部门经理 = '%1' where 部门编号 = '%2'").arg(variable2,variable1);
       int i= query.exec(sqlquery);
       if(!i) {
           QMessageBox::information(this, "警告", "修改失败");
           qDebug()<<query.lastError();
       }
       else {QMessageBox::information(this, "恭喜", "修改成功!");}
       ui->lineEdit->clear();
       ui->lineEdit_2->clear();
       break;
        }
   case 1:{
        variable1 = ui->lineEdit_3->text();
        variable2 = ui->lineEdit_4->text();
        sqlquery = QObject::tr("update 工种表 set 基本工资 = '%1' where 工种编号 = '%2'").arg(variable2,variable1);
        int i= query.exec(sqlquery);
        if(!i) {
            QMessageBox::information(this, "警告", "修改失败");
            qDebug()<<query.lastError();
        }
        else {QMessageBox::information(this, "恭喜", "修改成功!");}
        ui->lineEdit_3->clear();
        ui->lineEdit_4->clear();
        break;
    }//end of case 1
    case 2:{
        variable1 = ui->lineEdit_5->text();
        variable2 = ui->lineEdit_6->text();
        sqlquery = QObject::tr("update 员工表 set 工种编号 = '%1' where 员工编号 = '%2'").arg(variable2,variable1);
        qDebug()<<sqlquery;
        int i= query.exec(sqlquery);
        if(!i) {
            QMessageBox::information(this, "警告", "修改失败");
            qDebug()<<query.lastError();
        }
        else {QMessageBox::information(this, "恭喜", "修改成功!");}
        ui->lineEdit_5->clear();
        ui->lineEdit_6->clear();
        break;
    }
    case 3:{
        variable1 = ui->lineEdit_8->text();
        variable2 = ui->lineEdit_9->text();
        variable3 = ui->lineEdit_10->text();
        sqlquery = QObject::tr("update 考勤表 set 出勤次数 = '%1' where 员工编号 = '%2' and 考勤时间 = '%3'").arg(variable3,variable1,variable2);
        qDebug()<<sqlquery;
        int i= query.exec(sqlquery);
        if(!i) {
            QMessageBox::information(this, "警告", "修改失败");
            qDebug()<<query.lastError();
        }
        else {QMessageBox::information(this, "恭喜", "修改成功!");}
        ui->lineEdit_8->clear();
        ui->lineEdit_9->clear();
        ui->lineEdit_10->clear();
        break;
    }
    case 4:{
        variable1 = ui->lineEdit_11->text();
        variable2 = ui->lineEdit_12->text();
        variable3 = ui->lineEdit_13->text();
        sqlquery = QObject::tr("update 加班表 set 加班类别 = '%1' where 员工编号 = '%2' and 加班时间 = '%3'").arg(variable3,variable1,variable2);
        qDebug()<<sqlquery;
        int i= query.exec(sqlquery);
        if(!i) {
            QMessageBox::information(this, "警告", "修改失败");
            qDebug()<<query.lastError();
        }
        else {QMessageBox::information(this, "恭喜", "修改成功!");}
        ui->lineEdit_11->clear();
        ui->lineEdit_12->clear();
        ui->lineEdit_13->clear();
        break;
    }
    }//end of switch

}

void Qupdate::on_pushButton_2_clicked()
{
    this->close();
}
