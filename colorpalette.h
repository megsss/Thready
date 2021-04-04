#ifndef COLORPALETTE_H
#define COLORPALETTE_H
#include <QListWidget>
#include <QWidget>

class ColorPalette  : public QListWidget
{
    Q_OBJECT
public:
    explicit ColorPalette(QWidget *parent = nullptr);

signals:

public slots:

    // QAbstractItemView interface
protected:
    void startDrag(Qt::DropActions supportedActions) override;
};
#endif // COLORPALETTE_H
