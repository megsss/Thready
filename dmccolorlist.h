#ifndef DMCCOLORLIST_H
#define DMCCOLORLIST_H

#include "dmcfloss.h"

class dmcColorList
{
public:
    dmcColorList();
    QVector<DMCFloss> dmcList;
    static void initializeDMCList();

private:

};

#endif // DMCCOLORLIST_H
