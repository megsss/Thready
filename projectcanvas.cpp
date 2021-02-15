#include "projectcanvas.h"
#include <QGraphicsScene>
#include <QGraphicsView>

ProjectCanvas::ProjectCanvas(QWidget *parent) : QWidget(parent)
{
    scene = new QGraphicsScene(QRectF(QRect(0, 0, 750, 990)), this);
    graphicsView = new QGraphicsView(scene);
    graphicsView->setSceneRect(QRectF(QRect(0, 0, 750, 990)));
    graphicsView->setBackgroundBrush(QBrush(Qt::white, Qt::SolidPattern));
    graphicsView->show();
}

