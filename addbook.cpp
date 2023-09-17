#include "addbook.h"
#include "ui_addbook.h"

AddBook::AddBook(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddBook)
{
    ui->setupUi(this);
    QIntValidator *val = new QIntValidator(this);
    ui->lineEdit_count->setValidator(val);
    ui->lineEdit_year->setValidator(val);
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
    qDebug() << "save Book";

    if(ui->lineEdit_author->text().isEmpty() ||
            ui->lineEdit_count->text().isEmpty() ||
            ui->lineEdit_isbn->text().isEmpty() ||
            ui->lineEdit_name->text().isEmpty() ||
            ui->lineEdit_year->text().isEmpty()){
        QMessageBox::warning(this,
                             "Внимание",
                             "Заполните все поля");
        return;
    }

    if( ui->lineEdit_year->text().toInt() > 2024 || ui->lineEdit_year->text().toInt() < 1900){
        QMessageBox::warning(this,
                             "Внимание",
                             "Год должен быть от 1900 и до 2024");
        ui->lineEdit_year->clear();
        return;
    }

    QStringList list;
    list.append(ui->lineEdit_name->text());
    list.append(ui->lineEdit_author->text());
    list.append(ui->lineEdit_isbn->text());
    list.append(ui->lineEdit_year->text());
    list.append(ui->lineEdit_count->text());

    emit saveBook(list);

    clearContents();

    close();
}


void AddBook::on_pushButton_cancel_clicked()
{
    qDebug() << "cancel book";
    clearContents();
    close();
}

void AddBook::clearContents(){
    ui->lineEdit_author->clear();
    ui->lineEdit_count->clear();
    ui->lineEdit_isbn->clear();
    ui->lineEdit_name->clear();
    ui->lineEdit_year->clear();
}
