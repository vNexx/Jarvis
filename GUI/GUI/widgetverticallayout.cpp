#include "widgetverticallayout.h"

WidgetVerticalLayout::WidgetVerticalLayout(QWidget *parent)
    : QWidget(parent)
{
    vertLayout = new QGridLayout(parent);
    vertLayout->setSizeConstraint(QLayout::SetMaximumSize);
    this->setFixedHeight(35);
    counter = 0;
    //this->setMinimumHeight(15);
}

WidgetVerticalLayout::~WidgetVerticalLayout()
{

   delete vertLayout;
}

void WidgetVerticalLayout::addWidget(DynamicButton *widget)
{
    vertLayout->addWidget(widget, count(), 0);
    counter++;
    //this->setFixedHeight(35 * count() );

}

int  WidgetVerticalLayout::count() const
{
    return counter;//vertLayout->rowCount();
}

QLayoutItem* WidgetVerticalLayout::itemAt(int index) const
{
    return vertLayout->itemAt(index);
}

void WidgetVerticalLayout::removeWidget(QWidget *widget)
{
    vertLayout->removeWidget(widget);
    counter--;
}
