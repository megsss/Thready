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
    qDebug() << "Save triggered";
}

void MainWindow::on_actionOpen_triggered()
{
    qDebug() << "Open triggered";
}

void MainWindow::on_actionNew_triggered()
{
    qDebug() << "New triggered";
}
