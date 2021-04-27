#include "dmccolorlist.h"
#include "dmcfloss.h"
#include <QFile>
#include <QDebug>

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
    QString name, dmcNum, rgb;
    do{
        stringstream = in.readLine();
        //qDebug() << stringstream;
        QStringList ssList = stringstream.split(QLatin1Char(','));
        qDebug() << ssList;
        dmcNum = ssList[0];
        qDebug() << dmcNum;
        name = ssList[1];
        qDebug() << name;
        rgb = ssList[2];
        qDebug() << rgb;

        //DMCFloss::DMCFloss(stringstream);

    }while(!stringstream.isNull());

    dmcFile.close();
    qDebug() << "Done reading file";
    /*
    for (int i = 0; i < dmcBefore.count(); ++i) {
        qDebug() << dmcBefore[i];
    }
    */
    //dDebug() << dmcBefore.count();


}
