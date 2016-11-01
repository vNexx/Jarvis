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
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>
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
    QFrame *frame;
    QWidget *widget;
    QVBoxLayout *vertNameLabelsLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *GroupNameEdit;
    QLineEdit *nameEdit;
    QWidget *widget2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *statusLabel;
    QRadioButton *statusRadioButton;
    QWidget *widget3;
    QVBoxLayout *verticalLayout;
    QLabel *idLabel;
    QLabel *deviceTypelabel;

    void setupUi(QDialog *SettingsDialogWindow)
    {
        if (SettingsDialogWindow->objectName().isEmpty())
            SettingsDialogWindow->setObjectName(QStringLiteral("SettingsDialogWindow"));
        SettingsDialogWindow->setWindowModality(Qt::WindowModal);
        SettingsDialogWindow->resize(344, 266);
        SettingsDialogWindow->setModal(true);
        layoutWidget = new QWidget(SettingsDialogWindow);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(80, 230, 260, 24));
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

        frame = new QFrame(SettingsDialogWindow);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(20, 30, 251, 171));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        widget = new QWidget(frame);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 10, 90, 151));
        vertNameLabelsLayout = new QVBoxLayout(widget);
        vertNameLabelsLayout->setObjectName(QStringLiteral("vertNameLabelsLayout"));
        vertNameLabelsLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        vertNameLabelsLayout->addWidget(label);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        vertNameLabelsLayout->addWidget(label_2);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));

        vertNameLabelsLayout->addWidget(label_3);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));

        vertNameLabelsLayout->addWidget(label_4);

        label_5 = new QLabel(widget);
        label_5->setObjectName(QStringLiteral("label_5"));

        vertNameLabelsLayout->addWidget(label_5);

        widget1 = new QWidget(frame);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(110, 10, 127, 52));
        verticalLayout_3 = new QVBoxLayout(widget1);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        GroupNameEdit = new QLineEdit(widget1);
        GroupNameEdit->setObjectName(QStringLiteral("GroupNameEdit"));

        verticalLayout_3->addWidget(GroupNameEdit);

        nameEdit = new QLineEdit(widget1);
        nameEdit->setObjectName(QStringLiteral("nameEdit"));

        verticalLayout_3->addWidget(nameEdit);

        widget2 = new QWidget(frame);
        widget2->setObjectName(QStringLiteral("widget2"));
        widget2->setGeometry(QRect(111, 77, 46, 20));
        horizontalLayout_2 = new QHBoxLayout(widget2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        statusLabel = new QLabel(widget2);
        statusLabel->setObjectName(QStringLiteral("statusLabel"));

        horizontalLayout_2->addWidget(statusLabel);

        statusRadioButton = new QRadioButton(widget2);
        statusRadioButton->setObjectName(QStringLiteral("statusRadioButton"));

        horizontalLayout_2->addWidget(statusRadioButton);

        widget3 = new QWidget(frame);
        widget3->setObjectName(QStringLiteral("widget3"));
        widget3->setGeometry(QRect(111, 100, 84, 61));
        verticalLayout = new QVBoxLayout(widget3);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 5, 0, 0);
        idLabel = new QLabel(widget3);
        idLabel->setObjectName(QStringLiteral("idLabel"));
        idLabel->setMargin(0);

        verticalLayout->addWidget(idLabel);

        deviceTypelabel = new QLabel(widget3);
        deviceTypelabel->setObjectName(QStringLiteral("deviceTypelabel"));

        verticalLayout->addWidget(deviceTypelabel);

        frame->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        statusRadioButton->raise();
        statusLabel->raise();

        retranslateUi(SettingsDialogWindow);
        QObject::connect(buttonBox, SIGNAL(accepted()), SettingsDialogWindow, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), SettingsDialogWindow, SLOT(reject()));

        QMetaObject::connectSlotsByName(SettingsDialogWindow);
    } // setupUi

    void retranslateUi(QDialog *SettingsDialogWindow)
    {
        SettingsDialogWindow->setWindowTitle(QApplication::translate("SettingsDialogWindow", "Device Setiings", 0));
        label->setText(QApplication::translate("SettingsDialogWindow", "Device Name:", 0));
        label_2->setText(QApplication::translate("SettingsDialogWindow", "Group Name:", 0));
        label_3->setText(QApplication::translate("SettingsDialogWindow", "Device Status:", 0));
        label_4->setText(QApplication::translate("SettingsDialogWindow", "Device ID:", 0));
        label_5->setText(QApplication::translate("SettingsDialogWindow", "Device Type:", 0));
        GroupNameEdit->setText(QApplication::translate("SettingsDialogWindow", "name", 0));
        nameEdit->setText(QApplication::translate("SettingsDialogWindow", "name", 0));
        statusLabel->setText(QApplication::translate("SettingsDialogWindow", "OFF", 0));
        statusRadioButton->setText(QString());
        idLabel->setText(QApplication::translate("SettingsDialogWindow", "ID", 0));
        deviceTypelabel->setText(QApplication::translate("SettingsDialogWindow", "Smart Device", 0));
    } // retranslateUi

};

namespace Ui {
    class SettingsDialogWindow: public Ui_SettingsDialogWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSDIALOGWINDOW_H
