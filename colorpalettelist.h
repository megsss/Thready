#ifndef COLORPALETTELIST_H
#define COLORPALETTELIST_H
#include <QListWidget>
#include <QWidget>

class ColorPaletteList  : public QListWidget
{
    Q_OBJECT
public:
    explicit ColorPaletteList(QWidget *parent = nullptr);

signals:

public slots:

    // QAbstractItemView interface
protected:
    void startDrag(Qt::DropActions supportedActions) override;
};
#endif // COLORPALETTELIST_H
