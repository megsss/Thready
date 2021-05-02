#include "colorconverter.h"
#include <QColor>
#include <QDebug>
#include "dmcfloss.h"

ColorConverter::ColorConverter()
{

}

QColor ColorConverter::RGBtoDMC(QColor &color)
{
    QColor pickedColor = color;
    //int redValue = color.red();
    //int blueValue = color.blue();
    //int greenValue = color.green();
    //qDebug << "red color value is" + redValue ;

    //TODO
}

QColor ColorConverter::DMCtoRGB(QColor color)
{
    return color.toRgb();
}

void ColorConverter::findClosestColor(QColor &color)
{
    //DMCFloss closestmatchingfloss;
    int closestdistance;
    for(int i=0; i < dmcList.count(); i++){
        QColor dmcListColor = dmcList[i].color();
        int distance = compareColors(dmcListColor, color);
        if(distance < closestdistance)
        {
            closestdistance = distance;
            //DMCFloss closestMatch = dmcList[i];
        }
    }
    //compareColors();
}

int ColorConverter::compareColors(QColor &dmcColor, QColor &color)
{
    int distance;
    int redToCompare = color.red();
    int greenToCompare = color.green();
    int blueToCompare = color.blue();

    int dmcColorRed = dmcColor.red();
    int dmcColorGreen = dmcColor.green();
    int dmcColorBlue = dmcColor.blue();
    distance = qAbs(redToCompare - dmcColorRed) + qAbs(greenToCompare - dmcColorGreen) + qAbs(blueToCompare - dmcColorBlue);
    return distance;
}

