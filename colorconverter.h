#ifndef COLORCONVERTER_H
#define COLORCONVERTER_H
#include <QColor>
#include <QList>
#include "dmcfloss.h"


class ColorConverter
{
public:
    QList<DMCFloss> dmcList;
    ColorConverter();
    QColor RGBtoDMC(QColor &color);
    QColor DMCtoRGB(QColor color);
    void findClosestColor(QColor &color);
    int compareColors(QColor &dmcColor, QColor &color);
};

#endif // COLORCONVERTER_H
