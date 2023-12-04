#ifndef ADDUSER_H
#define ADDUSER_H

#include <QWidget>
#include <QDebug>
#include <QFile>
#include <QApplication>
#include <QTableWidget>
#include <QIntValidator>
#include <QMessageBox>

/*!
 *  \namespace UI
 */

namespace Ui {
class AddUser;
}

/*!
 * \brief Класс для добавления пользователей
 * \version 1.0
 * \date 01.01.2022
 */
class AddUser : public QWidget
{
    Q_OBJECT

public:

    /*!
     * \brief Конструктор
     * \param [QWidget] родитель
     */
    explicit AddUser(QWidget *parent = nullptr);

    /*!
     * \brief Деструктор
     */
    ~AddUser();

private slots:

    /*!
     * \brief Слот-обработчик нажатия на кнопку "Сохранить"
     */
    void on_pushButton_save_clicked();

    /*!
     * \brief Слот-обработчик нажатия на кнопку "Отменить"
     */
    void on_pushButton_cancel_clicked();

signals:

    /*!
     * \brief Сигнал, сообщающий о том, что можно сохранить список пользователей в файл
     * \param [QStringList] Список книг
     */
    void saveUser(QStringList list);

private:
    /*!
     * \brief Виджет для добавления пользователя
     */
    Ui::AddUser *ui;

    /*!
     * \brief Метод для очистки полей
     */
    void clearContents();
};

#endif // ADDUSER_H
