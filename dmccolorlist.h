#ifndef DMCCOLORLIST_H
#define DMCCOLORLIST_H

#include "dmcfloss.h"

class dmcColorList
{
public:
    static QVector<DMCFloss> dmcList;
    //static QVector<QString> dmcBefore;
    static void initializeDMCList();

private:
    static QVector<QString> dmcBefore;

};

#endif // DMCCOLORLIST_H
