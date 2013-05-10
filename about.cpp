#include "mainwindow.h"
#include <QtGui>

void MainWindow::about(){
    QMessageBox::about(this,
                       "TILTE_HERE",
                       "YOUR_NAMES_HERE");
}
