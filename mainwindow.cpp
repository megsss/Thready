#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <QDebug>
#include <QTimer>

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
    //TODO
    qDebug() << "Save triggered";
}

void MainWindow::on_actionOpen_triggered()
{
    //TODO
    qDebug() << "Open triggered";
}

void MainWindow::on_actionNew_triggered()
{
    //TODO
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
