#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QColorDialog>
#include "projectcanvas.h"
#include "colorpalettelist.h"
#include "dmccolorpalette.h"
#include "view.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    ColorPaletteList * colorPaletteList;
    DMCColorPalette * dmcColorPaletteList;

    void CreateNewProject();
    void updateButtonColor(QPushButton *b, QColor &color);

private slots:
    void setUpPalettes();

    void on_actionExit_triggered();

    void on_actionSave_triggered();

    void on_actionOpen_triggered();

    void on_actionNew_triggered();

    void quitApp();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

    void on_actionAdd_Image_triggered();

    void on_actionCursor_triggered();

    void on_actionFill_Color_triggered();

    void on_actionEraser_triggered();

    void on_actionPen_triggered();

    void on_actionAdd_Aida_Template_triggered();

    void on_addToPaletteButton_clicked();

    void on_colorPaletteList_itemDoubleClicked(QListWidgetItem *item);

    void on_removeFromPaletteButton_clicked();

    void on_dmcAddButton_clicked();

    void on_penToolColorButton_clicked();

    void on_fillToolColorButton_clicked();

private:
    void setActiveTool(ProjectCanvas::ToolType tool);
    Ui::MainWindow *ui;
    ProjectCanvas *canvas;
    View * view;
    QColorDialog colorDialog;
    QPushButton * addToPaletteButton;
    QPushButton * removeFromPaletteButton;


};
#endif // MAINWINDOW_H
