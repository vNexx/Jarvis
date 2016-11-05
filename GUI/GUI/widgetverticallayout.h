#ifndef WIDGETVERTICALLAYOUT_H
#define WIDGETVERTICALLAYOUT_H

#include <QWidget>
//#include <QVBoxLayout>
#include <QGridLayout>
#include "dynamicbutton.h"

class WidgetVerticalLayout : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetVerticalLayout(QWidget *parent = 0);

   ~WidgetVerticalLayout();
    QLayoutItem *itemAt(int index) const;
    void removeWidget(QWidget *widget);
    void addWidget(DynamicButton *widget);
    int  count() const;

    int counter;

private:
    QGridLayout *vertLayout;
};

#endif // WIDGETVERTICALLAYOUT_H
