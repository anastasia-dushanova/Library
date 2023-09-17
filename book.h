#ifndef BOOK_H
#define BOOK_H

#include <QString>

class Book
{
public:
    Book();
    Book(QString name, QString author, QString isbn, int count);
    ~Book() {}

    void setBookName(QString name){this->name = name;}
    void setBookAuthor(QString author){this->author = author;}
    void setBookIsbn(QString isbn){this->isbn = isbn;}
    void setBookCount(int count){this->count = count;}

    QString getBookName(){return name;}
    QString getBookAuthor(){return author;}
    QString getBookIsbn(){return isbn;}
    int getBookCount(){return count;}

private:
    QString name;
    QString author;
    QString isbn;
    int count;
};

#endif // BOOK_H
