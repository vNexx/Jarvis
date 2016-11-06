#include "widgetverticallayout.h"

WidgetVerticalLayout::WidgetVerticalLayout(QWidget *parent)
    : QWidget(parent)
{
    vertLayout = new QGridLayout(parent);
    vertLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
}

WidgetVerticalLayout::~WidgetVerticalLayout()
{

}

void WidgetVerticalLayout::addWidget(DynamicButton *widget)
{
    vertLayout->addWidget(widget, count(), 0);

}

int  WidgetVerticalLayout::count() const
{
    return vertLayout->count();
}

QLayoutItem* WidgetVerticalLayout::itemAt(int index) const
{
    return vertLayout->itemAt(index);
}


void WidgetVerticalLayout::removeWidget(QWidget *widget)
{
    vertLayout->removeWidget(widget);
    delete widget;
}
