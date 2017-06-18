#include "insert.h"
#include "ui_insert.h"
#include <QtGui>
#include <QDate>


insert::insert(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::insert)
{
    ui->setupUi(this);
}

void insert::setDb(QSqlDatabase db)
{
    this->db=db;
}

insert::~insert()
{
    delete ui;
}



void insert::on_toolBox_currentChanged(int index)
{
    ui->stackedWidget->setCurrentIndex(index);
}



void insert::on_pushButton_clicked()
{

    QSqlQuery query(db);
    qDebug()<<db;
    if (db.open()) qDebug()<<"open db success!";
    else qDebug()<<"cannot open";
    int index = ui->stackedWidget->currentIndex();
    QString sqlquery;   //sql语句
    switch (index) {
    case 0:{
        variable1 = ui->lineEdit->text();
        variable2 = ui->lineEdit_2->text();
        if(variable1.isEmpty())
        {
            QMessageBox::information(this, "警告", "员工编号不能为空",QMessageBox::Yes);
            ui->lineEdit->setFocus();
            return;
        }
        sqlquery = QObject::tr("insert into 员工表 values ('%1','%2','%3','%4','%5');"
                               "create login %2 with password='123456',default_database=WageManager;"
                               "create user %2 for login %2 with default_schema=dbo;"
                               "grant select on 员工表 to %2;"
                               "grant select on 考勤表 to %2;"
                               "grant select on 加班表 to %2;"
                               "grant select on 工资表 to %2;").arg(variable1,variable2,Sex,variableP,variableD);
        int i= query.exec(sqlquery);
        if(!i) {
            QMessageBox::information(this, "警告", "插入失败");
            qDebug()<<query.lastError();
        }
        else {
            QMessageBox::information(this, "恭喜", "插入成功!");
        }
        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
        break;
        }
    case 1:{
        variable1 = ui->lineEdit_6->text();
        variable2 = ui->lineEdit_7->text();
        variable3 = ui->lineEdit_8->text();
        if(variable1.isEmpty())
        {
            QMessageBox::information(this, "警告", "部门编号不能为空",QMessageBox::Yes);
            ui->lineEdit_6->setFocus();
            return;
        }
        sqlquery = QObject::tr("insert into 部门表 values ('%1','%2','%3')").arg(variable1,variable2,variable3);
        qDebug()<<sqlquery;
        int i= query.exec(sqlquery);
        if(!i) {
            QMessageBox::information(this, "警告", "插入失败");
            qDebug()<<query.lastError();
        }
        else {QMessageBox::information(this, "恭喜", "插入成功!");}
        ui->lineEdit_6->clear();
        ui->lineEdit_7->clear();
        ui->lineEdit_8->clear();
        ui->lineEdit_6->setFocus();
        break;
    }//end of case 1
    case 2:{
        variable1 = ui->lineEdit_9->text();
        variable2 = ui->lineEdit_10->text();
        variable3 = ui->lineEdit_11->text();
        if(variable1.isEmpty())
        {
            QMessageBox::information(this, "警告", "工种编号不能为空",QMessageBox::Yes);
            ui->lineEdit_9->setFocus();
            return;
        }
        sqlquery = QObject::tr("insert into 工种表 values ('%1','%2',%3)").arg(variable1,variable2,variable3);
        qDebug()<<sqlquery;
        int i= query.exec(sqlquery);
        if(!i) {
            QMessageBox::information(this, "警告", "插入失败");
            qDebug()<<query.lastError();
        }
        else {QMessageBox::information(this, "恭喜", "插入成功!");}
        ui->lineEdit_9->clear();
        ui->lineEdit_10->clear();
        ui->lineEdit_11->clear();
        ui->lineEdit_9->setFocus();
        break;
    }
    case 3:{
        variable1 = ui->lineEdit_12->text();
        variable2 = ui->dateEdit->text();
        variable3 = ui->lineEdit_14->text();
        if(variable1.isEmpty())
        {
            QMessageBox::information(this, "警告", "员工编号不能为空",QMessageBox::Yes);
            ui->lineEdit_12->setFocus();
            return;
        }
        sqlquery = QObject::tr("insert into 考勤表 values ('%1','%2',%3)").arg(variable1,variable2,variable3);
        qDebug()<<sqlquery;
        int i= query.exec(sqlquery);
        if(!i) {
            QMessageBox::information(this, "警告", "插入失败");
            qDebug()<<query.lastError();
        }
        else {QMessageBox::information(this, "恭喜", "插入成功!");}
        ui->lineEdit_14->clear();
        break;
    }
    case 4:{
        variable1 = ui->lineEdit_15->text();
        variable2 = ui->dateEdit_2->text();
        if(variable1.isEmpty()){
            QMessageBox::information(this, "警告", "员工编号不能为空",QMessageBox::Yes);
            ui->lineEdit_15->setFocus();
            return;
        }
        if (OverType == 1){
            sqlquery = QObject::tr("insert into 加班表(员工编号,加班时间,加班类别) values ('%1','%2',1)").arg(variable1,variable2);
        }
        else if (OverType ==2){
            sqlquery = QObject::tr("insert into 加班表(员工编号,加班时间,加班类别) values ('%1','%2',2)").arg(variable1,variable2);
        }
        else{
            sqlquery = QObject::tr("insert into 加班表(员工编号,加班时间,加班类别) values ('%1','%2',3)").arg(variable1,variable2);
        }
        qDebug()<<sqlquery;
        int i= query.exec(sqlquery);
        if(!i) {
            QMessageBox::information(this, "警告", "插入失败");
            qDebug()<<query.lastError();
        }
        else {QMessageBox::information(this, "恭喜", "插入成功!");}
        //ui->lineEdit_15->clear();
        break;
    }
    }//end of switch
}

void insert::on_pushButton_2_clicked()
{
    this->close();
}



void insert::on_radioButton_clicked()//男
{
    ui->radioButton_2->setChecked(false);
    Sex = "男";
}

void insert::on_radioButton_2_clicked()
{
    ui->radioButton->setChecked(false);
    Sex = "女";
}

void insert::on_comboBox_currentIndexChanged(int index)
{
    if(index == 0){
        variableP = "P1";
    }
    else if (index == 1){
        variableP = "P2";
    }
    else{
        variableP = "P3";
    }
}

void insert::on_comboBox_2_currentIndexChanged(int index)
{

    if(index == 0){
        variableD = "D1";
    }
    else if (index ==1){
        variableD = "D2";
    }
    else if (index ==2){
        variableD = "D3";
    }
    else if (index ==3){
        variableD = "D4";
    }
}

void insert::on_radioButton_3_clicked()
{
    OverType = 1;
}

void insert::on_radioButton_4_clicked()
{
    OverType = 2;
}

void insert::on_radioButton_5_clicked()
{
    OverType = 3;
}


