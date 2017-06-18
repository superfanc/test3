#include "logindialog.h"
#include "ui_logindialog.h"
#include <QMessageBox>


logindialog::logindialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::logindialog)
{
    ui->setupUi(this);
    QFile fin(pswfile);
    if(!fin.open(QIODevice::ReadOnly))
    {
         qDebug()<<"cann't open file";
    }
    else{
        QDataStream in(&fin);
        in>>userinfolist;
        QHash<QString, QString>::const_iterator it;
        for(it =userinfolist.constBegin();it!=userinfolist.constEnd();it++){
            ui->userlist->addItem(it.key());
        }
        ui->userlist->setCurrentIndex(0);
        user =ui->userlist->currentText();
        qDebug()<<"3"<<user;
        psw =userinfolist.value(user);
        ui->pswedit->setText(psw);
        if(!psw.isEmpty())
            ui->savepsw->setChecked(true);
        else
            ui->savepsw->setChecked(false);
    }
}


logindialog::~logindialog()
{
    delete ui;
}

QString logindialog::getuser()
{
   return user;
}
QString logindialog::getpsw()
{
    return psw;
}

QSqlDatabase logindialog::getdb()
{
    return db;
}

void logindialog::initview()
{
    ui->pswedit->clear();//清空密码输入框
    ui->userlist->setFocus();//将光标转到用户名输入框
}

void logindialog::on_login_clicked()
{
    user =ui->userlist->currentText();
    qDebug()<<"1"<<user;
    psw =ui->pswedit->text();
    if(user.isEmpty())
    {
        QMessageBox::information(this, "警告", "有户名不能为空",QMessageBox::Yes);
        initview();
        return;
    }
    if(psw.isEmpty())
    {
        QMessageBox::information(this, "警告", "密码不能为空");
        return;
    }
    db=QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName(QString("DRIVER={SQL SERVER};"
                               "SERVER=%1;" //服务器名称
                               "DATABASE=%2;"//数据库名
                               "UID=%3;"           //登录名
                               "PWD=%4;"        //密码
                               ).arg(".")
                       .arg("WageManager")
                       .arg(user)
                       .arg(psw)
                       );
    qDebug()<<"1db="<<db;
    if (!db.open())
    {
        qDebug()<<"cannot open!";
        QMessageBox::critical(0, qApp->tr("Cannot open database"),
                              db.lastError().databaseText(), QMessageBox::Cancel);
        return;

    }
    if(ui->savepsw->checkState())
    {
        userinfolist.insert(user,psw);
    }
    else
    {
        userinfolist.insert(user,"");
    }
    QFile fout(pswfile);
    if(!fout.open(QIODevice::WriteOnly))
    {
         qDebug()<<"cann't open file";
    }
    else{
        QDataStream out(&fout);
        userinfolist.insert(user,psw);
        out<<userinfolist;
    }
     accept();
}



void logindialog::on_userlist_currentIndexChanged(const QString &arg1)
{
    psw =userinfolist.value(arg1);
    ui->pswedit->setText(psw);
    if(psw.isEmpty())
    {
        ui->savepsw->setChecked(false);
    }
    else
    {
        ui->savepsw->setChecked(true);
    }
}


void logindialog::on_delay_clicked()
{
    exit(-1);
}
