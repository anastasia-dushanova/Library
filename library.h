#ifndef LIBRARY_H
#define LIBRARY_H

#include <QMainWindow>
#include <QListWidget>
#include <QTabWidget>
#include <QFile>
#include <QDebug>
#include <QString>
#include <QTextCodec>
#include <addbook.h>
#include <adduser.h>

QT_BEGIN_NAMESPACE
namespace Ui { class Library; }
QT_END_NAMESPACE

class Library : public QMainWindow
{
    Q_OBJECT

public:
    Library(QWidget *parent = nullptr);
    ~Library();

private slots:
    void on_pushButton_addBook_clicked();

    void on_pushButton_addUser_clicked();

    void on_pushButton_deleteBook_clicked();

    void on_pushButton_deleteUser_clicked();

    void on_pushButton_search_clicked();

    void on_listWidget_tasks_itemClicked(QListWidgetItem *item);

    void slotAddNewBook(QStringList);

    void slotAddNewUser(QStringList);

private:
    Ui::Library *ui;

    AddBook *addBook;
    AddUser *addUser;
    int rowCountTableBooks = 0;
    int rowCountTableUsers = 0;

    void insertBooks(QString filename);
    void insertUsers(QString filename);
};
#endif // LIBRARY_H
