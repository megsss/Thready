#include "colorpalettelist.h"
#include "colorconverter.h"
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
    setGeometry(900, 90, 200, 200);
    setDragEnabled(true);
    setDragDropMode(DragDropMode::DragDrop);
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

void ColorPaletteList::removeColorFromList(QListWidgetItem * colorItem)
{
    removeItemWidget(colorItem);
    update();
}

void ColorPaletteList::startDrag(Qt::DropActions supportedActions)
{
    QListWidgetItem * item = takeItem(currentRow());
    QDrag* drag = new QDrag(this);
    QMimeData *mimeData = new QMimeData;
    QString colorName = item->text();

    QStringList s = ColorConverter::findDMCbyName(colorName);
    QColor color = ColorConverter::getColorByName(s);

    mimeData->setColorData(color);
    mimeData->setText(s.value(1));

    QPixmap pix(20, 20);
    pix.fill(color);
    drag->setPixmap(pix);
    drag->setMimeData(mimeData);
    drag->exec(supportedActions);

//        if(drag->exec() == Qt::IgnoreAction){
//            qDebug() << "Drag ignored";
//        }
}
