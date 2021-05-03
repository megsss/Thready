#include "colorconverter.h"
#include <QColor>
#include <QDebug>
#include <QFile>
#include "dmcfloss.h"
#include "mainwindow.h"


QColor ColorConverter::findClosestColor(QColor &color)
{
    QColor closestRGB;
    QStringList closestDmcStringList;
    int smallestDistance = 1000;
    int distance;

    //compare to colors in file
    QFile dmcFile(":/dmcColorValues.csv");
    if(!dmcFile.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug() << "File open failed";

    }

    QTextStream in(&dmcFile);
    QString stringstream;

    QString name, dmcNum, rgbString;
    int red, blue, green;
    QColor rgb;

    QList<QStringList> DMC;

    do{
        stringstream = in.readLine();
        QStringList ssList = stringstream.split(QLatin1Char(','));
        if(!ssList.empty())
        {
            DMC.append(ssList);
            qDebug() << ssList;
        }
    }while(!stringstream.isNull());

    dmcFile.close();
    qDebug() << "Done reading file";

    qDebug()<< DMC.count();
    for(int i=0; i<DMC.count(); i++)
    {
        QStringList dmcColor = DMC[i];
        dmcNum = dmcColor.value(0);
        qDebug() << dmcNum;

        name = dmcColor.value(1);
        qDebug() << name;

        red = dmcColor.value(2).toInt();
        qDebug() << red;


        green = dmcColor.value(3).toInt();
        qDebug() << green;

        blue = dmcColor.value(4).toInt();
        qDebug() << blue;

        rgb = QColor(red, green, blue).toRgb();
        //qDebug() << rgb;
        rgbString = dmcColor.value(5);
        qDebug() << rgbString;

        //find the distance between dmc color and user selected color
        distance = compareColors(color, rgb);
        if(distance < smallestDistance){
            smallestDistance=distance;
            closestDmcStringList = DMC[i];
            closestRGB = QColor(red, green, blue, 255);

        }
        qDebug() << distance;
    }
    qDebug() << smallestDistance;
    qDebug() << closestDmcStringList;
    qDebug() << closestRGB.name();

    return closestRGB;
}

int ColorConverter::compareColors(QColor &color, QColor &dmcColor)
{
    int distance;
    distance = qAbs(color.red() - dmcColor.red()) + qAbs(color.green() - dmcColor.green()) + qAbs(color.blue() - dmcColor.blue());
    return distance;
}

QStringList ColorConverter::findDMCbyRBGColor(QString color)
{
    QFile dmcFile(":/dmcColorValues.csv");
    if(!dmcFile.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug() << "File open failed";

    }

    QTextStream in(&dmcFile);
    QString stringstream;

    QString name, dmcNum, rgbString;

    QList<QStringList> DMC;

    do{
        stringstream = in.readLine();
        QStringList ssList = stringstream.split(QLatin1Char(','));
        if(!ssList.empty())
        {
            DMC.append(ssList);
            qDebug() << ssList;
        }
    }while(!stringstream.isNull());
    dmcFile.close();
    qDebug() << "Done reading file";

    qDebug()<< DMC.count();
    for(int i=0; i<DMC.count(); i++)
    {
        QStringList dmcColor = DMC[i];
        rgbString = dmcColor.value(5);
        if(color.contains(rgbString)){
            return dmcColor;
        }
    }

}



