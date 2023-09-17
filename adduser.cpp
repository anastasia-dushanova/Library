#include "adduser.h"
#include "ui_adduser.h"

AddUser::AddUser(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddUser)
{
    ui->setupUi(this);
}

AddUser::~AddUser()
{
    delete ui;
}

void AddUser::on_pushButton_save_clicked()
{
    qDebug() << "saveUser";

    if(ui->lineEdit_books->text().isEmpty() || ui->lineEdit_name->text().isEmpty()){
        QMessageBox::warning(this,
                             "Внимание",
                             "Заполните все поля");
        return;
    }
    QStringList list;
    list.append(ui->lineEdit_name->text());
    list.append(ui->lineEdit_books->text());

    emit saveUser(list);

    clearContents();

    close();
}


void AddUser::on_pushButton_cancel_clicked()
{
    qDebug() << "cancel user";
    clearContents();
    close();
}

void AddUser::clearContents(){
    ui->lineEdit_books->clear();
    ui->lineEdit_name->clear();

}
