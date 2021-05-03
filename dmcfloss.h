#ifndef DMCFLOSS_H
#define DMCFLOSS_H

#include <QObject>
#include <QColor>

class DMCFloss: QObject
{
    Q_OBJECT
public:
    DMCFloss(const QString &flossNum, const QString &name, const QColor &rgbVal);
    //DMCFloss(const QString &streamstring);
    QColor color() const { return color_; }
    QColor rgbVal() const {return rgbVal_; }
    QRgb qrgb() const { return color_.rgb(); }
    QString flossNum() const { return flossNum_; }
    QString name() const { return name_; }

private:
    QString flossNum_;
    QString name_;
    QColor rgbVal_;
    QColor color_;
};

#endif // DMCFLOSS_H
