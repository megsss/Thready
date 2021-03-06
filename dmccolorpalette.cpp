#include "dmccolorpalette.h"
#include "colorconverter.h"
#include <QDrag>
#include <QMimeData>
#include <QDebug>

DMCColorPalette::DMCColorPalette(QWidget *parent) : QListWidget(parent)
{
    setGeometry(1150, 90, 200, 200);
    setMinimumWidth(200);
    setMaximumHeight(300);
    setSelectionMode(QAbstractItemView::SingleSelection);
    setViewMode(QListView::ListMode);
    setFlow(Flow::TopToBottom);
    initializeDMCList();
}

void DMCColorPalette::initializeDMCList()
{
    qDebug() << "DMCColorPalette::initializeDMCList()";
    QList<QStringList> DMC = ColorConverter::readDMCColors();

    for(int i=0; i<DMC.count(); i++)
    {
        QStringList dmcColor = DMC[i];
        addDMCColorToList(dmcColor);
    }
    qDebug() << "All colors from file added to list";
}

void DMCColorPalette::addDMCColorToList(QStringList &color)
{
    //qDebug() << "DMCColorPalette::addDMCColorToList";
    QString dmcNum = color.value(0);
    QString colorName = color.value(1);
    QColor dmcColor = QColor(color.value(2).toInt(), color.value(3).toInt(), color.value(4).toInt());
    QListWidgetItem *newItem = new QListWidgetItem;
    QFont f;
    f.setPointSize(1);
    newItem->setText(colorName);
    QPixmap pix(20, 20);
    pix.fill(dmcColor);
    newItem->setIcon(QIcon(pix));
    addItem(newItem);
}

