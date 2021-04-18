#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "projectcanvas.h"
#include "view.h"
#include "colorpalette.h"
#include <QApplication>
#include <QDebug>
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QFileDialog>
#include <QDir>
#include <QMessageBox>
#include <QColorDialog>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->canvasLayout->setGeometry(QRect(0, 0, 750, 990));
    colorDialog.open();
    CreateNewProject();
    //colorPalette = new ColorPalette(this);
    //ui->colorWidgetLayout->addWidget(colorPalette);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::CreateNewProject()
{
    canvas = new ProjectCanvas(this);
    View * view = new View(this);
    view->setScene(canvas);
    ui->canvasLayout->addWidget(view);
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
    CreateNewProject();
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
    colorDialog.show();
}

void MainWindow::on_actionEyedropper_triggered()
{
    canvas->setTool(ProjectCanvas::Eyedropper);
    setActiveTool(ProjectCanvas::Eyedropper);
    statusBar()->showMessage("Current tool is Eyedropper");
    QColor color = colorDialog.getColor(Qt::white, this);
    color.toRgb();
    QString colorName = color.name();
    statusBar()->showMessage("Color chosen: " + colorName);
    //qDebug() << colorName;
    QCursor cursor(QPixmap(":/images/32/eyedropper_32.png"),32,32);
    //view->setCursor(cursor);
    setCursor(cursor);


}

void MainWindow::on_actionCursor_triggered()
{
    QCursor cursor(Qt::ArrowCursor);
    //view->setCursor(cursor);
    setCursor(cursor);
    statusBar()->showMessage("Current tool is Cursor");
    canvas->setTool(ProjectCanvas::Cursor);
    setActiveTool(ProjectCanvas::Cursor);
}

void MainWindow::on_actionFill_Color_triggered()
{
    QCursor cursor(QPixmap(":/images/32/fill_32.png"),32,32);
    //view->setCursor(cursor);
    setCursor(cursor);
    statusBar()->showMessage("Current tool is Fill");
    canvas->setTool(ProjectCanvas::Fill);
    setActiveTool(ProjectCanvas::Fill);
    QColor color = colorDialog.getColor(Qt::black,this);

    if(color.isValid()){
        canvas->setFillColor(color);
        //ui->brushColorButton->setButtonColor(color);
        //QString colorQss = QString("background-color: %1").arg(color.name());
        //ui->brushColorButton->setStyleSheet(colorQss);
    }

}

void MainWindow::on_actionEraser_triggered()
{
    QCursor cursor(Qt::ArrowCursor);
    //view->setCursor(cursor);
    setCursor(cursor);
    statusBar()->showMessage("Current tool is Eraser");
    canvas->setTool(ProjectCanvas::Eraser);
    setActiveTool(ProjectCanvas::Eraser);
}

void MainWindow::on_actionPen_triggered()
{
    QCursor cursor(QPixmap(":/images/32/pen_32.png"),32,32);
    //view->setCursor(cursor);
    setCursor(cursor);
    statusBar()->showMessage("Current tool is Pen");
    canvas->setTool(ProjectCanvas::Pen);
    setActiveTool(ProjectCanvas::Pen);
    QColor color = colorDialog.getColor(Qt::black,this);

    if(color.isValid()){
        canvas->setFillColor(color);
        //ui->brushColorButton->setButtonColor(color);
        //QString colorQss = QString("background-color: %1").arg(color.name());
        //ui->brushColorButton->setStyleSheet(colorQss);
    }
}

void MainWindow::setActiveTool(ProjectCanvas::ToolType tool)
{
    if(tool == ProjectCanvas::Cursor)
    {
        ui->actionCursor->setIcon(QIcon(":/images/50/cursor-50.png"));
        ui->actionEraser->setIcon(QIcon(":/images/50/eraser.png"));
        ui->actionEyedropper->setIcon(QIcon(":/images/50/dropper-50.png"));
        ui->actionFill_Color->setIcon(QIcon(":/images/50/fillColor.png"));
        ui->actionPen->setIcon(QIcon(":/images/50/pen-50.png"));
    }

    if(tool == ProjectCanvas::Fill)
    {
        ui->actionCursor->setIcon(QIcon(":/images/50/cursor-50.png"));
        ui->actionEraser->setIcon(QIcon(":/images/50/eraser.png"));
        ui->actionEyedropper->setIcon(QIcon(":/images/50/dropper-50.png"));
        ui->actionFill_Color->setIcon(QIcon(":/images/50/fillColor.png"));
        ui->actionPen->setIcon(QIcon(":/images/50/pen-50.png"));
    }

    if(tool == ProjectCanvas::Eraser)
    {
        ui->actionCursor->setIcon(QIcon(":/images/50/cursor-50.png"));
        ui->actionEraser->setIcon(QIcon(":/images/50/eraser.png"));
        ui->actionEyedropper->setIcon(QIcon(":/images/50/dropper-50.png"));
        ui->actionFill_Color->setIcon(QIcon(":/images/50/fillColor.png"));
        ui->actionPen->setIcon(QIcon(":/images/50/pen-50.png"));
    }

    if(tool == ProjectCanvas::Eyedropper)
    {
        ui->actionCursor->setIcon(QIcon(":/images/50/cursor-50.png"));
        ui->actionEraser->setIcon(QIcon(":/images/50/eraser.png"));
        ui->actionEyedropper->setIcon(QIcon(":/images/50/dropper-50.png"));
        ui->actionFill_Color->setIcon(QIcon(":/images/50/fillColor.png"));
        ui->actionPen->setIcon(QIcon(":/images/50/pen-50.png"));
    }

    if(tool == ProjectCanvas::Pen)
    {
        ui->actionCursor->setIcon(QIcon(":/images/50/cursor-50.png"));
        ui->actionEraser->setIcon(QIcon(":/images/50/eraser.png"));
        ui->actionEyedropper->setIcon(QIcon(":/images/50/dropper-50.png"));
        ui->actionFill_Color->setIcon(QIcon(":/images/50/fillColor.png"));
        ui->actionPen->setIcon(QIcon(":/images/50/pen-50.png"));
    }
}




