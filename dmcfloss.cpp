#include "dmcfloss.h"
#include <QList>
#include <QVector>
#include <QDebug>

DMCFloss::DMCFloss(const QString &flossNum, const QString &name, const QColor &rgbVal)
    :flossNum_(flossNum), name_(name), rgbVal_(rgbVal)
{
    this->flossNum_=flossNum;
    this->name_=name;
    this->rgbVal_=rgbVal;
    return;
}
