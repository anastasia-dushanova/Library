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

    ui->stackedWidget->setCurrentIndex(0);

    addBook = new AddBook();
    addUser = new AddUser();
    connect(addBook, SIGNAL(saveBook(QStringList)), this, SLOT(slotAddNewBook(QStringList)));
    connect(addUser, SIGNAL(saveUser(QStringList)), this, SLOT(slotAddNewUser(QStringList)));
}

Library::~Library()
{
    delete ui;
    delete addBook;
    delete addUser;
}

void Library::slotAddNewUser(QStringList list){
    qDebug() << "add book";
    int row = rowCountTableUsers+1;
    ui->tableWidget_users->setRowCount(row);
    QTableWidgetItem *id = new QTableWidgetItem(QString::number(row+1));
    QTableWidgetItem *name = new QTableWidgetItem(list[0]);
    QTableWidgetItem *books = new QTableWidgetItem(list[1]);

    ui->tableWidget_users->setItem(rowCountTableUsers, 0, id);
    ui->tableWidget_users->setItem(rowCountTableUsers, 1, name);
    ui->tableWidget_users->setItem(rowCountTableUsers, 2, books);

    QFile file(QApplication::applicationDirPath() + "/users.txt");
    if(file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)){

        QTextStream in(&file);
        in <<row+1 << " | "
           <<list[0] << " | "
           << list[1] << "\n";
    }
    file.close();
}

void Library::slotAddNewBook(QStringList list){
    qDebug() << "add book";
    int row = rowCountTableBooks+1;
    ui->tableWidget_books->setRowCount(row);
    QTableWidgetItem *id = new QTableWidgetItem(QString::number(row+1));
    QTableWidgetItem *name = new QTableWidgetItem(list[0]);
    QTableWidgetItem *author = new QTableWidgetItem(list[1]);
    QTableWidgetItem *isbn = new QTableWidgetItem(list[2]);
    QTableWidgetItem *year = new QTableWidgetItem(list[3]);
    QTableWidgetItem *count = new QTableWidgetItem(list[4]);

    ui->tableWidget_books->setItem(rowCountTableBooks, 0, id);
    ui->tableWidget_books->setItem(rowCountTableBooks, 1, name);
    ui->tableWidget_books->setItem(rowCountTableBooks, 2, author);
    ui->tableWidget_books->setItem(rowCountTableBooks, 3, isbn);
    ui->tableWidget_books->setItem(rowCountTableBooks, 4, year);
    ui->tableWidget_books->setItem(rowCountTableBooks, 5, count);

    QFile file(QApplication::applicationDirPath() + "/books.txt");
    if(file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)){

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
    addUser->show();
}


void Library::on_pushButton_deleteBook_clicked()
{
    qDebug() << "delete book";
    int row = ui->tableWidget_books->currentRow();
    if(row == -1)
        return;

    qDebug() << "currentRow " << row;

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
    qDebug() << "delete user";
    int row = ui->tableWidget_users->currentRow();
    if(row == -1)
        return;

    qDebug() << "currentRow " << row;

    QTableWidgetItem *item = ui->tableWidget_users->item(row, 0);

    QStringList newList;
    QFile file(QApplication::applicationDirPath() + "/users.txt");
    if(file.open(QIODevice::ReadWrite | QIODevice::Text)){
        QTextStream out(&file);
        while(!out.atEnd()){
            QString line = out.readLine();
            QStringList lineList = line.split(" | ");
            if(lineList[0] != item->text())
                newList.append(lineList[0] + " | "
                        + lineList[1] + " | "
                        + lineList[2]);
        }

        file.resize(0);
        for(int i = 0; i < newList.size(); ++i)
           out << newList[i] << "\n";
    }



    ui->tableWidget_users->removeRow(row);
    file.close();
}


void Library::on_pushButton_search_clicked()
{
    qDebug() << "search";
    QString name = ui->lineEdit_search->text();
    if(name.isEmpty()) {
        QMessageBox::warning(this,
                             "Внимание",
                             "Введите текст");
        return;
    }

    QList<QTableWidgetItem *> listItems = ui->tableWidget_books->findItems(name,Qt::MatchExactly);
    if(listItems.isEmpty())
        ui->textBrowser_search->setText("Совпадений не найдено");
    else{
        ui->textBrowser_search->setText("Результаты поиска: \n");
        for(int i = 0; i < listItems.size(); ++i){
            QString prev = ui->textBrowser_search->toPlainText();
            QString author = ui->tableWidget_books->item(listItems[i]->row(), 2)->text();
            QString count = ui->tableWidget_books->item(listItems[i]->row(), 5)->text();
            ui->textBrowser_search->setText(prev + listItems[i]->text() + "\t" + author + "\t" + count + "\n");
        }
    }
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
