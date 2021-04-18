#include "colorconverter.h"
#include <QColor>
#include <QDebug>

ColorConverter::ColorConverter()
{

}

QColor ColorConverter::RGBtoDMC(QColor color)
{
    QColor pickedColor = color;
    int redValue = color.red();
    int blueValue = color.blue();
    int greenValue = color.green();
    //qDebug << "red color value is" + redValue ;

    //TODO
}

QColor ColorConverter::DMCtoRGB(QColor color)
{
    return color.toRgb();
}

void ColorConverter::findClosestColor(QColor color)
{

    //compareColors();
}

void ColorConverter::compareColors(QColor dmcColor, QColor color)
{
    int distance;
    int redToCompare = color.red();
    int greenToCompare = color.green();
    int blueToCompare = color.blue();

    int dmcColorRed = dmcColor.red();
    int dmcColorGreen = dmcColor.green();
    int dmcColorBlue = dmcColor.blue();
    //distance = sqrt((redToCompare - dmcColorRed)^2 + (greenToCompare - dmcColorGreen)^2 + (blueToCompare - dmcColorBlue)^2);



}

