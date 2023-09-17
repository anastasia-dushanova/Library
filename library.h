#ifndef LIBRARY_H
#define LIBRARY_H

#include <QMainWindow>
#include <QListWidget>
#include <QTabWidget>
#include <QFile>
#include <QDebug>

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

private:
    Ui::Library *ui;

    void insertBooks(QString filename);
    void insertUsers(QString filename);
};
#endif // LIBRARY_H
