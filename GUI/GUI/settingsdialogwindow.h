#ifndef SETTINGSDIALOGWINDOW_H
#define SETTINGSDIALOGWINDOW_H
#include <QDialog>
#include "dynamicbutton.h"

namespace Ui {
class SettingsDialogWindow;
}

class SettingsDialogWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SettingsDialogWindow(QWidget *parent = 0);
    SettingsDialogWindow(QWidget *parent, DynamicButton *btn);
    ~SettingsDialogWindow();

private slots:


    void on_buttonBox_clicked(QAbstractButton *button);

private:
    Ui::SettingsDialogWindow *ui;
    DynamicButton *deviceButton;

};

#endif // SETTINGSDIALOGWINDOW_H
