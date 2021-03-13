#include "view.h"
#include <QMouseEvent>
#include <QGraphicsRectItem>
#include "projectcanvas.h"
#include <QDebug>
#include <QPainter>

View::View(QWidget *parent) : QGraphicsView(parent),drawingSelection(false),
    lastRect(nullptr)
{

}

void View::mousePressEvent(QMouseEvent *event)
{

    QGraphicsScene * currentScene = scene();
    ProjectCanvas * mScene = dynamic_cast<ProjectCanvas * >(currentScene);

    if(mScene && (mScene->getTool() == ProjectCanvas::Cursor)){
        QGraphicsItem * sceneItem = scene()->itemAt(mapToScene(event->pos()),transform());
        if(!sceneItem){
            selectTopLeft = event->pos();
            drawingSelection = true;
        }

    }
    QGraphicsView::mousePressEvent(event);
}

void View::mouseMoveEvent(QMouseEvent *event)
{

    QGraphicsScene * currentScene = scene();
    ProjectCanvas * mScene = dynamic_cast<ProjectCanvas * >(currentScene);

    if(mScene && (mScene->getTool() == ProjectCanvas::Cursor)){
        if(drawingSelection){

            //Selection region
            QRect selectRegion = QRect(selectTopLeft,event->pos());

            QPainterPath path;
            path.addRect(selectRegion);

            scene()->setSelectionArea(mapToScene(path));

            //Draw visual feedback for the user
            QGraphicsItem * itemToRemove = lastRect;

            scene()->removeItem(itemToRemove);

            lastRect = scene()->addRect(QRectF(mapToScene(selectTopLeft),
                                               mapToScene(event->pos())).normalized());
            lastRect->setBrush(QBrush(QColor(255, 0, 0, 50)));

            delete  itemToRemove;
        }

    }

    QGraphicsView::mouseMoveEvent(event);
}

void View::mouseReleaseEvent(QMouseEvent *event)
{
    QGraphicsScene * currentScene = scene();
    ProjectCanvas * mScene = dynamic_cast<ProjectCanvas * >(currentScene);

    if(mScene && (mScene->getTool() == ProjectCanvas::Cursor)){
        if(drawingSelection){
            QGraphicsItem * itemToRemove = lastRect;
            if(itemToRemove){
                scene()->removeItem(itemToRemove);
                delete itemToRemove;
                lastRect = nullptr;
            }

        }
        drawingSelection = false;
    }

    QGraphicsView::mouseReleaseEvent(event);
}

void View::drawBackground(QPainter *painter, const QRectF &rect)
{
    Q_UNUSED(rect);
    painter->save();

    painter->setBrush(QBrush(Qt::white));

    painter->drawRect(-800,-600,1600,1200);

    painter->restore();

}

QColor View::getBackgroundColor() const
{
    return backgroundColor;
}

void View::setBackgroundColor(const QColor &value)
{
    backgroundColor = value;
    scene()->update();
}
