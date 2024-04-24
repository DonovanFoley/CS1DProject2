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

    /*
    //Dummy teams for testing purposes
    QMap<QString, double> s;
    s.insert("Souvenir item", 15.59);
    s.insert("Second Souvenir item", 10.05);

    _teams.insert(Team("Arizona Diamondbacks", "Chase Field", 48686, "Phoenix, Arizona", "Grass", "National", 1998, 407, "Retro Modern", "Retractable", s));
    s.clear();
    s.insert("Third souvenir item", 6.00);
    s.insert("A Souvenir", 9.99);
    _teams.insert(Team("Atlanta Braves", "SunTrust Park", 41149, "Cumberland, Georgia", "Grass", "National", 2017, 400, "Retro Modern", "Open", s));
    s.clear();
    s.insert("First", 6.55);
    s.insert("Second", 1.11);
    _teams.insert(Team("Baltimore Orioles", "Oriole Park at Camden Yards", 45971, "Baltimore, Maryland", "Grass", "American", 1992, 410, "Retro Classic", "Open", s));
    _teams.insert(Team("Chicago Cubs", "Wrigley Field", 41268, "Chicago, Illinois", "Grass", "National", 1914, 400, "Jewel Box", "Open", s)); */

    StadiumsDB db("stadiums.db");
    db.populate_teams(_teams);
    db.populate_souvenirs(_teams);

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
            if (_teams(i)->league() == "American") ui->listWidget_teamList->addItem(_teams(i)->teamName());
        }
        else if (onlyNational)
        {
            if (_teams(i)->league() == "National") ui->listWidget_teamList->addItem(_teams(i)->teamName());
        }
        else if (onlyOpenRoof)
        {
            if (_teams(i)->rooftype() == "Open") ui->listWidget_teamList->addItem(_teams(i)->teamName());
        }
        else if (onlyGreatestDistance)
        {
            if (_teams(i)->distanceToField() > max)
            {
                ui->listWidget_teamList->clear();
                ui->listWidget_teamList->addItem(_teams(i)->teamName());
                max = _teams(i)->distanceToField();
            }
        }
        else if (onlySmallestDistance)
        {
            if (_teams(i)->distanceToField() < min)
            {
                ui->listWidget_teamList->clear();
                ui->listWidget_teamList->addItem(_teams(i)->teamName());
                min = _teams(i)->distanceToField();
            }
        }
        else
        {
            ui->listWidget_teamList->addItem(_teams(i)->teamName());
        }
    }
}

void MainWindow::login()
{
    loginDialog->exec();
    if (loginDialog->ok() && loginDialog->password() == "*Saddleback")
    {
        //ui->pushButton_add->setEnabled(true);
        //ui->pushButton_edit->setEnabled(true);
        //ui->pushButton_delete->setEnabled(true);
        ui->tableWidget_teamInfo->setEditTriggers(QAbstractItemView::DoubleClicked);
        ui->tableWidget_souvenirInfo->setEditTriggers(QAbstractItemView::DoubleClicked);
    }
    loginDialog->reset();
}

//-----------------------------BEGINNING OF GO TO SLOT FUNCTIONS------------------------------------

//Update display info when a team is clicked
void MainWindow::on_listWidget_teamList_itemClicked(QListWidgetItem *item)
{
    editFlag = false;
    currentTeam = _teams[item->text()];
    //If the user deselects a team
    if (item->text() == "")
    {
        //ui->tableWidget_teamInfo->clear();
        return;
    }

    ui->tableWidget_teamInfo->setItem(0, 0, new QTableWidgetItem(_teams[item->text()]->teamName()));
    ui->tableWidget_teamInfo->setItem(0, 1, new QTableWidgetItem(_teams[item->text()]->stadiumName()));
    ui->tableWidget_teamInfo->setItem(0, 2, new QTableWidgetItem(QString::number(_teams[item->text()]->seatingCapacity())));
    ui->tableWidget_teamInfo->setItem(0, 3, new QTableWidgetItem(_teams[item->text()]->location()));
    ui->tableWidget_teamInfo->setItem(0, 4, new QTableWidgetItem(_teams[item->text()]->playingSurface()));
    ui->tableWidget_teamInfo->setItem(0, 5, new QTableWidgetItem(_teams[item->text()]->league()));
    ui->tableWidget_teamInfo->setItem(0, 6, new QTableWidgetItem(QString::number(_teams[item->text()]->dateOpened())));
    ui->tableWidget_teamInfo->setItem(0, 7, new QTableWidgetItem(QString::number(_teams[item->text()]->distanceToField())));
    ui->tableWidget_teamInfo->setItem(0, 8, new QTableWidgetItem(_teams[item->text()]->typology()));
    ui->tableWidget_teamInfo->setItem(0, 9, new QTableWidgetItem(_teams[item->text()]->rooftype()));


    //Souvenir list
    ui->tableWidget_souvenirInfo->clearContents();
    ui->tableWidget_souvenirInfo->setRowCount(0);
    QMapIterator<QString, double> it(_teams[item->text()]->souvenirList());

    while (it.hasNext()) {
        it.next();
        ui->tableWidget_souvenirInfo->insertRow(0);
        QString souvenir = it.key();
        QString price = QString::number(it.value(), 'f', 2);
        ui->tableWidget_souvenirInfo->setItem(0, 0, new QTableWidgetItem(souvenir));
        ui->tableWidget_souvenirInfo->setItem(0, 1, new QTableWidgetItem(price));
    }

    editFlag = true;
}

//Sorting box changed
void MainWindow::on_comboBox_sort_currentTextChanged(const QString &arg1)
{
    ui->listWidget_teamList->clear();
    _teams.sort(propertyMap[arg1]);

    displayTeamNames();
}

//Exclusion box changed_
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

//Edit team info upon changing the table table
void MainWindow::on_tableWidget_teamInfo_itemChanged()
{
    if (!editFlag) return;

    currentTeam->setTeamName(ui->tableWidget_teamInfo->item(0,0)->text());
    currentTeam->setStadiumName(ui->tableWidget_teamInfo->item(1,0)->text());
    currentTeam->setSeatingCapacity(ui->tableWidget_teamInfo->item(2,0)->text().toInt());
    currentTeam->setLocation(ui->tableWidget_teamInfo->item(3,0)->text());
    currentTeam->setPlayingSurface(ui->tableWidget_teamInfo->item(4,0)->text());
    currentTeam->setLeague(ui->tableWidget_teamInfo->item(5,0)->text());
    currentTeam->setDateOpened(ui->tableWidget_teamInfo->item(6,0)->text().toInt());
    currentTeam->setDistanceToField(ui->tableWidget_teamInfo->item(7,0)->text().toInt());
    currentTeam->setTypology(ui->tableWidget_teamInfo->item(8,0)->text());
    currentTeam->setRooftype(ui->tableWidget_teamInfo->item(9,0)->text());

    //Call the combo box sorting method and then print new team names
    on_comboBox_sort_currentTextChanged(ui->comboBox_sort->currentText());
}

//Edit team info upon changing the souvenir table
void MainWindow::on_tableWidget_souvenirInfo_itemChanged()
{
    if (!editFlag) return;

    QMap<QString, double> souvenirList;

    for (int i = 0; i < ui->tableWidget_souvenirInfo->rowCount(); i++)
    {
        souvenirList[ui->tableWidget_souvenirInfo->item(i, 0)->text()] = ui->tableWidget_souvenirInfo->item(i, 1)->text().toDouble();
    }

    currentTeam->setSouvenirList(souvenirList);
}

