#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QScrollBar>
#include <QMessageBox>
#include <vector>
#include "dynamicbutton.h"
#include "settingsdialogwindow.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    bool checkName(const QString &name) const;

private slots:
    void on_addButton_clicked();    // СЛОТ-обработчик нажатия кнопки добавления
    void on_deleteButton_clicked(); // СЛОТ-обработчик нажатия кнопки удаления
    void slotGetButtonName();       // СЛОТ для получения имени нажатой динамической кнопки

    void on_settingsButton_clicked();
    void on_lineEdit_textChanged(const QString &str);

private:
    Ui::MainWindow *ui;
    std::vector<DynamicButton*> buttonList;
    QString stylesList[10];


};

#endif // MAINWINDOW_H
