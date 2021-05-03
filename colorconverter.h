#ifndef COLORCONVERTER_H
#define COLORCONVERTER_H
#include <QColor>
#include <QList>
#include "dmcfloss.h"


class ColorConverter
{
public:
    static QColor findClosestColor(QColor &color);
    static int compareColors(QColor &color, QColor &dmcColor);
    static QStringList findDMCbyRBGColor(QString color);
    static QStringList findDMCbyName(QString colorName);
    static QList<QStringList> readDMCColors();
};

#endif // COLORCONVERTER_H
