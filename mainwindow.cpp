#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "iostream"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget_teamInfo->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);

    //Dummy teams for testing purposes
    QMap<QString, double> s;

    _teams.insert(Team("Arizona Diamondbacks", "Chase Field", 48686, "Phoenix, Arizona", "Grass", "National", 1998, 407, "Retro Modern", "Retractable", s));
    _teams.insert(Team("Atlanta Braves", "SunTrust Park", 41149, "Cumberland, Georgia", "Grass", "National", 2017, 400, "Retro Modern", "Open", s));
    _teams.insert(Team("Baltimore Orioles", "Oriole Park at Camden Yards", 45971, "Baltimore, Maryland", "Grass", "American", 1992, 410, "Retro Classic", "Open", s));
    _teams.insert(Team("Chicago Cubs", "Wrigley Field", 41268, "Chicago, Illinois", "Grass", "National", 1914, 400, "Jewel Box", "Open", s));

    propertyMap["Team Name"] = teamName;
    propertyMap["Stadium Name"] = stadiumName;
    propertyMap["Park Typology"] = typology;
    propertyMap["Date Opened"] = dateOpened;
    propertyMap["Seating Capacity"] = seatingCapacity;

    displayTeamNames();
}

MainWindow::~MainWindow()
{
    delete ui;
}

// void testSouvenirPurchaseWindow() {

// }

void MainWindow::displayTeamNames()
{
    int max = INT_MIN;
    int min = INT_MAX;

    for (int i = 0; i < _teams.size(); i++)
    {
        if (onlyAmerican)
        {
            if (_teams(i).league() == "American") ui->listWidget_teamList->addItem(_teams(i).teamName());
        }
        else if (onlyNational)
        {
            if (_teams(i).league() == "National") ui->listWidget_teamList->addItem(_teams(i).teamName());
        }
        else if (onlyOpenRoof)
        {
            if (_teams(i).rooftype() == "Open") ui->listWidget_teamList->addItem(_teams(i).teamName());
        }
        else if (onlyGreatestDistance)
        {
            if (_teams(i).distanceToField() > max)
            {
                ui->listWidget_teamList->clear();
                ui->listWidget_teamList->addItem(_teams(i).teamName());
                max = _teams(i).distanceToField();
            }
        }
        else if (onlySmallestDistance)
        {
            if (_teams(i).distanceToField() < min)
            {
                ui->listWidget_teamList->clear();
                ui->listWidget_teamList->addItem(_teams(i).teamName());
                min = _teams(i).distanceToField();
            }
        }
        else
        {
            ui->listWidget_teamList->addItem(_teams(i).teamName());
        }
    }
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
    _teams.sort(propertyMap[arg1]);

    displayTeamNames();
}

//Exclusion box changed
void MainWindow::on_comboBox_exclude_currentTextChanged(const QString &arg1)
{
    ui->listWidget_teamList->clear();

    onlyAmerican = false;
    onlyNational = false;
    onlyOpenRoof = false;
    onlyGreatestDistance = false;
    onlySmallestDistance = false;

    onlyAmerican = (arg1 == "American League");
    onlyNational = (arg1 == "National League");
    onlyOpenRoof = (arg1 == "Open Roof");
    onlyGreatestDistance = (arg1 == "Greatest Distance");
    onlySmallestDistance = (arg1 == "Smallest Distance");

    displayTeamNames();
}

