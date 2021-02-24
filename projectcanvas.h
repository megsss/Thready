#ifndef PROJECTCANVAS_H
#define PROJECTCANVAS_H
#include <QWidget>
#include <QGraphicsScene>

class ProjectCanvas : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit ProjectCanvas(QObject *parent = nullptr);
    void save();
    enum ToolType {
           Cursor,
           Eraser,
           Pen,
           Fill,
           Eyedropper
       };

    ToolType getTool() const;
    void setTool(const ToolType &value);

    void addImageItem(const QString &path);

signals:

public slots:

protected:
    void dragMoveEvent(QGraphicsSceneDragDropEvent *event) override;
    void dropEvent(QGraphicsSceneDragDropEvent *event) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

private:
    void drawLineTo(const QPointF &endPoint);
    void drawEraserAt(const QPointF & endPoint);
    void eraseStrokesUnder(QGraphicsEllipseItem * item);

    ToolType tool;
    bool drawing;
    QGraphicsItemGroup * lineGroup;
    QPointF startingPoint;
    QPointF lastPenPoint;
    QGraphicsEllipseItem * lastEraserCircle;
    QGraphicsItem * lastItem;

    QGraphicsLineItem * horGuideLine;
    QGraphicsLineItem * verGuideLine;
};


#endif // PROJECTCANVAS_H
