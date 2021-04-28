#include "projectcanvas.h"
#include "resizablepixmapitem.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMimeData>
#include <QGraphicsSceneDragDropEvent>
#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>
#include <QDebug>
#include <QPainter>

ProjectCanvas::ProjectCanvas(QObject *parent) : QGraphicsScene(parent),
    tool(Cursor),
    drawing(false),
    lineGroup(nullptr),
    lastEraserCircle(nullptr),
    lastItem (nullptr),
    penColor(Qt::black),
    penWidth(2),
    penStyle(Qt::SolidLine),
    fillColor(Qt::gray),
    brushStyle(Qt::SolidPattern)
{
    setSceneRect(0, 0, 750, 990);
}

//drag shapes and images
void ProjectCanvas::dragMoveEvent(QGraphicsSceneDragDropEvent *event)
{
    qDebug() << "ProjectCanvas::dragMoveEvent";
    if(event->mimeData()->property("Key").canConvert(QMetaType::Int)){
        event->acceptProposedAction();
    }else{
        QGraphicsScene::dragMoveEvent(event);
    }
}


//add aida templates here on drop event
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


//create starting point for tools when left mouse button is clicked
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

//tool actions when left mouse button is clicked and moved
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
        //when mouse released, pen no longer drawing - set to false
        if(tool == ToolType::Pen){
            lineGroup = nullptr;
            drawing = false;
        }

        //remove eraser cursor circle & set drawing to false
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

//delete item from canvas with backspace button
void ProjectCanvas::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Backspace){
        qDebug() << "delete keys pressed";
        if(selectedItems().count()  > 0){
            QGraphicsItem * itemToRemove = selectedItems()[0];
            qDebug() << itemToRemove;
            removeItem(itemToRemove);
            delete itemToRemove;
        }
    }
    QGraphicsScene::keyPressEvent(event);
}

// eraser/pen - draw line to endpoint (when mouse is released)
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
    mPen.setColor(Qt::black);
    localLine->setPen(mPen);
    lineGroup->addToGroup(localLine);

    lastPenPoint = endPoint;
}

//draw eraser under cursor
void ProjectCanvas::drawEraserAt(const QPointF &endPoint)
{
    if(!lastEraserCircle){
        lastEraserCircle = addEllipse(0,0,50,50);
    }
    lastEraserCircle->setPos(endPoint - QPointF(lastEraserCircle->boundingRect().width()/2,
                                                lastEraserCircle->boundingRect().height()/2));
    eraseStrokesUnder(lastEraserCircle);

}

//erase lines underneath the eraser
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
            qDebug() << "Group item has no child. Removing.";
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
    image->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsFocusable);
    addItem(image);

    image->setPos(QPointF(300,300) - QPointF(image->boundingRect().width()/2,
                                           image->boundingRect().height()/2));
}

Qt::BrushStyle ProjectCanvas::getBrushStyle() const
{
    return brushStyle;
}

void ProjectCanvas::setBrushStyle(const Qt::BrushStyle &value)
{
    brushStyle = value;
}

QColor ProjectCanvas::getFillColor() const
{
    return fillColor;
}

void ProjectCanvas::setFillColor(const QColor &value)
{
    fillColor = value;
}

Qt::PenStyle ProjectCanvas::getPenStyle() const
{
    return penStyle;
}

void ProjectCanvas::setPenStyle(const Qt::PenStyle &value)
{
    penStyle = value;
}

int ProjectCanvas::getPenWidth() const
{
    return penWidth;
}

void ProjectCanvas::setPenWidth(int value)
{
    penWidth = value;
}

QColor ProjectCanvas::getPenColor() const
{
    return penColor;
}

void ProjectCanvas::setPenColor(const QColor &value)
{
    penColor = value;
}

void ProjectCanvas::addGraphItem(const int &aidaSize)
{
    //QLineF line;
    //QList<QGraphicsItemGroup *> grid;
    QRect rect = QRect(50,50, 350, 350);
    addRect(rect);

    // how far apart the lines will be
    qreal left = int(rect.left()) - (int(rect.left()) % aidaSize);
    qreal top = int(rect.top()) - (int(rect.top()) % aidaSize);

    //create the lines
    for (qreal x = left + aidaSize; x < rect.right(); x += aidaSize)
    addLine(QLineF(x, rect.top(), x, rect.bottom()));
    for (qreal y = top + aidaSize; y < rect.bottom(); y += aidaSize)
    addLine(QLineF(rect.left(), y, rect.right(), y));
}
