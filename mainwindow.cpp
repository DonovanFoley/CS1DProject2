#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    loginDialog = new LoginDialog;
    ui->tableWidget_teamInfo->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);

    //Set up actions
    loginAct = new QAction("Login to Admin", this);

    //Set up toolbar
    loginMenu = menuBar()->addMenu("&Login");
    loginMenu->addAction(loginAct);
    connect(loginAct, &QAction::triggered, this, &MainWindow::login);

    //Dummy teams for testing purposes
    QMap<QString, double> s;
    s.insert("Souvenir item", 15.59);
    s.insert("Second Souvenir item", 10.05);

    _teams.insert(Team("Arizona Diamondbacks", "Chase Field", 48686, "Phoenix, Arizona", "Grass", "National", 1998, 407, "Retro Modern", "Retractable", s));
    s.insert("Third souvenir item", 6.00);
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

void MainWindow::login()
{
    loginDialog->exec();
    if (loginDialog->ok() && loginDialog->password() == "*Saddleback")
    {
        ui->pushButton_add->setEnabled(true);
        ui->pushButton_edit->setEnabled(true);
        ui->pushButton_delete->setEnabled(true);
        ui->tableWidget_teamInfo->setEditTriggers(QAbstractItemView::DoubleClicked);
    }
    loginDialog->reset();
}

//-----------------------------BEGINNING OF GO TO SLOT FUNCTIONS------------------------------------

//Update display info when a team is clicked
/*
void MainWindow::on_listWidget_teamList_currentTextChanged(const QString &currentText)
{
    currentTeam = &_teams[currentText];
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

    //Souvenir list
    ui->listWidget_souvenirList->clear();
    QMapIterator<QString, double> it(_teams[currentText].souvenirList());

    while (it.hasNext()) {
        it.next();
        QString souvenir;
        souvenir = it.key() + " - $" + QString::number(it.value(), 'f', 2);
        ui->listWidget_souvenirList->addItem(souvenir);
    }
}*/


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

    onlyAmerican = (arg1 == "American League");
    onlyNational = (arg1 == "National League");
    onlyOpenRoof = (arg1 == "Open Roof");
    onlyGreatestDistance = (arg1 == "Greatest Distance");
    onlySmallestDistance = (arg1 == "Smallest Distance");

    displayTeamNames();
}


void MainWindow::on_listWidget_teamList_itemClicked(QListWidgetItem *item)
{
    //If the user deselects a team
    if (item->text() == "")
    {
        //ui->tableWidget_teamInfo->clear();
        return;
    }

    //Set the currentTeamIndex to the index of the team the user selected
    for (int i = 0; i < _teams.size(); i++)
    {
        if (_teams(i).teamName() == item->text())
        {
            currentTeamIndex = i;
            break;
        }
    }

    //_teams(currentTeamIndex).setTeamName("Hi");
    ui->tableWidget_teamInfo->setItem(0, 0, new QTableWidgetItem(_teams[item->text()].teamName()));
    ui->tableWidget_teamInfo->setItem(0, 1, new QTableWidgetItem(_teams[item->text()].stadiumName()));
    ui->tableWidget_teamInfo->setItem(0, 2, new QTableWidgetItem(QString::number(_teams[item->text()].seatingCapacity())));
    ui->tableWidget_teamInfo->setItem(0, 3, new QTableWidgetItem(_teams[item->text()].location()));
    ui->tableWidget_teamInfo->setItem(0, 4, new QTableWidgetItem(_teams[item->text()].playingSurface()));
    ui->tableWidget_teamInfo->setItem(0, 5, new QTableWidgetItem(_teams[item->text()].league()));
    ui->tableWidget_teamInfo->setItem(0, 6, new QTableWidgetItem(QString::number(_teams[item->text()].dateOpened())));
    ui->tableWidget_teamInfo->setItem(0, 7, new QTableWidgetItem(QString::number(_teams[item->text()].distanceToField())));
    ui->tableWidget_teamInfo->setItem(0, 8, new QTableWidgetItem(_teams[item->text()].typology()));
    ui->tableWidget_teamInfo->setItem(0, 9, new QTableWidgetItem(_teams[item->text()].rooftype()));

    //Souvenir list
    ui->listWidget_souvenirList->clear();
    QMapIterator<QString, double> it(_teams[item->text()].souvenirList());

    while (it.hasNext()) {
        it.next();
        QString souvenir;
        souvenir = it.key() + " - $" + QString::number(it.value(), 'f', 2);
        ui->listWidget_souvenirList->addItem(souvenir);
    }
}


void MainWindow::on_tableWidget_teamInfo_itemChanged(QTableWidgetItem *item)
{
    qDebug("h");
    //currentTeam->setTeamName("Hi");
}

