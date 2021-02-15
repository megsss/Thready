#ifndef PROJECTCANVAS_H
#define PROJECTCANVAS_H

#include <QWidget>
#include <QGraphicsScene>

class ProjectCanvas : public QWidget
{
    Q_OBJECT
public:
    explicit ProjectCanvas(QWidget *parent = nullptr);
    void addImage(QString file);
    void save();

signals:



private:
    QGraphicsScene *scene;
    QGraphicsView *graphicsView;


};

#endif // PROJECTCANVAS_H
