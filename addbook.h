#ifndef ADDBOOK_H
#define ADDBOOK_H

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
class AddBook;
}

/*!
 * \brief Класс для добавления книг
 * \version 1.0
 * \date 01.01.2022
 */
class AddBook : public QWidget
{
    Q_OBJECT

public:
    /*!
     * \brief Конструктор
     * \param [QWidget] родитель
     */
    explicit AddBook(QWidget *parent = nullptr);

    /*!
     * \brief Деструктор
     */
    ~AddBook();

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
     * \brief Сигнал, сообщающий о том, что можно сохранить список книг в файл
     * \param [QStringList] Список книг
     */
    void saveBook(QStringList list);

private:
    /*!
     * \brief Виджет для добавления книги
     */
    Ui::AddBook *ui;

    /*!
     * \brief Метод для очистки полей
     */
    void clearContents();
};

#endif // ADDBOOK_H
