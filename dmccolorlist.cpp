#include "dmccolorlist.h"
#include <QFile>
#include <QDebug>

dmcColorList::dmcColorList()
{

}


//read DMC colors from dmcColors.txt and add to array
void dmcColorList::initializeDMCList()
{
    QFile dmcFile(":/dmcColors.txt");
    if(!dmcFile.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug() << "File open failed";
        return;
    }
    QTextStream in(&dmcFile);
    qDebug() << in.readAll();
}
