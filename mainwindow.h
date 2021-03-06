#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private:
    enum {
        colCount = 3
    };
    Ui::MainWindow *ui;
    int lastRow;
    QString fileName;
    void createActions();
    void loadActions();
    void loadConnections();
    bool loadFile(const QString &fileName);
    void loadRow(int row, const QString ch);
    void insertRow();

    /*
     *Actions
     */
    QAction *newRow;
    QAction *deleteRow;
    QAction *save;


private slots:
    void createRow();
    void removeRow();
    bool saveFile();
    void about();

};

#endif // MAINWINDOW_H
