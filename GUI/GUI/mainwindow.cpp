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

    setStyles(stylesList);

    ui->addButton->setStyleSheet(stylesList[0]);
    ui->deleteButton->setStyleSheet(stylesList[0]);
    ui->settingsButton->setStyleSheet(stylesList[0]);
    ui->addGroup->setStyleSheet(stylesList[0]);
    ui->deleteGroup->setStyleSheet(stylesList[0]);



}

MainWindow::~MainWindow()
{
    delete ui;
}

DynamicButton* MainWindow::createDynamicButton(const QString &buttonName, const QString groupName, QWidget *parent)
{
    DynamicButton *button = new DynamicButton(parent);  // Создаем объект динамической кнопки


    button->setStyleSheet(stylesList[0]);
    button->setText(buttonName);
    button->setDeviceName(buttonName);
    button->setGroupName(groupName);
    buttonList.push_back(button);

    return button;
}

void MainWindow::deleteDynamicButton(const QString &buttonName)
{
    for(size_t i = 0; i < buttonList.size(); ++i)
    {
        DynamicButton *button = buttonList[i];

        if(button->text() == buttonName)
        {
            GroupTab *tab = getGroupTab(button->getGroupName(), false);
            tab->layout->counter--;
            for(size_t j = i; j < buttonList.size() - 1; ++j)
                buttonList[j] = buttonList[j + 1];           //сдвигаем список кнопок
            buttonList.pop_back();                           //удаляем последний элемент из списка


            button->hide();
            delete button;
            break;
        }
    }
}

GroupTab* MainWindow::getGroupTab(QString tabName,bool createIfNotExist, QWidget *parent)
{
    GroupTab *tab = nullptr;
    for(size_t i = 0; i < groupList.size(); ++i)
    {
        tab = groupList[i];
        if(tab->tab->text() == tabName)
            return tab;
    }
    if(createIfNotExist)
        return createGroupTab(tabName, parent);
    else
        return nullptr;
}

GroupTab* MainWindow::createGroupTab(QString tabName, QWidget *parent)
{

    if(tabName.isEmpty())
        tabName = QString("Main Group");

    GroupTab *tab = new GroupTab(parent, tabName);
    groupList.push_back(tab);

    ui->verticalLayoutLeft->addWidget(tab->tab);
    ui->verticalLayoutLeft->addWidget(tab->layout);

    tab->tab->show();

    connect(tab->tab, SIGNAL(clicked()), this, SLOT(on_tab_clicked()));
    return tab;
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
    if(ui->lineEdit->text().isEmpty())
    {
        QMessageBox::information(this, QString("warning"), QString("Error. Empty name"));
        return;
    }

    if (checkName(ui->lineEdit->text()))
    {
        ui->deleteButton->setDisabled(false);
        ui->settingsButton->setDisabled(false);


        GroupTab *tab = getGroupTab(ui->groupNameEdit->text(), true, ui->scrollAreaWidgetContents);

        // Создаем объект динамической кнопки
        DynamicButton *button = createDynamicButton(ui->lineEdit->text(), tab->tab->text(), tab->layout);

        /* Добавляем кнопку в слой с вертикальной компоновкой
         * */
        tab->layout->addWidget(button);
        button->show();


        /* Подключаем сигнал нажатия кнопки к СЛОТ получения номера кнопки
         * */
        connect(button, SIGNAL(clicked()), this, SLOT(slotGetButtonName()));
        connect(button, SIGNAL(clicked()), this, SLOT(slotOpenDeviceConfig()));

    }
    else
        QMessageBox::information(nullptr, QString("warning"), QString("Error. Name is alredy used"));

}

/* Метод для удаления динамической кнопки по её имени
 * */
void MainWindow::on_deleteButton_clicked()
{
    deleteDynamicButton(ui->lineEdit->text());
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
                SettingsDialogWindow *settings = new SettingsDialogWindow(this, button, buttonList);
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

void MainWindow::slotOpenDeviceConfig()
{
    SmartBulbConfig *configWindow = new SmartBulbConfig(this, (DynamicButton*) sender());
    configWindow->show(); //вызов диалогового окна настроек

}

void MainWindow::on_tab_clicked()
{
    QPushButton *tab =(QPushButton*)sender();

    if(tab->isChecked())
    {
        tab->setIcon(QIcon(QPixmap(":/images/tabClosed")));
    }
    else
        tab->setIcon(QIcon(QPixmap(":/images/tabOpened")));
}

void MainWindow::on_addGroup_clicked()
{    
    QString tabName = ui->groupNameEdit->text();
    getGroupTab(tabName, true, ui->scrollAreaWidgetContents); //возвращает указатель на вкладку, если ее нет, то создает ее
}



void MainWindow::on_deleteGroup_clicked()
{
    QString tabName = ui->groupNameEdit->text();

    if(tabName.isEmpty())
        return;
    GroupTab *tab = getGroupTab(tabName, false);

    if(tab == nullptr)
        return;

    GroupTab *mainTab = getGroupTab(QString("Main Group"), true, ui->scrollAreaWidgetContents);
    if(tab == mainTab)
        return;

    for( int i = 0; tab->layout->count() > 0; ++i)
    {
          DynamicButton *button = qobject_cast<DynamicButton*>(tab->layout->itemAt(i)->widget());
          DynamicButton *newButton = new DynamicButton(button, mainTab->layout);
          newButton->setStyleSheet(stylesList[0]);
          newButton->setGroupName(mainTab->tab->text());
          deleteDynamicButton(button->text());


          buttonList.push_back(newButton);
          newButton->show();
          mainTab->layout->addWidget(newButton);

          connect(newButton, SIGNAL(clicked()), this, SLOT(slotGetButtonName()));
          connect(newButton, SIGNAL(clicked()), this, SLOT(slotOpenDeviceConfig()));

    }


    for(size_t i = 0; i < groupList.size()-1; ++i)
    {
        if(tab == groupList[i])
            std::swap(groupList[i], groupList[i + 1]);
    }
    groupList.pop_back();
    delete tab;

}
