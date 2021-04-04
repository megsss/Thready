#ifndef COLORWIDGET_H
#define COLORWIDGET_H
#include "doubleclickbutton.h"
#include <QWidget>
#include <QColorDialog>

class ColorWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ColorWidget(QWidget *parent = nullptr);

signals:
    void colorChanged(QColor newColor);

public slots:
private:
    void populateColors();
    void setButtonColor(DoubleclickButton * button, QColor color);
    void makeConnections(DoubleclickButton * button, int index);
    QVector <QColor> colors;
    QColorDialog colorDialog;

};

#endif // COLORWIDGET_H
