#ifndef DMCFLOSS_H
#define DMCFLOSS_H

#include <QObject>
#include <QColor>

class DMCFloss: QObject
{
    Q_OBJECT
public:
    DMCFloss(const QString &flossNum, const QString &name, const QString &rgbVal);
    //DMCFloss(const QString &streamstring);
    QColor color() const { return color_; }
    QString rgbVal() const {return rgbVal_; }
    QRgb qrgb() const { return color_.rgb(); }
    QString flossNum() const { return flossNum_; }
    QString name() const { return name_; }

private:
    QString flossNum_;
    QString name_;
    QString rgbVal_;
    QColor color_;
};

#endif // DMCFLOSS_H
