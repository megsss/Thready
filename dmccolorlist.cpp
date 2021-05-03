#include "dmccolorlist.h"
#include "dmcfloss.h"
#include <QFile>
#include <QDebug>
#include <QColor>

//read DMC colors from dmcColors.txt and add to QVector<DMCFloss> dmcList
void dmcColorList::initializeDMCList()
{
    QFile dmcFile(":/dmcColorValues.csv");
    if(!dmcFile.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug() << "File open failed";
        return;
    }

    QTextStream in(&dmcFile);
    QString stringstream;
    QString name, dmcNum, rgbString;
    QString redString, blueString, greenString;
    int red, blue, green;
    QColor rgb;
    //DMCFloss floss;

    do{
        stringstream = in.readLine();
        QStringList ssList = stringstream.split(QLatin1Char(','));
        qDebug() << ssList;

        dmcNum = ssList.value(0);
        qDebug() << dmcNum;

        name = ssList.value(1);
        qDebug() << name;

        redString = ssList.value(2);
        qDebug() << redString;
        red = redString.toInt();

        blueString = ssList.value(3);
        qDebug() << blueString;
        blue = blueString.toInt();

        greenString = ssList.value(4);
        qDebug() << greenString;
        green = greenString.toInt();

        rgb = QColor(red, blue, green).toRgb();
        qDebug() << rgb;
        //rgb.toRgb();

        rgbString = ssList.value(5);
        qDebug() << rgbString;
        //rgb = (QColor)rgbString;

        //DMCFloss floss = DMCFloss(dmcNum, floss, rgb);

        //add floss item to dmcList
        //dmcList.push_back(DMCFloss(dmcNum, name,rgb));

    }while(!stringstream.isNull());

    dmcFile.close();
    qDebug() << "Done reading file";
}
