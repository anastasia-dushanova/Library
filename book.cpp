#include "book.h"


Book::Book(){}

Book::Book(QString name, QString author, QString isbn, int count)
    : name(name), author(author), isbn(isbn), count(count){

}

void Book::setBookName(QString name){this->name = name;}

void Book::setBookAuthor(QString author){this->author = author;}

void Book::setBookIsbn(QString isbn){this->isbn = isbn;}

void Book::setBookCount(int count){this->count = count;}

QString Book::getBookName(){return name;}

QString Book::getBookAuthor(){return author;}

QString Book::getBookIsbn(){return isbn;}

int Book::getBookCount(){return count;}
