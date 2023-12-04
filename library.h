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
/*!
 *  \namespace UI
 */
namespace Ui { class Library; }
QT_END_NAMESPACE

/*!
 * \brief Основной класс "Библиотека"
 * \version 1.0
 * \date 01.01.2022
 */
class Library : public QMainWindow
{
    Q_OBJECT

public:
    /*!
     * \brief Конструктор
     * \param [QWidget] родитель
     */
    Library(QWidget *parent = nullptr);

    /*!
     * \brief Деструктор
     */
    ~Library();

private slots:
    /*!
     * \brief Слот-обработчик нажатия на кнопку "Добавить книгу"
     */
    void on_pushButton_addBook_clicked();

    /*!
     * \brief Слот-обработчик нажатия на кнопку "Добавить клиента"
     */
    void on_pushButton_addUser_clicked();

    /*!
     * \brief Слот-обработчик нажатия на кнопку "Удалить книгу"
     */
    void on_pushButton_deleteBook_clicked();

    /*!
     * \brief Слот-обработчик нажатия на кнопку "Удалить клиента"
     */
    void on_pushButton_deleteUser_clicked();

    /*!
     * \brief Слот-обработчик нажатия на кнопку "Поиск"
     */
    void on_pushButton_search_clicked();

    /*!
     * \brief Слот для переключения задачи
     * \param [QListWidgetItem*] Задача
     */
    void on_listWidget_tasks_itemClicked(QListWidgetItem *item);

    /*!
     * \brief Слот для добавления новой книги
     * \param [QStringList] Список книг
     */
    void slotAddNewBook(QStringList list);

    /*!
     * \brief Слот для добавления нового клиента
     * \param [QStringList] Список клиентов
     */
    void slotAddNewUser(QStringList list);

private:
    /*!
     * \brief Главный виджет
     */
    Ui::Library *ui;

    /*!
     * \brief Экземпляр класса AddBook
     */
    AddBook *addBook;

    /*!
     * \brief Экземпляр класса AddUser
     */
    AddUser *addUser;

    /*!
     * \brief Количество записей в таблице "Книги"
     */
    int rowCountTableBooks = 0;

    /*!
     * \brief Количество записей в таблице "Пользователь"
     */
    int rowCountTableUsers = 0;

    /*!
     * \brief Метод для первоначальной загрузки книг в таблицу "Книги"
     * \param [QString] Путь к файлу с книгами
     */
    void insertBooks(QString filename);

    /*!
     * \brief Метод для первоначальной загрузки клиентов в таблицу "Клиенты"
     * \param [QString] Путь к файлу с клиентами
     */
    void insertUsers(QString filename);
};
#endif // LIBRARY_H
