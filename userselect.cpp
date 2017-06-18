#include "userselect.h"
#include "ui_userselect.h"

userselect::userselect(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::userselect)
{
    ui->setupUi(this);
}

void userselect::setUser(QString user)
{
    this->user = user;
}

userselect::~userselect()
{
    delete ui;
}

void userselect::on_pushButton_2_clicked()//基本信息
{
    QSqlQueryModel *model = new QSqlQueryModel;
    QString sqlquery;
    sqlquery = QObject::tr("select * from 员工表 where 员工姓名 = '%1'").arg(user);
    model->setQuery(sqlquery);
    qDebug()<<sqlquery;
    ui->tableView->setModel(model);
    ui->tableView->setAlternatingRowColors(true);
}

void userselect::on_pushButton_3_clicked()//考勤
{
    QSqlQueryModel *model = new QSqlQueryModel;
    QString sqlquery;
    sqlquery = QObject::tr("select 员工姓名,考勤时间,出勤次数 from 考勤表,员工表 "
                           "where 考勤表.员工编号 = 员工表.员工编号  and 员工表.员工姓名 = '%1'").arg(user);
    model->setQuery(sqlquery);
    qDebug()<<sqlquery;
    ui->tableView->setModel(model);
    ui->tableView->setAlternatingRowColors(true);
}

void userselect::on_pushButton_4_clicked()//加班
{
    QSqlQueryModel *model = new QSqlQueryModel;
    QString sqlquery;
    sqlquery = QObject::tr("select 员工姓名,加班时间,加班类别,加班奖金 from 加班表,员工表 "
                           "where 加班表.员工编号 = 员工表.员工编号  and 员工表.员工姓名 = '%1'").arg(user);
    model->setQuery(sqlquery);
    qDebug()<<sqlquery;
    ui->tableView->setModel(model);
    ui->tableView->setAlternatingRowColors(true);
}

void userselect::on_pushButton_5_clicked()//工资
{
    QSqlQueryModel *model = new QSqlQueryModel;
    QString sqlquery;
    sqlquery = QObject::tr("select 员工姓名,结算时间,基本工资,缺勤扣工资,加班津贴,本月工资 "
                           "from 工资表,员工表 "
                           "where 工资表.员工编号 = 员工表.员工编号  and 员工表.员工姓名 = '%1'").arg(user);
    model->setQuery(sqlquery);
    qDebug()<<sqlquery;
    ui->tableView->setModel(model);
    ui->tableView->setAlternatingRowColors(true);
}

void userselect::on_pushButton_clicked()
{
    this->close();
}
