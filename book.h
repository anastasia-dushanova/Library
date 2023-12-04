#ifndef BOOK_H
#define BOOK_H

#include <QString>

/*!
 * \brief Класс "Книга"
 * \version 1.0
 * \date 01.01.2022
 */
class Book
{
public:
    /*!
     * \brief Конструктор по умолчанию
     */
    Book();

    /*!
     * \brief Конструктор
     * \param [QString] Имя
     * \param [QString] Автор
     * \param [QString] ISBN
     * \param [int] Количество
     */
    Book(QString name, QString author, QString isbn, int count);

    /*!
     * \brief Деструктор
     */
    ~Book() {}

    /*!
     * \brief Установить наименование книги
     * \param [QString] Наименование книги
     */
    void setBookName(QString name);

    /*!
     * \brief Установить автора книги
     * \param [QString] Автор книги
     */
    void setBookAuthor(QString author);

    /*!
     * \brief Установить ISBN книги
     * \param [QString] ISBN книги
     */
    void setBookIsbn(QString isbn);

    /*!
     * \brief Установить количество экземпляров книги
     * \param [int] Количество экземпляров книги
     */
    void setBookCount(int count);

    /*!
     * \brief Получить наименование книги
     * \return [QString] Наименование книги
     */
    QString getBookName();

    /*!
     * \brief Получить автора книги
     * \return [QString] Автор книги
     */
    QString getBookAuthor();

    /*!
     * \brief Получить ISBN книги
     * \return [QString] ISBN книги
     */
    QString getBookIsbn();

    /*!
     * \brief Получить количество экземпляров книги
     * \return [int] Количество экземпляров книги
     */
    int getBookCount();

private:
    /*!
     * \brief Наименование книги
     */
    QString name;

    /*!
     * \brief Автор книги
     */
    QString author;

    /*!
     * \brief ISBN книги
     */
    QString isbn;

    /*!
     * \brief Количество экземпляров книг
     */
    int count;

};

#endif // BOOK_H
