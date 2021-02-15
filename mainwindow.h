#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "projectcanvas.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

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

private:
    Ui::MainWindow *ui;
    ProjectCanvas *canvas;

};
#endif // MAINWINDOW_H
