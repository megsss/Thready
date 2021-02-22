#include "projectcanvas.h"
#include "resizablepixmapitem.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMimeData>
#include <QGraphicsSceneDragDropEvent>
#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>
#include <QDebug>

ProjectCanvas::ProjectCanvas(QObject *parent) : QGraphicsScene(parent),
    tool(Cursor),
    drawing(false),
    lineGroup(nullptr),
    lastEraserCircle(nullptr),
    lastItem (nullptr)
{
    setSceneRect(0, 0, 750, 990);
}

void ProjectCanvas::dragMoveEvent(QGraphicsSceneDragDropEvent *event)
{
    qDebug() << "ProjectCanvas::dragMoveEvent";
    if(event->mimeData()->property("Key").canConvert(QMetaType::Int)){
        event->acceptProposedAction();
    }else{
        QGraphicsScene::dragMoveEvent(event);
    }
}

void ProjectCanvas::dropEvent(QGraphicsSceneDragDropEvent *event)
{
    if(event->mimeData()->property("Key").canConvert(QMetaType::Int)){

        int key = event->mimeData()->property("Key").toInt();


        switch (key) {
        case 20:{
            ResizablePixmapItem * pixItem = new ResizablePixmapItem(QPixmap(""));
            pixItem->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
            addItem(pixItem);
            pixItem->setPos(event->scenePos() -QPointF((pixItem->boundingRect().width()/2),
                                                       (pixItem->boundingRect().height()/2))) ;
        }
            break;
        }



        event->acceptProposedAction();
    }else{
        QGraphicsScene::dropEvent(event);
    }

}

void ProjectCanvas::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){

        if(tool == ToolType::Pen || tool == Eraser){
            startingPoint = event->scenePos();
            drawing = true;
        }else{
            QGraphicsScene::mousePressEvent(event);
        }
    }else{
        QGraphicsScene::mousePressEvent(event);
    }
}

void ProjectCanvas::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if((event->buttons() & Qt::LeftButton) && drawing){
        if(tool == ToolType::Pen){
            drawLineTo(event->scenePos());
        }else if(tool == ToolType::Eraser){
            drawEraserAt(event->scenePos());
        }
    }else{
        QGraphicsScene::mouseMoveEvent(event);
    }

}

void ProjectCanvas::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if((event->button() == Qt::LeftButton) && drawing){
        /*
        if(lastItem && ((tool == Rect)){
            removeItem(lastItem);
            delete lastItem;
        }
        */

        if(tool == ToolType::Pen){
            lineGroup = nullptr;
            drawing = false;
        }

        if(tool == ToolType::Eraser){
            removeItem(lastEraserCircle);
            delete lastEraserCircle;
            lastEraserCircle = nullptr;
            drawing = false;
        }

    }else{
        QGraphicsScene::mouseReleaseEvent(event);
    }

}

void ProjectCanvas::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Delete){
        qDebug() << "delete key pressed";
        if(selectedItems().count()  > 0){
            QGraphicsItem * itemToRemove = selectedItems()[0];
            qDebug() << itemToRemove;
            removeItem(itemToRemove);
            delete itemToRemove;
        }
    }
    QGraphicsScene::keyPressEvent(event);
}

void ProjectCanvas::drawLineTo(const QPointF &endPoint)
{
    if(!lineGroup){
        lineGroup = new QGraphicsItemGroup();
        lineGroup->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
        addItem(lineGroup);
        lastPenPoint = startingPoint;
    }

    QGraphicsLineItem  *localLine = new QGraphicsLineItem(QLineF(lastPenPoint,endPoint));
    QPen mPen;
    mPen.setWidth(3);
    mPen.setColor(Qt::green);
    localLine->setPen(mPen);
    lineGroup->addToGroup(localLine);

    lastPenPoint = endPoint;
}

void ProjectCanvas::drawEraserAt(const QPointF &endPoint)
{
    if(!lastEraserCircle){
        lastEraserCircle = addEllipse(0,0,50,50);
    }
    lastEraserCircle->setPos(endPoint - QPointF(lastEraserCircle->boundingRect().width()/2,
                                                lastEraserCircle->boundingRect().height()/2));
    eraseStrokesUnder(lastEraserCircle);

}

void ProjectCanvas::eraseStrokesUnder(QGraphicsEllipseItem *item)
{
    QList<QGraphicsItem *> itemsToRemove = item->collidingItems();
    QList<QGraphicsItemGroup *> groupItems;

    foreach (QGraphicsItem * myItem, itemsToRemove) {

        QGraphicsItemGroup * group = dynamic_cast<QGraphicsItemGroup *>(myItem);
        if(group){
            groupItems.append(group);
        }

        //Cast to graphicsLineItem
        QGraphicsLineItem * line = dynamic_cast<QGraphicsLineItem *>(myItem);
        if(line && (line != horGuideLine) && (line != verGuideLine)){
            removeItem(line);
            delete line;
        }

    }

    //Remove group items that don't have any children.
    foreach (QGraphicsItemGroup * group, groupItems) {
        if(group->childItems().count() == 0){
            qDebug() << "Group item has no child. Removing it";
            removeItem(group);
            delete group;
        }
    }
}

ProjectCanvas::ToolType ProjectCanvas::getTool() const
{
    return tool;
}

void ProjectCanvas::setTool(const ToolType &value)
{
    tool = value;
}

void ProjectCanvas::addImageItem(const QString &path)
{
    ResizablePixmapItem * image = new ResizablePixmapItem(QPixmap(path));
    image->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
    addItem(image);

    image->setPos(QPointF(300,300) - QPointF(image->boundingRect().width()/2,
                                           image->boundingRect().height()/2));
}
