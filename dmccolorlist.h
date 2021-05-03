#ifndef DMCCOLORLIST_H
#define DMCCOLORLIST_H

#include "dmcfloss.h"

#include <QListWidget>

class dmcColorList : public QListWidget
{
    Q_OBJECT
public:
    explicit dmcColorList(QWidget *parent = nullptr);

private:
    void initializeDMCList();
    void addDMCColorToList(QStringList &color);


};

#endif // DMCCOLORLIST_H
