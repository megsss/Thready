#ifndef DMCCOLORPALETTE_H
#define DMCCOLORPALETTE_H

#include <QListWidget>
#include <QWidget>

class DMCColorPalette : public QListWidget
{
    Q_OBJECT
public:
    explicit DMCColorPalette(QWidget *parent = nullptr);
    void addDMCColorToList(QStringList &color);

private:
    void initializeDMCList();

signals:

public slots:


    // QAbstractItemView interface
protected:
    //void startDrag(Qt::DropActions supportedActions) override;
    //void keyPressEvent(QKeyEvent *event) override;
};

#endif // DMCCOLORPALETTE_H
