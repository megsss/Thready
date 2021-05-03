#include "dmccombobox.h"
#include <QAbstractItemView>
#include <QColor>
#include <QListView>

DMCComboBox::DMCComboBox()
{
    setEditable(true);
    setMinimumWidth(200);
    setMaximumWidth(300);
    testPopulateColors();

}

void DMCComboBox::testPopulateColors()
{
    QStringList qtColors = QColor::colorNames();

    for(int i = 0; i < qtColors.count(); i++)
    {
        addItem(qtColors[i]);

    }
}
