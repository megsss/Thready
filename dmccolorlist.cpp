#include "dmccolorlist.h"
#include <QFile>
#include <QDebug>

//read DMC colors from dmcColors.txt and add to array
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

    do{
        stringstream = in.readLine();
        qDebug() << stringstream;
    }while(!stringstream.isNull());

    dmcFile.close();
    qDebug() << "Done reading file";
    //currently only reads to line 180 in dmcColorValues.csv

}
