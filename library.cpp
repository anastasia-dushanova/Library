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

    addBook = new AddBook();
    connect(addBook, SIGNAL(saveBook(QStringList)), this, SLOT(slotAddNewBook(QStringList)));
}

Library::~Library()
{
    delete ui;
    delete addBook;
}

void Library::slotAddNewBook(QStringList list){
    qDebug() << "add book";
    int row = rowCountTableBooks;
    ui->tableWidget_books->setRowCount(row+1);
    QTableWidgetItem *id = new QTableWidgetItem(QString::number(row+1));
    QTableWidgetItem *name = new QTableWidgetItem(list[0]);
    QTableWidgetItem *author = new QTableWidgetItem(list[1]);
    QTableWidgetItem *isbn = new QTableWidgetItem(list[2]);
    QTableWidgetItem *year = new QTableWidgetItem(list[3]);
    QTableWidgetItem *count = new QTableWidgetItem(list[4]);

    ui->tableWidget_books->setItem(row, 0, id);
    ui->tableWidget_books->setItem(row, 1, name);
    ui->tableWidget_books->setItem(row, 2, author);
    ui->tableWidget_books->setItem(row, 3, isbn);
    ui->tableWidget_books->setItem(row, 4, year);
    ui->tableWidget_books->setItem(row, 5, count);

    QFile file(QApplication::applicationDirPath() + "/books.txt");
    if(file.open(QIODevice::WriteOnly | QIODevice::Append)){

        QTextStream in(&file);
        in <<row+1 << " | "
           <<list[0] << " | "
           << list[1] << " | "
           << list[2] << " | "
           << list[3] << " | "
           << list[4] << "\n";
    }
    file.close();

}

void Library::on_pushButton_addBook_clicked()
{
    addBook->show();
}


void Library::on_pushButton_addUser_clicked()
{

}


void Library::on_pushButton_deleteBook_clicked()
{
    qDebug() << "delete book";
    int row = ui->tableWidget_books->currentRow();
    qDebug() << "cuurrentRow " << row;

    QTableWidgetItem *item = ui->tableWidget_books->item(row, 0);

    QStringList newList;
    QFile file(QApplication::applicationDirPath() + "/books.txt");
    if(file.open(QIODevice::ReadWrite | QIODevice::Text)){
        QTextStream out(&file);
        while(!out.atEnd()){
            QString line = out.readLine();
            QStringList lineList = line.split(" | ");
            if(lineList[0] != item->text())
                newList.append(lineList[0] + " | "
                        + lineList[1] + " | "
                        + lineList[2] + " | "
                        + lineList[3] + " | "
                        + lineList[4] + " | "
                        + lineList[5]);
        }

        file.resize(0);
        for(int i = 0; i < newList.size(); ++i)
           out << newList[i] << "\n";
    }



    ui->tableWidget_books->removeRow(row);
    file.close();
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
            QTableWidgetItem *id = new QTableWidgetItem(list[0]);
            QTableWidgetItem *name = new QTableWidgetItem(list[1]);
            QTableWidgetItem *author = new QTableWidgetItem(list[2]);
            QTableWidgetItem *isbn = new QTableWidgetItem(list[3]);
            QTableWidgetItem *year = new QTableWidgetItem(list[4]);
            QTableWidgetItem *count = new QTableWidgetItem(list[5]);
            ui->tableWidget_books->setItem(row, 0, id);
            ui->tableWidget_books->setItem(row, 1, name);
            ui->tableWidget_books->setItem(row, 2, author);
            ui->tableWidget_books->setItem(row, 3, isbn);
            ui->tableWidget_books->setItem(row, 4, year);
            ui->tableWidget_books->setItem(row, 5, count);
            rowCountTableBooks++;
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
            QByteArray encodedString = list[1].toUtf8();
            QTextCodec *codec = QTextCodec::codecForName("UTF-8");
            QString string = codec->toUnicode(encodedString);

            int row = ui->tableWidget_users->rowCount();
            ui->tableWidget_users->setRowCount(row+1);
            QTableWidgetItem *id = new QTableWidgetItem(list[0]);
            QTableWidgetItem *fio = new QTableWidgetItem(string);
            QTableWidgetItem *books = new QTableWidgetItem(list[2]);
            ui->tableWidget_users->setItem(row, 0, id);
            ui->tableWidget_users->setItem(row, 1, fio);
            ui->tableWidget_users->setItem(row, 2, books);
            rowCountTableUsers++;
        }
    }
    file.close();
}
