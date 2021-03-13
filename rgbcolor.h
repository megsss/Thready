#ifndef RGBCOLOR_H
#define RGBCOLOR_H

#include <QWidget>
#include "colorspace.h"

class RgbColor : public ColorSpace
{
public:
    static RgbColor *instance();

    QString name(int idx) const override;
    int value(const QColor &color, int idx) const override;
    int maximum(int idx) const override;

    QVector<int> values(const QColor &color) const override;
    QColor fromValues(const QVector<int> &values) const override;

private:
    RgbColor();
};

#endif // RGBCOLOR_H
