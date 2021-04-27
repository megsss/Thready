#include "dmcfloss.h"
#include <QList>
#include <QVector>
#include <QDebug>

DMCFloss::DMCFloss(QString flossNum, QString name, QColor rgbVal)
{
    QString flossNum_ = flossNum;
    QString name_ = name;
    QColor color_ = rgbVal;
    return;
}

DMCFloss::DMCFloss(QString streamstring)
{
    qDebug() << "create dmc floss object from streamstring";
    qDebug() << streamstring;
}
