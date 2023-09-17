#include "addbook.h"
#include "ui_addbook.h"

AddBook::AddBook(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddBook)
{
    ui->setupUi(this);
    QIntValidator *val = new QIntValidator(this);
    ui->lineEdit_count->setValidator(val);
    ui->lineEdit_count->setMaxLength(3);
    ui->lineEdit_year->setMaxLength(4);
    ui->lineEdit_isbn->setInputMask("DDD-D-DD-DDDDDD-D");
}

AddBook::~AddBook()
{
    delete ui;
}

void AddBook::on_pushButton_save_clicked()
{
    qDebug() << "save";
    QStringList list;
    list.append(ui->lineEdit_name->text());
    list.append(ui->lineEdit_author->text());
    list.append(ui->lineEdit_isbn->text());
    list.append(ui->lineEdit_year->text());
    list.append(ui->lineEdit_count->text());

    emit saveBook(list);

    clearContents();

    this->close();
}


void AddBook::on_pushButton_cancel_clicked()
{
    qDebug() << "cancel";
    clearContents();
    this->close();
}

void AddBook::clearContents(){
    ui->lineEdit_author->clear();
    ui->lineEdit_count->clear();
    ui->lineEdit_isbn->clear();
    ui->lineEdit_name->clear();
    ui->lineEdit_year->clear();
}
