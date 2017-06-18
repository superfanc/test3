#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "logindialog.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
    {
    ui->setupUi(this);
    logindialog *dlg = new logindialog();
    QFile qss(":/qss/blue.css");
    qss.open(QFile::ReadOnly);
    dlg->setStyleSheet(qss.readAll());
    qss.close();
    if(dlg->exec() ==QDialog::Accepted){
        dlg->close();
    }
    else exit(-1);
    setUser(dlg->getuser());
    showUser(user);
    UserSele.setUser(user);
    //UserPsw.setUser(user);
    db=dlg->getdb();
}

void MainWindow::setUser(QString user)
{
    this->user = user;
}

void MainWindow::showUser(QString user)
{
    ui->label_3->setText(user);
}

QString MainWindow::getuser()
{
    return user;
}


MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked()
{
    Insert.setDb(db);
    if(!QString::compare(user,"sa")){
        qss.setFileName(":/qss/blue.css");
        switch (index){
        case 0: {qss.setFileName(":/qss/blue.css"); break;}
        case 1: {qss.setFileName(":/qss/black.css"); break;}
        case 2: {qss.setFileName(":/qss/brown.css"); break;}
        case 3: {qss.setFileName(":/qss/dev.css"); break;}
        case 4: {qss.setFileName(":/qss/silvery.css"); break;}
        }
        qss.open(QFile::ReadOnly);
        Insert.setStyleSheet(qss.readAll());
        qss.close();
        Insert.show();
    }
    else{
        QMessageBox::information(this, "警告", "没有权限！",QMessageBox::Yes);
        return;
    }

}

void MainWindow::on_pushButton_5_clicked()
{
    exit(-1);
}

void MainWindow::on_select_clicked()
{
    if(!QString::compare(user,"sa")){
       qss.setFileName(":/qss/blue.css");
       switch (index){
       case 0: {qss.setFileName(":/qss/blue.css"); break;}
       case 1: {qss.setFileName(":/qss/black.css"); break;}
       case 2: {qss.setFileName(":/qss/brown.css"); break;}
       case 3: {qss.setFileName(":/qss/dev.css"); break;}
       case 4: {qss.setFileName(":/qss/silvery.css"); break;}
       }
       qss.open(QFile::ReadOnly);
       Select.setStyleSheet(qss.readAll());
       qss.close();
       Select.show();
    }
    else{
        qss.setFileName(":/qss/blue.css");
        switch (index){
        case 0: {qss.setFileName(":/qss/blue.css"); break;}
        case 1: {qss.setFileName(":/qss/black.css"); break;}
        case 2: {qss.setFileName(":/qss/brown.css"); break;}
        case 3: {qss.setFileName(":/qss/dev.css"); break;}
        case 4: {qss.setFileName(":/qss/silvery.css"); break;}
        }
        qss.open(QFile::ReadOnly);
        UserSele.setStyleSheet(qss.readAll());
        qss.close();
        UserSele.show();
    }
}



void MainWindow::on_update_clicked()
{
    Update.setDb(db);
    if(!QString::compare(user,"sa")){
        qss.setFileName(":/qss/blue.css");
        switch (index){
        case 0: {qss.setFileName(":/qss/blue.css"); break;}
        case 1: {qss.setFileName(":/qss/black.css"); break;}
        case 2: {qss.setFileName(":/qss/brown.css"); break;}
        case 3: {qss.setFileName(":/qss/dev.css"); break;}
        case 4: {qss.setFileName(":/qss/silvery.css"); break;}
        }
        qss.open(QFile::ReadOnly);
        Update.setStyleSheet(qss.readAll());
        qss.close();
        Update.show();
    }
    else{
        QMessageBox::information(this, "警告", "没有权限！",QMessageBox::Yes);
        return;
    }

}

void MainWindow::on_delete_2_clicked()//数据删除
{
    Delete.setDb(db);
    if(!QString::compare(user,"sa")){
        qss.setFileName(":/qss/blue.css");
        switch (index){
        case 0: {qss.setFileName(":/qss/blue.css"); break;}
        case 1: {qss.setFileName(":/qss/black.css"); break;}
        case 2: {qss.setFileName(":/qss/brown.css"); break;}
        case 3: {qss.setFileName(":/qss/dev.css"); break;}
        case 4: {qss.setFileName(":/qss/silvery.css"); break;}
        }
        qss.open(QFile::ReadOnly);
        Delete.setStyleSheet(qss.readAll());
        qss.close();
        Delete.show();
    }
    else{
        QMessageBox::information(this, "警告", "没有权限！",QMessageBox::Yes);
        return;
    }
}


void MainWindow::on_help_clicked()//添加用户
{
    AddUser.setDb(db);
    //UserPsw.setDb(db);
    if(!QString::compare(user,"sa")){
        qss.setFileName(":/qss/blue.css");
        switch (index){
        case 0: {qss.setFileName(":/qss/blue.css"); break;}
        case 1: {qss.setFileName(":/qss/black.css"); break;}
        case 2: {qss.setFileName(":/qss/brown.css"); break;}
        case 3: {qss.setFileName(":/qss/dev.css"); break;}
        case 4: {qss.setFileName(":/qss/silvery.css"); break;}
        }
        qss.open(QFile::ReadOnly);
        AddUser.setStyleSheet(qss.readAll());
        qss.close();
        AddUser.show();
    }
    else{
        qDebug()<<"1";
        qss.setFileName(":/qss/blue.css");
        switch (index){
        case 0: {qss.setFileName(":/qss/blue.css"); break;}
        case 1: {qss.setFileName(":/qss/black.css"); break;}
        case 2: {qss.setFileName(":/qss/brown.css"); break;}
        case 3: {qss.setFileName(":/qss/dev.css"); break;}
        case 4: {qss.setFileName(":/qss/silvery.css"); break;}
        }
        qss.open(QFile::ReadOnly);
        //UserPsw.setStyleSheet(qss.readAll());
        qss.close();
        qDebug()<<"2";
        //UserPsw.show();
    }
}


void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    this->index = index;
    if(index == 0){
        qss.setFileName(":/qss/blue.css");
        qss.open(QFile::ReadOnly);
        this->setStyleSheet(qss.readAll());
        qDebug()<<"1"<<qss.fileName();
        qss.close();
        this->update();
    }
    if(index == 1){
        qss.setFileName(":/qss/black.css");
        qss.open(QFile::ReadOnly);
        this->setStyleSheet(qss.readAll());
        qDebug()<<"1"<<qss.fileName();
        //qss.close();
        this->update();
    }
    if(index == 2){
        qss.setFileName(":/qss/brown.css");
        qss.open(QFile::ReadOnly);
        this->setStyleSheet(qss.readAll());
        qDebug()<<"1"<<qss.fileName();
        //qss.close();
        this->update();
    }
    if(index == 3){
        qss.setFileName(":/qss/dev.css");
        qss.open(QFile::ReadOnly);
        this->setStyleSheet(qss.readAll());
        qDebug()<<"1"<<qss.fileName();
        //qss.close();
        this->update();
    }
    if(index == 4){
        qss.setFileName(":/qss/silvery.css");
        qss.open(QFile::ReadOnly);
        this->setStyleSheet(qss.readAll());
        qDebug()<<"1"<<qss.fileName();
        //qss.close();
        this->update();
    }
}

void MainWindow::on_pushButton_2_clicked()//切换用户
{
    this->close();
    logindialog *dlg = new logindialog();
    QFile qss(":/qss/blue.css");
    qss.open(QFile::ReadOnly);
    dlg->setStyleSheet(qss.readAll());
    qss.close();
    if(dlg->exec() ==QDialog::Accepted){
        dlg->close();
    }
    else exit(-1);
    setUser(dlg->getuser());
    showUser(user);
    UserSele.setUser(user);
    db=dlg->getdb();
    this->show();
}
