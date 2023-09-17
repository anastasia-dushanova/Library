#ifndef ADDUSER_H
#define ADDUSER_H

#include <QWidget>
#include <QDebug>
#include <QFile>
#include <QApplication>
#include <QTableWidget>
#include <QIntValidator>
#include <QMessageBox>

namespace Ui {
class AddUser;
}

class AddUser : public QWidget
{
    Q_OBJECT

public:
    explicit AddUser(QWidget *parent = nullptr);
    ~AddUser();

private slots:
    void on_pushButton_save_clicked();

    void on_pushButton_cancel_clicked();

signals:
    void saveUser(QStringList);

private:
    Ui::AddUser *ui;

    void clearContents();
};

#endif // ADDUSER_H
