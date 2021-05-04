#include "colorconverter.h"
#include <QColor>
#include <QDebug>
#include <QFile>
#include "mainwindow.h"

//This method finds and returns the QColor of the closest DMC color to the color argument
QColor ColorConverter::findClosestColor(QColor &color)
{
    qDebug() << "ColorConverter::findClosestColor";
    QColor closestRGB;
    QStringList closestDmcStringList;
    int smallestDistance = 1000;
    int distance;

    QString name, flossNum, rgbColorString;
    int red, blue, green;
    QColor rgbColor;

    //read all DMC colors from file
    QList<QStringList> DMC = readDMCColors();

    for(int i=0; i<DMC.count(); i++)
    {
        //QStringList: ("Floss #"[0], "Color Name"[1], "Red"[2], "Green"[3], "Blue"[4], "RGB Color"[5])

        QStringList dmcColor = DMC[i];
        flossNum = dmcColor.value(0);
        name = dmcColor.value(1);
        red = dmcColor.value(2).toInt();
        green = dmcColor.value(3).toInt();
        blue = dmcColor.value(4).toInt();
        rgbColor = QColor(red, green, blue).toRgb();
        rgbColorString = dmcColor.value(5);

        //find the distance between dmc color and user selected color using euclidean distance
        distance = compareColors(color, rgbColor);

        //if DMC[i] distance is smaller than the current smallest distance, DMC[i] is now the current closest color match
        if(distance < smallestDistance){
            smallestDistance=distance;
            closestDmcStringList = DMC[i];
            closestRGB = QColor(red, green, blue, 255);

        }
        qDebug() << distance;
    }
    qDebug() << "Closest color: ";
    qDebug() << smallestDistance;
    qDebug() << closestDmcStringList;
    qDebug() << closestRGB.name();

    return closestRGB;
}

//This method uses the euclidean formula to find and return the distance between two colors
int ColorConverter::compareColors(QColor &color, QColor &dmcColor)
{
    qDebug() << "ColorConverter::compareColors";
    int distance;
    //euclidean distance formula
    distance = qAbs(color.red() - dmcColor.red()) + qAbs(color.green() - dmcColor.green()) + qAbs(color.blue() - dmcColor.blue());
    return distance;
}

//This method finds and returns the DMC QStringList that matches the rgb color argument
QStringList ColorConverter::findDMCbyRBGColor(QString color)
{
    qDebug() << "ColorConverter::findDMCbyRGBColor";

    QString name, dmcNum, rgbString;

    QList<QStringList> DMC = readDMCColors();

    for(int i=0; i<DMC.count(); i++)
    {
        QStringList dmcColor = DMC[i];
        rgbString = dmcColor.value(5);
        //qDebug() << rgbString;
        if(color.endsWith(rgbString, Qt::CaseInsensitive)){
            qDebug() << dmcColor;
            return dmcColor;
        }
    }
}

//This method finds and returns the DMC QStringList that matches the colorName argument
QStringList ColorConverter::findDMCbyName(QString colorName)
{
    qDebug() << "ColorConverter::findDMCbyName";
    QString name, dmcNum, rgbString;
    QList<QStringList> DMC = readDMCColors();
    for(int i=0; i<DMC.count(); i++)
    {
        QStringList dmcColor = DMC[i];
        name = dmcColor.value(1);
        //qDebug() << rgbString;
        if(colorName == name){
            qDebug() <<  dmcColor;
            return dmcColor;
        }
    }
}

//This function reads all lines from dmcColorValues.csv file and returns a list of <QStringList> with all DMC colors
QList<QStringList> ColorConverter::readDMCColors()
{
    qDebug() << "ColorConverter::readDMCColors()";

    QFile dmcFile(":/dmcColorValues.csv");

    if(!dmcFile.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug() << "File open failed";
    }

    QTextStream in(&dmcFile);
    QString stringstream;
    QList<QStringList> DMC;

    do{
        stringstream = in.readLine();
        QStringList ssList = stringstream.split(QLatin1Char(','));
        if(!ssList.empty())
        {
            DMC.append(ssList);
        }
    }while(!stringstream.isNull());

    //close dmcColorValues.csv file
    dmcFile.close();
    qDebug() << "Done reading file";

    //clean up list - first index item is the column headers in csv & last index item is blank
    DMC.removeFirst();
    DMC.removeLast();

    return DMC;
}

QColor ColorConverter::getColorByName(QStringList &color)
{
    QColor returnColor = QColor(color.value(2).toInt(), color.value(3).toInt(), color.value(4).toInt());
    qDebug() << "ColorConverter::getColorByName";
    qDebug() << returnColor.name();
    return returnColor;
}



