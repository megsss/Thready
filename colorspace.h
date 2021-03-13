#ifndef COLORSPACE_H
#define COLORSPACE_H
#include <QColor>
#include <QString>
#include <QVector>

class ColorSpace
{
public:
    virtual ~ColorSpace();
    virtual QString name(int idx) const = 0;
    virtual int value(const QColor &color, int idx) const = 0;
    virtual int maximum(int idx) const = 0;

    virtual QVector<int> values(const QColor &color) const = 0;
    virtual QColor fromValues(const QVector<int> &values) const = 0;
};

#endif // COLORSPACE_H
