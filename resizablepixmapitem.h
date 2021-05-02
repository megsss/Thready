#ifndef RESIZABLEPIXMAPITEM_H
#define RESIZABLEPIXMAPITEM_H

#include <QGraphicsRectItem>
#include "resizablehandlerect.h"

class ResizablePixmapItem : public QGraphicsRectItem,public ResizableHandleRect
{

public:
    explicit ResizablePixmapItem(QPixmap pixmap);

    QRectF selectorFrameBounds() const override;
    QRectF boundingRect() const override;
    QPixmap getPixmap() const;
    void setSelectorFrameBounds(QRectF boundsRect) override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void setPixmap(const QPixmap &value);
    //void addAidaGraph()

private:
    QPixmap mPixmap;

};

#endif // RESIZABLEPIXMAPITEM_H
