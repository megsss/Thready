#ifndef HANDLEITEM_H
#define HANDLEITEM_H

#include <QGraphicsRectItem>

class HandleItem : public QGraphicsRectItem
{
public:

enum Position
{
    TopLeft,
    TopRight,
    BottomRight,
    BottomLeft
};
explicit HandleItem(Position position);

protected:
void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
private:
Position handlePosition;
};

#endif // HANDLEITEM_H
