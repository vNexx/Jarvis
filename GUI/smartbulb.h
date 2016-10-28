#ifndef SMARTBULB_H
#define SMARTBULB_H
#include "smartdevice.h"

enum class bulbColor {white, red, blue, yellow};

class SmartBulb : public SmartDevice
{
    Q_OBJECT
public:
    SmartBulb(QWidget *parent = 0);
    SmartBulb(QWidget *parent, const QString &groupName, const QString &deviceName, int id, int brightness, bulbColor color);
    virtual ~SmartBulb();

    bool            setBrightness(int brightness);
    bool            setBulbColor(bulbColor color);
    int             getBrightness() const;
    bulbColor       getBulbColor() const;



private:
    int         brightness;  //от 1% до 100%
    bulbColor   color;
};

#endif // SMARTBULB_H
