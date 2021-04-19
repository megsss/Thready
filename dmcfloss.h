#ifndef DMCFLOSS_H
#define DMCFLOSS_H

#include <QObject>
#include <QColor>

class DMCFloss
{
    Q_OBJECT
public:
    DMCFloss();
    QColor color() const { return color_; }
    QRgb qrgb() const { return color_.rgb(); }
    int code() const { return code_; }
    QString name() const { return name_; }

private:
    int code_;
    QString name_;
    QColor color_;
};

#endif // DMCFLOSS_H
