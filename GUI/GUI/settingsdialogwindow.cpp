#include "settingsdialogwindow.h"
#include "ui_settingsdialogwindow.h"

SettingsDialogWindow::SettingsDialogWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsDialogWindow)
{
    ui->setupUi(this);  
}


SettingsDialogWindow::SettingsDialogWindow(QWidget *parent, DynamicButton *btn, const std::vector<DynamicButton *> &btnList) : SettingsDialogWindow(parent)

{

    deviceButton = btn;
    buttonList = btnList;

    ui->idLabel->setText(QString::number(deviceButton->getID()));
    ui->deviceTypelabel->setText(deviceButton->getDeviceType());
    ui->nameEdit->setText(deviceButton->getDeviceName());
    ui->GroupNameEdit->setText(deviceButton->getGroupName());

    setStyles(stylesList);
    ui->buttonBox->setStyleSheet(stylesList[1]);



    if(deviceButton->getDeviceStatus())
    {
        ui->statusLabel->setText(QString("ON"));
        ui->statusRadioButton->setChecked(true);
    }
    else
    {
        ui->statusLabel->setText(QString("OFF"));
        ui->statusRadioButton->setChecked(false);
    }

}


SettingsDialogWindow::~SettingsDialogWindow()
{
    delete ui;
}



void SettingsDialogWindow::on_buttonBox_clicked(QAbstractButton *button)
{
    if(ui->buttonBox->standardButton(button) == QDialogButtonBox::Apply)

    {
        if(!ui->nameEdit->text().isEmpty())
        {
            for(size_t i = 0; i < buttonList.size(); ++i)
            {
                DynamicButton *button = buttonList[i];
                if(button->getDeviceName() == ui->nameEdit->text())
                {
                    QMessageBox::information(nullptr, QString("Warning"), QString("Name is already used"));
                    return;
                }
            }
            deviceButton->setDeviceName(ui->nameEdit->text());
            deviceButton->setText(ui->nameEdit->text());
        }
        else
            QMessageBox::information(nullptr, QString("warning"), QString("Error. Empty device name"));

        deviceButton->setGroupName(ui->GroupNameEdit->text());

        if(ui->statusRadioButton->isChecked())
            deviceButton->turnOnDevice();
        else
            deviceButton->turnOffDevice();



    }
}

void SettingsDialogWindow::on_statusRadioButton_clicked()
{
    if(ui->statusRadioButton->isChecked())
        ui->statusLabel->setText(QString("ON"));
    else
        ui->statusLabel->setText(QString("OFF"));
}
