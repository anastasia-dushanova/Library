#include "library.h"
#include "ui_library.h"

Library::Library(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Library)
{
    ui->setupUi(this);
    QStringList list;
    list.append("Книги");
    list.append("Клиенты");
    list.append("Поиск");
    ui->listWidget_tasks->addItems(list);

    insertBooks(QApplication::applicationDirPath() + "/books.txt");
    insertUsers(QApplication::applicationDirPath() + "/users.txt");

    qDebug() << QApplication::applicationDirPath();
    ui->stackedWidget->setCurrentIndex(0);
}

Library::~Library()
{
    delete ui;
}


void Library::on_pushButton_addBook_clicked()
{

}


void Library::on_pushButton_addUser_clicked()
{

}


void Library::on_pushButton_deleteBook_clicked()
{

}


void Library::on_pushButton_deleteUser_clicked()
{

}


void Library::on_pushButton_search_clicked()
{

}


void Library::on_listWidget_tasks_itemClicked(QListWidgetItem *item)
{
    int currentTask = ui->listWidget_tasks->row(item);
    ui->stackedWidget->setCurrentIndex(currentTask);
    qDebug() << "currentTask = "<<QString::number(currentTask);
}

void Library::insertBooks(QString filename){
    QFile file(filename);
    if(file.open(QIODevice::ReadOnly)){
        QTextStream in(&file);
        while(!in.atEnd()){
            QString line = in.readLine();
            QStringList list = line.split(" | ");

            int row = ui->tableWidget_books->rowCount();
            ui->tableWidget_books->setRowCount(row+1);
            QTableWidgetItem *id = new QTableWidgetItem(QString::number(row+1));
            QTableWidgetItem *name = new QTableWidgetItem(list[0]);
            QTableWidgetItem *author = new QTableWidgetItem(list[1]);
            QTableWidgetItem *isbn = new QTableWidgetItem(list[2]);
            QTableWidgetItem *count = new QTableWidgetItem(list[3]);
            ui->tableWidget_books->setItem(row, 0, id);
            ui->tableWidget_books->setItem(row, 1, name);
            ui->tableWidget_books->setItem(row, 2, author);
            ui->tableWidget_books->setItem(row, 3, isbn);
            ui->tableWidget_books->setItem(row, 4, count);
        }
    }
    file.close();
}

void Library::insertUsers(QString filename){
    QFile file(filename);
    if(file.open(QIODevice::ReadOnly)){
        QTextStream in(&file);
        while(!in.atEnd()){
            QString line = in.readLine();
            QStringList list = line.split(" | ");

            int row = ui->tableWidget_users->rowCount();
            ui->tableWidget_users->setRowCount(row+1);
            QTableWidgetItem *id = new QTableWidgetItem(QString::number(row+1));
            QTableWidgetItem *surname = new QTableWidgetItem(list[0]);
            QTableWidgetItem *name = new QTableWidgetItem(list[1]);
            QTableWidgetItem *books = new QTableWidgetItem(list[2]);
            ui->tableWidget_users->setItem(row, 0, id);
            ui->tableWidget_users->setItem(row, 1, surname);
            ui->tableWidget_users->setItem(row, 2, name);
            ui->tableWidget_users->setItem(row, 3, books);
        }
    }
    file.close();
}
