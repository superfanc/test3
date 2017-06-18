#include "select.h"
#include "ui_select.h"
#include <QtGui>
qselect::qselect(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::select)
{
    ui->setupUi(this);
}

void qselect::setDb(QSqlDatabase db)
{
    this->db=db;
}





qselect::~qselect()
{
    delete ui;
}




void qselect::on_pushButton_8_clicked()
{
    this->close();
}

void qselect::on_pushButton_clicked() //部门表
{
    SelectKey = ui->lineEdit->text();
    QSqlQueryModel *model = new QSqlQueryModel;
    QString sqlquery;
    if(SelectKey.isEmpty()){
        sqlquery = QObject::tr("select * from 部门表");}
    else{
        sqlquery = QObject::tr("select * from 部门表 where 部门编号 = '%1'").arg(SelectKey);
        ui->lineEdit->clear();
    }
    model->setQuery(sqlquery);
    qDebug()<<sqlquery;
    ui->tableView->setModel(model);
    ui->tableView->setAlternatingRowColors(true);//隔行变色
    int row_count = model->rowCount();
    for(int i =0; i < row_count; i++){
         ui->tableView->setRowHeight(i, 20);
    }
}


void qselect::on_pushButton_2_clicked()//工种表
{
    SelectKey = ui->lineEdit_2->text();
    QSqlQueryModel *model = new QSqlQueryModel;
    QString sqlquery;
    if(SelectKey.isEmpty()){
        sqlquery = QObject::tr("select * from 工种表");}
    else{
        sqlquery = QObject::tr("select * from 工种表 where 工种编号 = '%1'").arg(SelectKey);
        ui->lineEdit->clear();
    }
    model->setQuery(sqlquery);
    qDebug()<<sqlquery;
    ui->tableView->setModel(model);
    ui->tableView->setAlternatingRowColors(true);//隔行变色
    int row_count = model->rowCount();
    for(int i =0; i < row_count; i++){
         ui->tableView->setRowHeight(i, 20);}
}

void qselect::on_pushButton_3_clicked()//员工表
{
    SelectKey = ui->lineEdit_3->text();
    QSqlQueryModel *model = new QSqlQueryModel;
    QString sqlquery;
    if(SelectKey.isEmpty()){
        sqlquery = QObject::tr("select * from 员工表");}
    else{
        sqlquery = QObject::tr("select * from 员工表 where 员工编号 = '%1'").arg(SelectKey);
        ui->lineEdit_3->clear();
    }
    model->setQuery(sqlquery);
    qDebug()<<sqlquery;
    ui->tableView->setModel(model);
    ui->tableView->setAlternatingRowColors(true);//隔行变色
    int row_count = model->rowCount();
    for(int i =0; i < row_count; i++){
        ui->tableView->setRowHeight(i, 20);}
}

void qselect::on_pushButton_4_clicked()//考勤表
{
    SelectKey = ui->lineEdit_4->text();
    QSqlQueryModel *model = new QSqlQueryModel;
    QString sqlquery;
    if(SelectKey.isEmpty()){
        sqlquery = QObject::tr("select * from 考勤表");}
    else{
        sqlquery = QObject::tr("select * from 考勤表 where 员工编号 = '%1'").arg(SelectKey);
        ui->lineEdit_4->clear();
    }
    model->setQuery(sqlquery);
    qDebug()<<sqlquery;
    ui->tableView->setModel(model);
    ui->tableView->setAlternatingRowColors(true);//隔行变色
    int row_count = model->rowCount();
    for(int i =0; i < row_count; i++){
         ui->tableView->setRowHeight(i, 20);}

}

void qselect::on_pushButton_5_clicked()//加班表
{
    SelectKey = ui->lineEdit_5->text();
    QSqlQueryModel *model = new QSqlQueryModel;
    QString sqlquery;
    if(SelectKey.isEmpty()){
        sqlquery = QObject::tr("select * from 加班表");}
    else{
        sqlquery = QObject::tr("select * from 加班表 where 员工编号 = '%1'").arg(SelectKey);
        ui->lineEdit_5->clear();
    }
    model->setQuery(sqlquery);
    qDebug()<<sqlquery;
    ui->tableView->setModel(model);
    ui->tableView->setAlternatingRowColors(true);//隔行变色
    int row_count = model->rowCount();
    for(int i =0; i < row_count; i++){
         ui->tableView->setRowHeight(i, 20);}
}

void qselect::on_pushButton_6_clicked()//月工资表
{
     this->close();
}


void qselect::on_pushButton_7_clicked() //年终奖
{
    this->close();
}



void qselect::on_pushButton_9_clicked()  //企业工资查询
{
    this->close();
}
