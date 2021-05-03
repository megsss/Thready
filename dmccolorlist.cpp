#include "dmccolorlist.h"
#include "dmcfloss.h"
#include "colorconverter.h"
#include <QFile>
#include <QDebug>
#include <QColor>

//read DMC colors from dmcColors.txt and add to QVector<DMCFloss> dmcList
dmcColorList::dmcColorList(QWidget *parent) : QListWidget(parent)
{
    setGeometry(1150, 450, 200, 200);
    setMinimumWidth(200);
    setMaximumHeight(300);
    setSelectionMode(QAbstractItemView::SingleSelection);
    setViewMode(QListView::ListMode);
    setFlow(Flow::TopToBottom);
    initializeDMCList();
}

void dmcColorList::initializeDMCList()
{
    QList<QStringList> DMC = ColorConverter::readDMCColors();

    for(int i=0; i<DMC.count(); i++)
    {
        QStringList dmcColor = DMC[i];
        addDMCColorToList(dmcColor);
        /*
        QListWidgetItem * newListItem = new QListWidgetItem();
        QString dmcNum = DMC[i].value(0);
        QString colorName = DMC[i].value(1);
        QColor color = QColor(DMC[i].value(2).toInt(), DMC[i].value(3).toInt(), DMC[i].value(4).toInt());
        QFont f;
        f.setPointSize(1);
        newListItem->setText(colorName);
        QPixmap pix(20, 20);
        pix.fill(color);
        newListItem->setIcon(QIcon(pix));
        addItem(newListItem);
        */
        }
}

void dmcColorList::addDMCColorToList(QStringList &color)
{

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
