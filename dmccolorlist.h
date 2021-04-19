#ifndef DMCCOLORLIST_H
#define DMCCOLORLIST_H

#include "dmcfloss.h"

class dmcColorList
{
public:
    dmcColorList();
    QVector<DMCFloss> dmcList;

private:
    void initializeDMCList();
};

#endif // DMCCOLORLIST_H
