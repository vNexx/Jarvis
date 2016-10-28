/********************************************************************************
** Form generated from reading UI file 'settingsdialogwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGSDIALOGWINDOW_H
#define UI_SETTINGSDIALOGWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingsDialogWindow
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QDialogButtonBox *buttonBox;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *nameEdit;
    QLineEdit *GroupNameEdit;
    QLineEdit *statusEdit;
    QLineEdit *idEdit;
    QLineEdit *deviceTypeEdit;

    void setupUi(QDialog *SettingsDialogWindow)
    {
        if (SettingsDialogWindow->objectName().isEmpty())
            SettingsDialogWindow->setObjectName(QStringLiteral("SettingsDialogWindow"));
        SettingsDialogWindow->resize(530, 300);
        layoutWidget = new QWidget(SettingsDialogWindow);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(260, 260, 260, 24));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        buttonBox = new QDialogButtonBox(layoutWidget);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Apply|QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout->addWidget(buttonBox);

        layoutWidget1 = new QWidget(SettingsDialogWindow);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(12, 10, 281, 231));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(layoutWidget1);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout->addWidget(label_3);

        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout->addWidget(label_4);

        label_5 = new QLabel(layoutWidget1);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout->addWidget(label_5);


        horizontalLayout_2->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        nameEdit = new QLineEdit(layoutWidget1);
        nameEdit->setObjectName(QStringLiteral("nameEdit"));

        verticalLayout_2->addWidget(nameEdit);

        GroupNameEdit = new QLineEdit(layoutWidget1);
        GroupNameEdit->setObjectName(QStringLiteral("GroupNameEdit"));

        verticalLayout_2->addWidget(GroupNameEdit);

        statusEdit = new QLineEdit(layoutWidget1);
        statusEdit->setObjectName(QStringLiteral("statusEdit"));

        verticalLayout_2->addWidget(statusEdit);

        idEdit = new QLineEdit(layoutWidget1);
        idEdit->setObjectName(QStringLiteral("idEdit"));

        verticalLayout_2->addWidget(idEdit);

        deviceTypeEdit = new QLineEdit(layoutWidget1);
        deviceTypeEdit->setObjectName(QStringLiteral("deviceTypeEdit"));

        verticalLayout_2->addWidget(deviceTypeEdit);


        horizontalLayout_2->addLayout(verticalLayout_2);


        retranslateUi(SettingsDialogWindow);
        QObject::connect(buttonBox, SIGNAL(accepted()), SettingsDialogWindow, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), SettingsDialogWindow, SLOT(reject()));

        QMetaObject::connectSlotsByName(SettingsDialogWindow);
    } // setupUi

    void retranslateUi(QDialog *SettingsDialogWindow)
    {
        SettingsDialogWindow->setWindowTitle(QApplication::translate("SettingsDialogWindow", "Dialog", 0));
        label->setText(QApplication::translate("SettingsDialogWindow", "Device Name:", 0));
        label_2->setText(QApplication::translate("SettingsDialogWindow", "Group Name:", 0));
        label_3->setText(QApplication::translate("SettingsDialogWindow", "Device Status:", 0));
        label_4->setText(QApplication::translate("SettingsDialogWindow", "Device ID:", 0));
        label_5->setText(QApplication::translate("SettingsDialogWindow", "Device Type:", 0));
        nameEdit->setText(QApplication::translate("SettingsDialogWindow", "name", 0));
        GroupNameEdit->setText(QApplication::translate("SettingsDialogWindow", "name", 0));
        statusEdit->setText(QApplication::translate("SettingsDialogWindow", "off", 0));
        idEdit->setText(QApplication::translate("SettingsDialogWindow", "0", 0));
        deviceTypeEdit->setText(QApplication::translate("SettingsDialogWindow", "default", 0));
    } // retranslateUi

};

namespace Ui {
    class SettingsDialogWindow: public Ui_SettingsDialogWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSDIALOGWINDOW_H
