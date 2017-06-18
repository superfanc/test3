#include "qselect.h"
#include "ui_qselect.h"

qselect::qselect(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::qselect)
{
    ui->setupUi(this);
}

qselect::~qselect()
{
    delete ui;
}

void qselect::on_pushButton_clicked()
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
}

void qselect::on_pushButton_2_clicked()
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
    ui->tableView->setAlternatingRowColors(true);
}

void qselect::on_pushButton_3_clicked()
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
    ui->tableView->setAlternatingRowColors(true);
}

void qselect::on_pushButton_4_clicked()
{
    SelectKey = ui->lineEdit_4->text();
    QSqlQueryModel *model = new QSqlQueryModel;
    QString sqlquery;
    if(SelectKey.isEmpty()){
        sqlquery = QObject::tr("select * from 考勤表");}
    else{
        sqlquery = QObject::tr("select * from 考勤表 where 员工编号 = '%1'").arg(SelectKey);
        //ui->lineEdit_4->clear();
    }
    model->setQuery(sqlquery);
    qDebug()<<sqlquery;
    ui->tableView->setModel(model);
    ui->tableView->setAlternatingRowColors(true);
}

void qselect::on_pushButton_5_clicked()
{
    SelectKey = ui->lineEdit_5->text();
    QSqlQueryModel *model = new QSqlQueryModel;
    QString sqlquery;
    if(SelectKey.isEmpty()){
        sqlquery = QObject::tr("select * from 加班表");}
    else{
        sqlquery = QObject::tr("select * from 加班表 where 员工编号 = '%1'").arg(SelectKey);
        //ui->lineEdit_5->clear();
    }
    model->setQuery(sqlquery);
    qDebug()<<sqlquery;
    ui->tableView->setModel(model);
    ui->tableView->setAlternatingRowColors(true);
}

void qselect::on_pushButton_6_clicked()//月工资
{
    SelectKey = ui->lineEdit_6->text();
    QSqlQueryModel *model = new QSqlQueryModel;
    QString sqlquery;
    if(SelectKey.isEmpty()){
        sqlquery = QObject::tr("select * from 工资表");}
    else{
        sqlquery = QObject::tr("select * from 工资表 where 员工编号 = '%1'").arg(SelectKey);
        //ui->lineEdit_6->clear();
    }
    model->setQuery(sqlquery);
    qDebug()<<sqlquery;
    ui->tableView->setModel(model);
    ui->tableView->setAlternatingRowColors(true);
}

void qselect::on_pushButton_7_clicked()//年终奖
{
    SelectKey = ui->lineEdit_7->text();
    QString SelectYear = ui->lineEdit_9->text();
    QSqlQueryModel *model = new QSqlQueryModel;
    QString sqlquery;
    if(SelectKey.isEmpty()){
        sqlquery = QObject::tr("select b.员工编号,(sum(b.本月工资)/12) as '年终奖金' "
                               "from 员工表 as a , 工资表 as b "
                               "where a.员工编号 = b.员工编号 "
                               "group by b.员工编号");}
    else{
        if(SelectYear.isEmpty()){
            QMessageBox::information(this, "警告", "年份不能为空",QMessageBox::Yes);
            ui->lineEdit_9->setFocus();
            return;
        }
        sqlquery = QObject::tr("select b.员工编号,(sum(b.本月工资)/12) as '年终奖金' "
                               "from 员工表 as a , 工资表 as b "
                               "where a.员工编号 = b.员工编号 and a.员工编号 = '%1' "
                               "and (datediff(year,b.结算时间,'%2-12-31')=0) "
                               "group by b.员工编号").arg(SelectKey,SelectYear);
        ui->lineEdit_7->clear();
        ui->lineEdit_9->clear();
    }

    model->setQuery(sqlquery);
    qDebug()<<sqlquery;
    ui->tableView->setModel(model);
    ui->tableView->setAlternatingRowColors(true);
}

void qselect::on_pushButton_9_clicked()//企业工资
{
    SelectKey = ui->lineEdit_8->text();
    QString SelectYear = ui->lineEdit_10->text();
    QSqlQueryModel *model = new QSqlQueryModel;
    QString sqlquery;
    if(SelectKey.isEmpty()){
        sqlquery = QObject::tr("select a.部门编号,sum(b.本月工资) as '部门工资' "
                               "from 部门表 as a , 工资表 as b ,员工表 as c "
                               "where a.部门编号 = c.部门编号 and c.员工编号 = b.员工编号 "
                               "group by a.部门编号");
    }
    else{
        if(SelectYear.isEmpty()){
            QMessageBox::information(this, "警告", "年份不能为空",QMessageBox::Yes);
            ui->lineEdit_10->setFocus();
            return;
        }
        sqlquery = QObject::tr("select a.部门编号,sum(b.本月工资) as '部门工资' "
                               "from 部门表 as a , 工资表 as b ,员工表 as c "
                               "where a.部门编号 = c.部门编号 and c.员工编号 = b.员工编号 and a.部门编号 = '%1' "
                               "and (datediff(year,b.结算时间,'%2-12-31')=0) "
                               "group by a.部门编号").arg(SelectKey,SelectYear);
        ui->lineEdit_8->clear();
        ui->lineEdit_10->clear();
    }
    model->setQuery(sqlquery);
    qDebug()<<sqlquery;
    ui->tableView->setModel(model);
    ui->tableView->setAlternatingRowColors(true);
}

void qselect::on_pushButton_8_clicked()
{
    this->close();
}
