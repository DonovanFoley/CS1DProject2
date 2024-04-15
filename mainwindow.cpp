#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget_teamInfo->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);

    Team test;

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::displayTeamInfo()
{

}
