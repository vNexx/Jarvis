#include "settingsdialogwindow.h"
#include "ui_settingsdialogwindow.h"

SettingsDialogWindow::SettingsDialogWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsDialogWindow)
{
    ui->setupUi(this);
    ui->idEdit->setDisabled(true);
    ui->deviceTypeEdit->setDisabled(true);
}


SettingsDialogWindow::SettingsDialogWindow(QWidget *parent, DynamicButton *btn) : SettingsDialogWindow(parent)

{

    deviceButton = btn;

    ui->idEdit->setText(QString::number(deviceButton->getID()));
    ui->deviceTypeEdit->setText(deviceButton->getDeviceType());
    ui->nameEdit->setText(deviceButton->getDeviceName());
    ui->GroupNameEdit->setText(deviceButton->getGroupName());

    if(deviceButton->getDeviceStatus())
        ui->statusEdit->setText(QString("On"));
    else
        ui->statusEdit->setText(QString("Off"));

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
            deviceButton->setDeviceName(ui->nameEdit->text());
            deviceButton->setText(ui->nameEdit->text());
        }
        else
            QMessageBox::information(nullptr, QString("warning"), QString("Error. Empty device name"));

        deviceButton->setGroupName(ui->GroupNameEdit->text());
    }
}
