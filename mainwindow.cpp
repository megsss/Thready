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
#include <QColorDialog>
#include "colorconverter.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->canvasLayout->setGeometry(QRect(0, 0, 750, 990));
    colorDialog.open();
    CreateNewProject();
    colorPaletteList = new ColorPaletteList(this);
    dmcColorPaletteList = new DMCColorPalette(this);


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
    qDebug() << "Quitting app";
    colorDialog.close();
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
    colorDialog.open();
    statusBar()->showMessage("Color Wheel");
}

void MainWindow::on_actionEyedropper_triggered()
{
    canvas->setTool(ProjectCanvas::Eyedropper);
    setActiveTool(ProjectCanvas::Eyedropper);
    statusBar()->showMessage("Current tool is Eyedropper");
    QCursor cursor(QPixmap(":/images/32/eyedropper_32.png"),32,32);
    //view->setCursor(cursor);
    setCursor(cursor);

    QColor color = colorDialog.getColor(Qt::white, this);
    color.toRgb();
    QString colorName = color.name();
    QColor dmcColor = ColorConverter::findClosestColor(color);
    QStringList colorStringList= ColorConverter::findDMCbyRBGColor(dmcColor.name());
    qDebug() << colorStringList;
    colorPaletteList->addColorToList(colorStringList);
}

void MainWindow::on_actionCursor_triggered()
{
    QCursor cursor(Qt::ArrowCursor);
    setCursor(cursor);
    statusBar()->showMessage("Current tool is Cursor");
    canvas->setTool(ProjectCanvas::Cursor);
    setActiveTool(ProjectCanvas::Cursor);
}

void MainWindow::on_actionFill_Color_triggered()
{
    QCursor cursor(QPixmap(":/images/32/fill_32.png"),32,32);
    setCursor(cursor);
    statusBar()->showMessage("Current tool is Fill");
    canvas->setTool(ProjectCanvas::Fill);
    canvas->setBrushStyle(Qt::BrushStyle::SolidPattern);
    setActiveTool(ProjectCanvas::Fill);
    QColor color = colorDialog.getColor(Qt::black,this);
    QColor dmcColor = ColorConverter::findClosestColor(color);
    qDebug() << dmcColor;

    if(dmcColor.isValid()){
        canvas->setFillColor(dmcColor);
        QStringList colorStringList= ColorConverter::findDMCbyRBGColor(dmcColor.name());
        colorPaletteList->addColorToList(colorStringList);
        statusBar()->showMessage(colorStringList.value(2));
    }


}

void MainWindow::on_actionEraser_triggered()
{
    QCursor cursor(Qt::ArrowCursor);
    setCursor(cursor);
    statusBar()->showMessage("Current tool is Eraser");
    canvas->setTool(ProjectCanvas::Eraser);
    setActiveTool(ProjectCanvas::Eraser);
}

void MainWindow::on_actionPen_triggered()
{
    QCursor cursor(QPixmap(":/images/32/pen_32.png"),32,32);
    setCursor(cursor);
    statusBar()->showMessage("Current tool is Pen");
    canvas->setTool(ProjectCanvas::Pen);
    setActiveTool(ProjectCanvas::Pen);

    QColor color = colorDialog.getColor(Qt::red, this);
    QColor dmcColor = ColorConverter::findClosestColor(color);

    if(dmcColor.isValid()){
        canvas->setPenColor(dmcColor);
        QStringList colorStringList= ColorConverter::findDMCbyRBGColor(dmcColor.name());
        colorPaletteList->addColorToList(colorStringList);
    }
}

void MainWindow::on_actionAdd_Aida_Template_triggered()
{

    canvas->setTool(ProjectCanvas::AidaGraph);
    statusBar()->showMessage("Current tool is Aida Graph");
    canvas->addAidaGraphItem(16);
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
