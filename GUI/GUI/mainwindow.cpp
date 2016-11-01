#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->verticalLayoutLeft->setSpacing(10);

    ui->deleteButton->setDisabled(true);
    ui->settingsButton->setDisabled(true);
    stylesList[0] = "QPushButton {"
                    "   background-color: rgb(93, 240, 84);"
                    "   border : none;"
                    "   font:  14px;"
                    "   max-width: 200px;"
                    "   min-width: 80px;"
                    "   min-height: 25px;"
                    "   padding: 5px;"
                    "}"
                    "QPushButton:disabled {"
                    "   background-color: #989898;"
                    "   color: #fff;"
                    " }"
                    "QPushButton:hover {"
                    "   background-color: #61b7ff;"
                    " }"
                    "QPushButton:focus { "
                    "   background-color: #61b7ff;"
                    " }"
                    "QPushButton:pressed {"
                    "   background-color: #54dff0;"
                    " }"
                    ;


    ui->addButton->setStyleSheet(stylesList[0]);
    ui->deleteButton->setStyleSheet(stylesList[0]);
    ui->settingsButton->setStyleSheet(stylesList[0]);

}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::checkName(const QString& name) const
{
    for(size_t i = 0; i < buttonList.size(); ++i)
    {
        DynamicButton *button = buttonList[i];
        if(button->text() == name)                 
            return false;

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
        ui->deleteButton->setDisabled(false);
        ui->settingsButton->setDisabled(false);

        DynamicButton *button = new DynamicButton(this);  // Создаем объект динамической кнопки

        button->setFlat(true);

        button->setStyleSheet(stylesList[0]);
        button->setMaximumWidth(200);
        buttonList.push_back(button);

        /* Устанавливаем имя кнопки с заданым именем
         * */
        button->setText(ui->lineEdit->text());
        button->setDeviceName(ui->lineEdit->text());

        /* Добавляем кнопку в слой с вертикальной компоновкой
         * */
        ui->verticalLayoutLeft->addWidget(button,buttonList.size()-1);


        /* Подключаем сигнал нажатия кнопки к СЛОТ получения номера кнопки
         * */
        connect(button, SIGNAL(clicked()), this, SLOT(slotGetButtonName()));       
    }
    else
        QMessageBox::information(nullptr, QString("warning"), QString("Error. Name is alredy used"));

}

/* Метод для удаления динамической кнопки по её номеру
 * */
void MainWindow::on_deleteButton_clicked()
{
    /* Выполняем перебор всех элементов слоя, где располагаются динамические кнопки
     * */
    for(size_t i = 0; i < buttonList.size(); ++i)
    {        
        DynamicButton *button = buttonList[i];
        /* Если название кнопки соответсвует строке, которая установлена
         * в lineEdit, то производим удаление данной кнопки
         * */
        if(button->text() == ui->lineEdit->text())
        {
            for(size_t j = i; j < buttonList.size() - 1; ++j)
                buttonList[j] = buttonList[j + 1];           //сдвигаем список кнопок
            buttonList.pop_back();                           //удаляем последний элемент из списка

            button->hide();
            delete button;
            break;
        }
    }

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
    if(checkName(ui->lineEdit->text()))
        QMessageBox::information(nullptr, QString("warning"),
                                 ui->lineEdit->text() +  QString(" doesn't exist"));
    else
    {
        for(size_t i = 0; i < buttonList.size(); ++i)
        {
            DynamicButton *button = buttonList[i];
            if(button->text() == ui->lineEdit->text())
            {
                SettingsDialogWindow *settings = new SettingsDialogWindow(this, button);
                settings->show(); //вызов диалогового окна настроек
            }
        }
    }

}

void MainWindow::on_lineEdit_textChanged(const QString &str)
{
    if(str.isEmpty())
    {
        ui->addButton->setDisabled(true);
        ui->deleteButton->setDisabled(true);
        ui->settingsButton->setDisabled(true);
    }
    else
    {
        ui->addButton->setDisabled(false);
        ui->deleteButton->setDisabled(false);
        ui->settingsButton->setDisabled(false);
    }

}
