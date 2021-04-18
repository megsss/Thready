#ifndef COLORCONVERTER_H
#define COLORCONVERTER_H
#include <QColor>
#include <QList>


class ColorConverter
{
public:
    QList<QColor> dmcList;
    ColorConverter();
    QColor RGBtoDMC(QColor color);
    QColor DMCtoRGB(QColor color);
    void findClosestColor(QColor color);
    void compareColors(QColor dmcColor, QColor color);
};

#endif // COLORCONVERTER_H
