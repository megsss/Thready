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
#include <QPushButton>
#include "colorconverter.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->canvasLayout->setGeometry(QRect(0, 0, 750, 990));
    CreateNewProject();
    setUpPalettes();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::CreateNewProject()
{
    qDebug() << "MainWindow::CreateNewProject()";
    canvas = new ProjectCanvas(this);
    View * view = new View(this);
    view->setScene(canvas);
    ui->canvasLayout->addWidget(view);
}

void MainWindow::setUpPalettes()
{
    qDebug() << "MainWindow::setUpPalettes()";
    //create QListWidgets for all DMC Colors and user's chosen colors

    colorPaletteList = new ColorPaletteList(this);
    ui->userColorPaletteLayout->addWidget(colorPaletteList);
    dmcColorPaletteList = new DMCColorPalette(this);
    ui->dmcPaletteLayout->addWidget(dmcColorPaletteList);
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
    qDebug() << "Redo triggered";
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

void MainWindow::on_actionCursor_triggered()
{
    qDebug() << "Cursor button triggered";
    QCursor cursor(Qt::ArrowCursor);
    setCursor(cursor);
    statusBar()->showMessage("Current tool is Cursor");
    canvas->setTool(ProjectCanvas::Cursor);
    setActiveTool(ProjectCanvas::Cursor);
}

void MainWindow::on_actionFill_Color_triggered()
{
    qDebug() << "Fill color toolbar button triggered";
    QCursor cursor(QPixmap(":/images/32/fill_32.png"),32,32);
    setCursor(cursor);
    statusBar()->showMessage("Current tool is Fill");
    canvas->setTool(ProjectCanvas::Fill);
    canvas->setBrushStyle(Qt::BrushStyle::SolidPattern);
    setActiveTool(ProjectCanvas::Fill);
}

void MainWindow::on_actionEraser_triggered()
{
    qDebug() << "Eraser toolbar button was triggered";
    QCursor cursor(Qt::ArrowCursor);
    setCursor(cursor);
    statusBar()->showMessage("Current tool is Eraser");
    canvas->setTool(ProjectCanvas::Eraser);
    setActiveTool(ProjectCanvas::Eraser);
}

void MainWindow::on_actionPen_triggered()
{
    qDebug() << "Pen toolbar button was triggered";
    QCursor cursor(QPixmap(":/images/32/pen_32.png"),32,32);
    setCursor(cursor);
    statusBar()->showMessage("Current tool is Pen");
    canvas->setTool(ProjectCanvas::Pen);
    setActiveTool(ProjectCanvas::Pen);
}

void MainWindow::on_actionAdd_Aida_Template_triggered()
{
    qDebug() << "Aida graph toolbar button was triggered";
    canvas->setTool(ProjectCanvas::AidaGraph);
    statusBar()->showMessage("Current tool is Aida Graph");
    canvas->addAidaGraphItem(16);
}

//This method changes the icons on the toolbar based on active tool
void MainWindow::setActiveTool(ProjectCanvas::ToolType tool)
{
    qDebug() << "MainWindow::setActiveTool - set toolbar icons";
    if(tool == ProjectCanvas::Cursor)
    {
        ui->actionCursor->setIcon(QIcon(":/images/50/cursor-50.png"));
        ui->actionEraser->setIcon(QIcon(":/images/50/eraser.png"));
        ui->actionFill_Color->setIcon(QIcon(":/images/50/fillColor.png"));
        ui->actionPen->setIcon(QIcon(":/images/50/pen-50.png"));
    }

    if(tool == ProjectCanvas::Fill)
    {
        ui->actionCursor->setIcon(QIcon(":/images/50/cursor-50.png"));
        ui->actionEraser->setIcon(QIcon(":/images/50/eraser.png"));
        ui->actionFill_Color->setIcon(QIcon(":/images/50/fillColor.png"));
        ui->actionPen->setIcon(QIcon(":/images/50/pen-50.png"));
    }

    if(tool == ProjectCanvas::Eraser)
    {
        ui->actionCursor->setIcon(QIcon(":/images/50/cursor-50.png"));
        ui->actionEraser->setIcon(QIcon(":/images/50/eraser.png"));
        ui->actionFill_Color->setIcon(QIcon(":/images/50/fillColor.png"));
        ui->actionPen->setIcon(QIcon(":/images/50/pen-50.png"));
    }

    if(tool == ProjectCanvas::Eyedropper)
    {
        ui->actionCursor->setIcon(QIcon(":/images/50/cursor-50.png"));
        ui->actionEraser->setIcon(QIcon(":/images/50/eraser.png"));
        ui->actionFill_Color->setIcon(QIcon(":/images/50/fillColor.png"));
        ui->actionPen->setIcon(QIcon(":/images/50/pen-50.png"));
    }

    if(tool == ProjectCanvas::Pen)
    {
        ui->actionCursor->setIcon(QIcon(":/images/50/cursor-50.png"));
        ui->actionEraser->setIcon(QIcon(":/images/50/eraser.png"));
        ui->actionFill_Color->setIcon(QIcon(":/images/50/fillColor.png"));
        ui->actionPen->setIcon(QIcon(":/images/50/pen-50.png"));
    }
}

void MainWindow::on_addToPaletteButton_clicked()
{
    qDebug() << "Add to palette button clicked";
    QColor userSelectedColor = colorDialog.getColor(Qt::white, this);
    //userSelectedColor.toRgb();
    QColor matchedDMCColor = ColorConverter::findClosestColor(userSelectedColor);
    QStringList colorStringList= ColorConverter::findDMCbyRBGColor(matchedDMCColor.name());
    qDebug() << "color added to user palette: ";
    qDebug() << colorStringList;
    colorPaletteList->addColorToList(colorStringList);
}

void MainWindow::on_colorPaletteList_itemDoubleClicked(QListWidgetItem *item)
{
    qDebug() << "Item in user palette double clicked";
    QString itemColorName = item->text();
    QStringList colorStringList = ColorConverter::findDMCbyName(itemColorName);
    QColor colorSelected = ColorConverter::getColorByName(colorStringList);
    canvas->setPenColor(colorSelected);
    canvas->setFillColor(colorSelected);
    qDebug() << "pen and fill colors updated";
    //canvas->addRect();
}

void MainWindow::on_removeFromPaletteButton_clicked()
{
    qDebug() << "Remove from palette button clicked";
    if(colorPaletteList->count() > 0)
    {
        QListWidgetItem * itemToBeRemoved = colorPaletteList->takeItem(colorPaletteList->currentRow());
        qDebug() << "item to be removed:";
        qDebug() << itemToBeRemoved->text();
        colorPaletteList->removeColorFromList(itemToBeRemoved);
    }
}

void MainWindow::on_dmcAddButton_clicked()
{
    qDebug() << "DMC add button clicked";

    QListWidgetItem * dmcItem = dmcColorPaletteList->currentItem();
    QString itemName = dmcItem->text();
    QStringList item = ColorConverter::findDMCbyName(itemName);
    qDebug() << "item to be added to my color palette:";
    qDebug() << item.value(1);
    colorPaletteList->addColorToList(item);

}
