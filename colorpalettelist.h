#ifndef COLORPALETTELIST_H
#define COLORPALETTELIST_H
#include <QListWidget>
#include <QWidget>

class ColorPaletteList  : public QListWidget
{
    Q_OBJECT
public:
    explicit ColorPaletteList(QWidget *parent = nullptr);
    void addColorToList(QStringList &color);

signals:

public slots:


    // QAbstractItemView interface
protected:
    void startDrag(Qt::DropActions supportedActions) override;
    //void keyPressEvent(QKeyEvent *event) override;
};
#endif // COLORPALETTELIST_H
