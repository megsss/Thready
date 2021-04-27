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

    // read each line until '\n' (end of line)
    // order: DMC Color #, Color Name, RGB Color
    // save to dmcColor object
    // add color to list of dmcColor objects

    qDebug() << in.readLine();
    qDebug() << in.readAll();
}
