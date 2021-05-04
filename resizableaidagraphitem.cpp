#include "resizableaidagraphitem.h"
#include <QPen>
#include <QGraphicsScene>
#include <QPainter>

/*
ResizableAidaGraphItem::ResizableAidaGraphItem(int size):
    size_(size)
{
    QRect rect = QRect(50,50, 350, 350);

    //addRect(rect);

    // how far apart the lines will be
    qreal left = int(rect.left()) - (int(rect.left()) % size);
    qreal top = int(rect.top()) - (int(rect.top()) % size);
    //create the lines
    for (qreal x = left + size; x < rect.right(); x += size)
    QLineF(x, rect.top(), x, rect.bottom());
    for (qreal y = top + size; y < rect.bottom(); y += size)
    QLineF(rect.left(), y, rect.right(), y);
}
*/



void ResizableAidaGraphItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    QRectF rectangle = QRectF(QRect(50,50, 350, 350));
    painter->setBrush(brush());
    painter->drawRect(rectangle);
    drawHandlesIfNecessary();
}
