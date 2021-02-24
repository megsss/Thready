#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "projectcanvas.h"
#include "view.h"
#include <QApplication>
#include <QDebug>
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QFileDialog>
#include <QDir>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->canvasLayout->setGeometry(QRect(0, 0, 750, 990));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionExit_triggered()
{
    qDebug() << "Exit triggered";
    statusBar()->showMessage("App closing");
    QTimer::singleShot(3000, this, SLOT(quitApp()));


}

void MainWindow::quitApp()
{
    QApplication::quit();
}

void MainWindow::on_actionSave_triggered()
{
    QString file_name = QFileDialog::getSaveFileName(this, "Save project", QDir::homePath());
    QMessageBox::information(this, "..", file_name);
    qDebug() << "Save triggered";
}

void MainWindow::on_actionOpen_triggered()
{
    QString file_name = QFileDialog::getOpenFileName(this, tr("Open a project"), QDir::homePath());
    QMessageBox::information(this, "..", file_name);
    qDebug() << "Open triggered";
}

void MainWindow::on_actionNew_triggered()
{
    qDebug() << "New triggered";
    statusBar()->showMessage("Create new project");
    canvas = new ProjectCanvas(this);
    View * view = new View(this);
    view->setScene(canvas);

    ui->canvasLayout->addWidget(view);
}

void MainWindow::on_actionUndo_triggered()
{
    //TODO
    qDebug() << "Undo triggered";
}

void MainWindow::on_actionRedo_triggered()
{
    //TODO
    qDebug() << "Undo triggered";
}

void MainWindow::on_actionAdd_Image_triggered()
{
    qDebug() << "Add Image triggered";
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                    "/home",
                                                    tr("Images (*.png *.jpg *.jpeg)"));
    if(fileName.isNull())
        return;

    canvas->addImageItem(fileName);
}

void MainWindow::on_actionColor_Wheel_triggered()
{
    //TODO
    //insert a color picker widget
}

void MainWindow::on_actionEyedropper_triggered()
{
    statusBar()->showMessage("Current tool is Eyedropper");
    canvas->setTool(ProjectCanvas::Eyedropper);
}

void MainWindow::on_actionCursor_triggered()
{
    statusBar()->showMessage("Current tool is Cursor");
    canvas->setTool(ProjectCanvas::Cursor);
}

void MainWindow::on_actionFill_Color_triggered()
{
    statusBar()->showMessage("Current tool is Fill");
    canvas->setTool(ProjectCanvas::Fill);
}

void MainWindow::on_actionEraser_triggered()
{
    statusBar()->showMessage("Current tool is Eraser");
    canvas->setTool(ProjectCanvas::Eraser);
}
