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
    // read each line until '\n' (end of line)
    // order: DMC Color #, Color Name, RGB Color
    // save to dmcFloss object
    // add color to list of dmcFloss objects
    QString name, dmcNum, rgbString;
    //QColor rgb;

    do{
        stringstream = in.readLine();
        //qDebug() << stringstream;
        //stringstream.split(QRegExp("\\W+"), Qt::SkipEmptyParts);
        QStringList ssList = stringstream.split(QLatin1Char(','));
        qDebug() << ssList;
        dmcNum = ssList.value(0);
        qDebug() << dmcNum;
        name = ssList.value(1);
        name.remove(QChar(' '));
        qDebug() << name;
        rgbString = ssList.value(2);
        rgbString.remove(QChar(' '));
        //rgb.name(rgbString);
        //rgb = rgbString;
        //rgb = QColor::name(rgbString);
        qDebug() << rgbString;
        //dmcList.push_back(DMCFloss(dmcNum, name, rgb));

    }while(!stringstream.isNull());

    dmcFile.close();
    qDebug() << "Done reading file";

/*
    for (int i = 0; i < dmcList.count(); ++i) {
        qDebug() << dmcList;
    }
*/
    //dDebug() << dmcBefore.count();


}
