#ifndef DMCFLOSS_H
#define DMCFLOSS_H

#include <QObject>
#include <QColor>

class DMCFloss: QObject
{
    Q_OBJECT
public:
    DMCFloss(QString const flossNum, QString const name, QColor const rgbVal);
    DMCFloss(QString streamstring);
    QColor color() const { return color_; }
    QRgb qrgb() const { return color_.rgb(); }
    QString flossNum() const { return flossNum_; }
    QString name() const { return name_; }

private:
    QString flossNum_;
    QString name_;
    QColor color_;
};

#endif // DMCFLOSS_H
