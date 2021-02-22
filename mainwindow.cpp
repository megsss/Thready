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
    statusBar()->showMessage("Create new project");
    canvas = new ProjectCanvas(this);
    View * view = new View(this);
    view->setScene(canvas);

    ui->canvasLayout->setGeometry(QRect(0, 0, 750, 990));
    ui->canvasLayout->addWidget(view);

    qDebug() << "New triggered";
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
                                                    tr("Images (*.png *.jpg)"));
    if(fileName.isNull())
        return;

    canvas->addImageItem(fileName);
}

void MainWindow::on_actionColor_Wheel_triggered()
{
    //TODO
}

void MainWindow::on_actionEyedropper_triggered()
{
    //TODO
}
