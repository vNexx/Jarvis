#include "dynamicbutton.h"

DynamicButton::DynamicButton(QWidget *parent) : QPushButton(parent)
{

    buttonID = findNewID();   /* Присвоение кнопке номера, по которому булет производиться
                               * дальнейшая работа с кнопок
                               * */
    resBusyID[buttonID] = true; //ID кнпки теперь занят
}

DynamicButton::~DynamicButton()
{
    resBusyID[buttonID] = false; //ID кнопки освобожден
}

/* Метод для возврата значения номера кнопки
 * */
int DynamicButton::getID()
{
    return buttonID;
}

int DynamicButton::findNewID()
{
    for(size_t i = 0; i < maxButtonAmount; ++i)
    {
        if(!resBusyID[i])
            return i;
    }
    QMessageBox::information(this, QString("warning"), QString("Error. Cannot create button. Delete some buttons"));
}

/* Инициализация статической переменной класса.
 * */
bool DynamicButton::resBusyID[maxButtonAmount];
