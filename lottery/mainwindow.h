
#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "csvclass.h"
#include "randthread.h"
#include <QMainWindow>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    CsvClass *CsvObj;
    QList<QStringList> retList;
    QList<QStringList> fileNameList;

private slots:
    void on_pushButton_clicked();
    void randSlot();
    //线程结束函数
    void quitThreadSlot();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    //...线程对象....
    randThread *pRandThread;
};

#endif // MAINWINDOW_H
