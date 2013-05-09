#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui>
#include <fstream>
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    lastRow = 0;
    ui->setupUi(this);
    loadActions();
    loadConnections();
    ui->tableWidget->setItemPrototype(new QTableWidgetItem);
    ui->tableWidget->setColumnCount(colCount);
    loadFile("/home/ahmed/Aya/GUI/Lib/row");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadActions()
{
    createActions();
    ui->mainToolBar->addAction(newRow);
    ui->mainToolBar->addAction(deleteRow);
}

void MainWindow::loadConnections()
{
    connect(newRow,SIGNAL(triggered()),this,SLOT(createRow()));
    connect(deleteRow,SIGNAL(triggered()),this,SLOT(removeRow()));
}

void MainWindow::createActions(){
    newRow = new QAction("&New",this);
    deleteRow = new QAction("&Delete",this);
}

bool MainWindow::loadFile(const QString &fileName){
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::warning(this, tr("Library"),
                             tr("Cannot read file %1:\n%2.")
                             .arg(file.fileName())
                             .arg(file.errorString()));
        return false;
    }
    QTextStream in(&file);
    QString str;
    QApplication::setOverrideCursor(Qt::WaitCursor);
    int row =0 ;
    while (!in.atEnd()) {
        str=in.readLine();
        loadRow(row,str);
        row++;
    }
    QApplication::restoreOverrideCursor();
    return true;
}

void MainWindow::loadRow(int row,const QString ch)
{
    QString str(ch);
    QStringList list= str.split(",");
    int col=0;
    ui->tableWidget->insertRow(row);
    while(col< colCount){
        QTableWidgetItem *cell=new QTableWidgetItem;
        cell->setText(list[col]);
        ui->tableWidget->setItem(row,col,cell);

        col++;
    }
    lastRow = row;
    qDebug()<< lastRow<<endl;
}


void MainWindow::createRow()
{
    lastRow++;
    ui->tableWidget->insertRow(lastRow);
}

void MainWindow::removeRow()
{
    ui->tableWidget->removeRow(ui->tableWidget->currentRow());
    lastRow--;
}
