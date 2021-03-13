#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QColorDialog>
#include "projectcanvas.h"
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

    void CreateNewProject();

private slots:
    void on_actionExit_triggered();

    void on_actionSave_triggered();

    void on_actionOpen_triggered();

    void on_actionNew_triggered();

    void quitApp();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

    void on_actionAdd_Image_triggered();

    void on_actionColor_Wheel_triggered();

    void on_actionEyedropper_triggered();

    void on_actionCursor_triggered();

    void on_actionFill_Color_triggered();

    void on_actionEraser_triggered();

    void on_actionPen_triggered();

private:
    void setActiveTool(ProjectCanvas::ToolType tool);
    Ui::MainWindow *ui;
    ProjectCanvas *canvas;
    View * view;
    QColorDialog colorDialog;

};
#endif // MAINWINDOW_H
