#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->verticalScrollBar->hide();
    //this->setLayout(ui->mainLayout);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::checkName(QString name) const
{
    for(int i = 0; i < ui->verticalLayoutLeft->count(); ++i)
    {
        DynamicButton *button = qobject_cast<DynamicButton*>(ui->verticalLayoutLeft->itemAt(i)->widget());
        if(button->text() == name)
        {
            QMessageBox::information(nullptr, QString("warning"), QString("Error. Name is alredy used"));
            return false;
        }

    }
    return true;
}

/* Метод для добавления динамической кнопки
 * */
void MainWindow::on_addButton_clicked()
{
    if(ui->lineEdit->text() == "")
    {
        QMessageBox::information(this, QString("warning"), QString("Error. Empty name"));
        return;
    }

    if (checkName(ui->lineEdit->text()))
    {

        DynamicButton *button = new DynamicButton(this);  // Создаем объект динамической кнопки

        /* Устанавливаем имя кнопки с заданым именем
         * */
        button->setText(ui->lineEdit->text());

        /* Добавляем кнопку в слой с вертикальной компоновкой
         * */
        ui->verticalLayoutLeft->addWidget(button);
        if (ui->verticalLayoutLeft->count() > 6)
            ui->verticalScrollBar->show();

        /* Подключаем сигнал нажатия кнопки к СЛОТ получения номера кнопки
         * */
        connect(button, SIGNAL(clicked()), this, SLOT(slotGetButtonName()));
    }
}

/* Метод для удаления динамической кнопки по её номеру
 * */
void MainWindow::on_deleteButton_clicked()
{
    /* Выполняем перебор всех элементов слоя, где располагаются динамические кнопки
     * */
    for(int i = 0; i < ui->verticalLayoutLeft->count(); ++i)
    {
        /* Производим каст элемента слоя в объект динамической кнопки
         * */
        DynamicButton *button = qobject_cast<DynamicButton*>(ui->verticalLayoutLeft->itemAt(i)->widget());
        /* Если название кнопки соответсвует строке, которая установлена
         * в lineEdit, то производим удаление данной кнопки
         * */
        if(button->text() == ui->lineEdit->text()){
            button->hide();
            delete button;
        }
    }
    if (ui->verticalLayoutLeft->count() <= 6)
        ui->verticalScrollBar->hide();
}

/* СЛОТ для получения номера кнопки.
 * */
void MainWindow::slotGetButtonName()
{
    /* Определяем объект, который вызвал сигнал
     * */
    DynamicButton *button = (DynamicButton*) sender();
    /* После чего устанавливаем номер кнопки в lineEdit,
     * который содержится в данной динамической кнопке
     * */
    ui->lineEdit->setText(button->text());
    /* То есть номер кнопки устанавливается в поле lineEdit только тогда,
     * когда мы нажимаем одну из динамических кнопок, и этот номер соответствует
     * номеру нажатой кнопки
     * */
}

void MainWindow::on_settingsButton_clicked()
{

}
