#ifndef ADDBOOK_H
#define ADDBOOK_H

#include <QWidget>
#include <QDebug>
#include <QFile>
#include <QApplication>
#include <QTableWidget>
#include <QIntValidator>

namespace Ui {
class AddBook;
}

class AddBook : public QWidget
{
    Q_OBJECT

public:
    explicit AddBook(QWidget *parent = nullptr);
    ~AddBook();

private slots:
    void on_pushButton_save_clicked();

    void on_pushButton_cancel_clicked();

signals:
    void saveBook(QStringList);

private:
    Ui::AddBook *ui;

    void clearContents();
};

#endif // ADDBOOK_H
