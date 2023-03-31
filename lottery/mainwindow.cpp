
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QFile>
#include <QDebug>
#include<QFileDialog>
#include<QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    CsvObj = new CsvClass();
    //retList = CsvObj->ReadFromCSV(":/poetry/Poetry/poetry_75.csv");
   // retList = CsvObj->ReadFromCSV(":/poetry/Poetry/poetry_75.csv");
    //retList = fileNameList;


    //....创建线程对象.......
    pRandThread=new randThread(this);


    connect(pRandThread,SIGNAL(randSignal()),this,SLOT(randSlot()));
    //关闭窗口的时候结束线程
    connect(this,SIGNAL(destroyed()),this,SLOT(quitThreadSlot()));
    ui->pushButton->setDisabled(1);
    ui->pushButton_2->setDisabled(1);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()//开始按钮
{

    //...调用run函数...每隔1s发送一个信号...
    pRandThread->start();



}

void MainWindow::randSlot()
{
    // 1.获取一个随机数
    int i = CsvObj->getLineOfCSV();
    int i_rand = rand()%i;

    // 2.显示到文本
    // ui->lineEdit_rand->setText(str_rand);
    ui->label->setText(retList[i_rand][0]);
}

void MainWindow::quitThreadSlot()
{
    pRandThread->quit();
    pRandThread->wait();

}


void MainWindow::on_pushButton_2_clicked()//结束按钮
{
    pRandThread->terminate();
}


void MainWindow::on_pushButton_3_clicked()//选择文件按钮
{
    QStringList fileNameList = QFileDialog::getOpenFileNames(this, QString::fromLocal8Bit("添加文本"), "", tr("CSV(*.csv)"));
    qDebug() << fileNameList;
    retList = CsvObj->ReadFromCSV(fileNameList.join(""));
    if(!retList.isEmpty() && !fileNameList.isEmpty()){
        ui->pushButton->setEnabled(1);
        ui->pushButton_2->setEnabled(1);
    }
    else{
        ui->pushButton->setDisabled(1);
        ui->pushButton_2->setDisabled(1);
        QMessageBox::information(this, "提示","你选择CSV无效，请重新选择！");
    }

}

