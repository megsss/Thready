#include "colorpalettelist.h"
#include <QDrag>
#include <QMimeData>
#include <QDebug>

ColorPaletteList::ColorPaletteList(QWidget *parent) : QListWidget(parent)
{
    setMinimumWidth(200);
    setMaximumHeight(300);
    setSelectionMode(QAbstractItemView::SingleSelection);
    setViewMode(QListView::ListMode);
    setFlow(Flow::TopToBottom);
    setGeometry(900, 450, 200, 200);

}

void ColorPaletteList::addColorToList(QStringList &color)
{
    qDebug() << "ColorPaletteList::addColorToList";
    QString dmcNum = color.value(0);
    QString colorName = color.value(1);
    QColor dmcColor = QColor(color.value(2).toInt(), color.value(3).toInt(), color.value(4).toInt());
    QListWidgetItem *newItem = new QListWidgetItem;
    QFont f;
    f.setPointSize(1); // It cannot be 0
    newItem->setText(colorName);
    QPixmap pix(20, 20);
    pix.fill(dmcColor);
    newItem->setIcon(QIcon(pix));
    addItem(newItem);

}

void ColorPaletteList::startDrag(Qt::DropActions supportedActions)
{
    QList<QListWidgetItem *> items = selectedItems();
    if(items.count() > 0){

        QDrag* drag = new QDrag(this);
        QMimeData *mimeData = new QMimeData;

        QColor color(items[0]->text());

        mimeData->setColorData(color);

        QPixmap pix(20, 20);
        pix.fill(color);
        drag->setPixmap(pix);
        drag->setMimeData(mimeData);
        drag->exec(supportedActions);

//        if(drag->exec() == Qt::IgnoreAction){
//            qDebug() << "Drag ignored";
//        }
    }

}
