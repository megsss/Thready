#ifndef COLORPALETTE_H
#define COLORPALETTE_H
#include "doubleclickbutton.h"
#include <QWidget>
#include <QColorDialog>

class ColorPalette : public QWidget
{
    Q_OBJECT
public:
    explicit ColorPalette(QWidget *parent = nullptr);
    QColorDialog colorDialog;

signals:
    void colorChanged(QColor newColor);

public slots:
private:
    void populateColors();
    void setButtonColor(DoubleclickButton * button, QColor color);
    void createColorPalette();
    void makeConnections(DoubleclickButton * button, int index);
    QVector <QColor> colors;
    void addColorToPalette(QString color);

};

#endif // COLORPALETTE_H
