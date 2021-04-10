#ifndef COLORCONVERTER_H
#define COLORCONVERTER_H
#include <QColor>


class ColorConverter
{
public:
    ColorConverter();
    QColor RGBtoDMC(QColor color);
    QColor DMCtoRGB(QColor color);
};

#endif // COLORCONVERTER_H
