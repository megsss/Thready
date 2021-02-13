#include "mainwindow.h"
#include "ui_mainwindow.h"
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
    QGraphicsScene scene;
    //myPopulateScene(&scene);
    QGraphicsView view(&scene);
    view.show();
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
    QString file_name = QFileDialog::getOpenFileName(this, tr("Choose image to add"), QDir::homePath(), tr("Images (*.jpeg *.jpg *.png)"));
    if(QString::compare(file_name, QString()) != 0)
    {
        QImage image;
        bool valid = image.load(file_name);

        if(valid)
        {
            image = image.scaledToWidth(ui->graphicsView->width(), Qt::SmoothTransformation);
            QPixmap pix = QPixmap::fromImage(image);
            //add 'pix' onto project canvass
            //ui->graphicsView->add
        }
        else{
            qDebug() << "Image is invalid";
        }
    }


}
