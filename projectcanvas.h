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
           Eyedropper,
           AidaGraph
       };

    ToolType getTool() const;
    void setTool(const ToolType &value);

    void addImageItem(const QString &path);

    QColor getPenColor() const;
    void setPenColor(const QColor &value);

    void addAidaGraphItem(const int &aidaSize);

    int getPenWidth() const;
    void setPenWidth(int value);

    Qt::PenStyle getPenStyle() const;
    void setPenStyle(const Qt::PenStyle &value);

    QColor getFillColor() const;
    void setFillColor(const QColor &value);

    Qt::BrushStyle getBrushStyle() const;
    void setBrushStyle(const Qt::BrushStyle &value);

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
    void drawEraserAt(const QPointF &endPoint);
    void eraseStrokesUnder(QGraphicsEllipseItem *item);
    void fillSquare(const QPointF &position);
    void addAidaGraph(QPainter *painter, int &size);

    ToolType tool;
    bool drawing;
    QGraphicsItemGroup * lineGroup;
    QPointF startingPoint;
    QPointF lastPenPoint;
    QGraphicsEllipseItem * lastEraserCircle;
    QGraphicsItem * lastItem;

    QGraphicsLineItem * horGuideLine;
    QGraphicsLineItem * verGuideLine;
    QColor penColor;
    int penWidth;
    Qt::PenStyle penStyle;
    QColor fillColor;
    Qt::BrushStyle brushStyle;
};


#endif // PROJECTCANVAS_H
