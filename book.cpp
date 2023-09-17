#include "book.h"


Book::Book(){}

Book::Book(QString name, QString author, QString isbn, int count)
    : name(name), author(author), isbn(isbn), count(count){

}
