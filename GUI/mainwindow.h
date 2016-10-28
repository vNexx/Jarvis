#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dynamicbutton.h"
#include <QScrollBar>
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_addButton_clicked();    // СЛОТ-обработчик нажатия кнопки добавления
    void on_deleteButton_clicked(); // СЛОТ-обработчик нажатия кнопки удаления
    void slotGetButtonName();       // СЛОТ для получения имени нажатой динамической кнопки

    void on_settingsButton_clicked();

private:
    Ui::MainWindow *ui;

    bool checkName(QString name) const;
};

#endif // MAINWINDOW_H
