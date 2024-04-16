#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget_teamInfo->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);

    //Dummy teams for testing purposes
    QMap<QString, double> s;
    //_teams.insert("First team", Team("First Team", "adfsdfg", 222, "hjhgf", "ertyu", "asdcxz", 1222, 11123, "hgfd", "zzc", s));
    //_teams.insert("HII", Team("HHH", "SDSD", 123, "F", "f", "a", 12, 2, "g", "2", s));

    //Add all team names to the UI list
    //for (auto i = _teams.cbegin(), end = _teams.cend(); i != end; ++i)
        //ui->listWidget_teamList->addItem(i.key());

    //Map myMap;
    _teams.insert(Team("ZZZ", "52225", 123, "dddF", "faaa", "a22i8uyt5r4ewdfgh", 12, 2, "g", "2v cx!!!ax", s));
    _teams.insert(Team("First Team", "adfsdfg", 222, "hjhgf", "ertyu", "asdcxz", 1222, 11123, "hgfd", "zzc", s));
    _teams.insert(Team("HHH", "SDSD", 123, "F", "f", "a", 12, 2, "g", "2", s));
    _teams.insert(Team("AAA", "55555", 123, "ddddddF", "faaaaa", "a22222", 12, 2, "ghhgfds", "2v cxx", s));

    for (int i = 0; i < _teams.size(); i++)
        ui->listWidget_teamList->addItem(_teams(i).teamName());
}

MainWindow::~MainWindow()
{
    delete ui;
}

//-----------------------------BEGINNING OF GO TO SLOT FUNCTIONS------------------------------------

//Update display info when a team is clicked
void MainWindow::on_listWidget_teamList_currentTextChanged(const QString &currentText)
{
    //If the user deselects a team
    if (currentText == "")
    {
        //ui->tableWidget_teamInfo->clear();
        return;
    }
    ui->tableWidget_teamInfo->setItem(0, 0, new QTableWidgetItem(_teams[currentText].teamName()));
    ui->tableWidget_teamInfo->setItem(0, 1, new QTableWidgetItem(_teams[currentText].stadiumName()));
    ui->tableWidget_teamInfo->setItem(0, 2, new QTableWidgetItem(QString::number(_teams[currentText].seatingCapacity())));
    ui->tableWidget_teamInfo->setItem(0, 3, new QTableWidgetItem(_teams[currentText].location()));
    ui->tableWidget_teamInfo->setItem(0, 4, new QTableWidgetItem(_teams[currentText].playingSurface()));
    ui->tableWidget_teamInfo->setItem(0, 5, new QTableWidgetItem(_teams[currentText].league()));
    ui->tableWidget_teamInfo->setItem(0, 6, new QTableWidgetItem(QString::number(_teams[currentText].dateOpened())));
    ui->tableWidget_teamInfo->setItem(0, 7, new QTableWidgetItem(QString::number(_teams[currentText].distanceToField())));
    ui->tableWidget_teamInfo->setItem(0, 8, new QTableWidgetItem(_teams[currentText].typology()));
    ui->tableWidget_teamInfo->setItem(0, 9, new QTableWidgetItem(_teams[currentText].rooftype()));
}

//Sorting box changed
void MainWindow::on_comboBox_sort_currentTextChanged(const QString &arg1)
{
    ui->listWidget_teamList->clear();
    _teams.sort(teamNameh);
    for (int i = 0; i < _teams.size(); i++)
        ui->listWidget_teamList->addItem(_teams(i).teamName());
}

