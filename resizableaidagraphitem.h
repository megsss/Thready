#ifndef RESIZABLEAIDAGRAPHITEM_H
#define RESIZABLEAIDAGRAPHITEM_H

#include <QRectF>
#include <QPainter>
#include <QGraphicsItem>
#include "handleitem.h"
#include <QGraphicsRectItem>
#include "resizablehandlerect.h"

class ResizableAidaGraphItem : public QGraphicsRectItem,public ResizableHandleRect
{
public:
    explicit ResizableAidaGraphItem(int size);
    QRectF selectorFrameBounds() const override;
    QRectF boundingRect() const override;
    //QPixmap getAidaGraph() const;
    void setSelectorFrameBounds(QRectF boundsRect) override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void setAidaGraph(const QPixmap &value);

private:
    int size_;
    QRect aidaGraphSize_;
    QLineF aidaGraphLines_;
};

#endif // RESIZABLEAIDAGRAPHITEM_H
