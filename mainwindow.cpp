#include "mainwindow.h"
#include "ui_mainwindow.h"
//hi
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    loginDialog = new LoginDialog;
    tripDialog = new TripDialog;
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

void MainWindow::displayTeamInfo()
{
    ui->tableWidget_teamInfo->setItem(0, 0, new QTableWidgetItem(currentTeam->teamName()));
    ui->tableWidget_teamInfo->setItem(0, 1, new QTableWidgetItem(currentTeam->stadiumName()));
    ui->tableWidget_teamInfo->setItem(0, 2, new QTableWidgetItem(QString::number(currentTeam->seatingCapacity())));
    ui->tableWidget_teamInfo->setItem(0, 3, new QTableWidgetItem(currentTeam->location()));
    ui->tableWidget_teamInfo->setItem(0, 4, new QTableWidgetItem(currentTeam->playingSurface()));
    ui->tableWidget_teamInfo->setItem(0, 5, new QTableWidgetItem(currentTeam->league()));
    ui->tableWidget_teamInfo->setItem(0, 6, new QTableWidgetItem(QString::number(currentTeam->dateOpened())));
    ui->tableWidget_teamInfo->setItem(0, 7, new QTableWidgetItem(QString::number(currentTeam->distanceToField())));
    ui->tableWidget_teamInfo->setItem(0, 8, new QTableWidgetItem(currentTeam->typology()));
    ui->tableWidget_teamInfo->setItem(0, 9, new QTableWidgetItem(currentTeam->rooftype()));
}

void MainWindow::displaySouvenirInfo()
{
    ui->tableWidget_souvenirInfo->clearContents();
    ui->tableWidget_souvenirInfo->setRowCount(0);
    QMapIterator<QString, double> it(currentTeam->souvenirList());

    while (it.hasNext()) {
        it.next();
        ui->tableWidget_souvenirInfo->insertRow(0);
        QString souvenir = it.key();
        QString price = QString::number(it.value(), 'f', 2);
        ui->tableWidget_souvenirInfo->setItem(0, 0, new QTableWidgetItem(souvenir));
        ui->tableWidget_souvenirInfo->setItem(0, 1, new QTableWidgetItem(price));
    }
}

void MainWindow::displayTripNames()
{
    QString names = "";
    for (int i = 0; i < _teamsInTrip.size(); i++)
    {
        names.append("->");
        names.append(_teamsInTrip(i)->teamName());
    }
    ui->label_tripNames->setText(names);
}

void MainWindow::login()
{
    loginDialog->exec();
    if (loginDialog->ok() && loginDialog->password() == "*Saddleback")
    {
        QMessageBox::information(this, "Admin", "Logged In Successfully");
        ui->pushButton_add->setEnabled(currentTeam != nullptr);
        ui->tableWidget_teamInfo->setEditTriggers(QAbstractItemView::DoubleClicked);
        ui->tableWidget_souvenirInfo->setEditTriggers(QAbstractItemView::DoubleClicked);
        loggedIn = true;
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

    displayTeamInfo();
    displaySouvenirInfo();

    editFlag = true;
    ui->pushButton_delete->setEnabled(false);
    ui->pushButton_add->setEnabled(loggedIn);
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

//Edit team info upon changing the table
void MainWindow::on_tableWidget_teamInfo_itemChanged()
{
    if (!editFlag) return;

    //Check for numbers in string properties (invalid input)
    if (ui->tableWidget_teamInfo->item(2,0)->text().toInt() == 0 ||
        ui->tableWidget_teamInfo->item(6,0)->text().toInt() == 0 ||
        ui->tableWidget_teamInfo->item(7,0)->text().toInt() == 0 ||
        ui->tableWidget_teamInfo->item(0,0)->text().toInt() != 0 ||
        ui->tableWidget_teamInfo->item(1,0)->text().toInt() != 0 ||
        ui->tableWidget_teamInfo->item(3,0)->text().toInt() != 0 ||
        ui->tableWidget_teamInfo->item(4,0)->text().toInt() != 0 ||
        ui->tableWidget_teamInfo->item(5,0)->text().toInt() != 0 ||
        ui->tableWidget_teamInfo->item(8,0)->text().toInt() != 0 ||
        ui->tableWidget_teamInfo->item(9,0)->text().toInt() != 0
        )
    {
        editFlag = false;
        displayTeamInfo();
        editFlag = true;
        QMessageBox::warning(this, "Invalid Input", "Invalid Input");
        return;
    }

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

//Edit team object info upon changing the souvenir table
void MainWindow::on_tableWidget_souvenirInfo_itemChanged()
{
    bool ok;
    if (!editFlag) return;

    QMap<QString, double> souvenirList;
    //Check for invalid user input

    for (int i = 0; i < ui->tableWidget_souvenirInfo->rowCount(); i++)
    {
        ui->tableWidget_souvenirInfo->item(i, 1)->text().toDouble(&ok);
        if (ui->tableWidget_souvenirInfo->item(i, 0)->text().toInt() != 0 || !ok)
        {
            editFlag = false;
            displaySouvenirInfo();
            editFlag = true;
            QMessageBox::warning(this, "Invalid Input", "Invalid Input");
            return;
        }
    }

    for (int i = 0; i < ui->tableWidget_souvenirInfo->rowCount(); i++)
    {
        souvenirList[ui->tableWidget_souvenirInfo->item(i, 0)->text()] = ui->tableWidget_souvenirInfo->item(i, 1)->text().toDouble();
    }

    currentTeam->setSouvenirList(souvenirList);
}

//Add souvenir button
void MainWindow::on_pushButton_add_clicked()
{
    editFlag = false;
    ui->tableWidget_souvenirInfo->insertRow(0);
    ui->tableWidget_souvenirInfo->setItem(0, 0, new QTableWidgetItem("Item"));
    editFlag = true;
    ui->tableWidget_souvenirInfo->setItem(0, 1, new QTableWidgetItem("0.00"));
}

//Delete souvenir button
void MainWindow::on_pushButton_delete_clicked()
{
    bool userClickedName = true;
    editFlag = false;

    QMap<QString, double> map = currentTeam->souvenirList();

    //If the user clicked delete on the price, search the map until we find the element with the price
    QMapIterator<QString, double> it2(currentTeam->souvenirList());
    while (it2.hasNext())
    {
        it2.next();
        if (it2.value() == currentSouvenirPrice)
        {
            map.remove(it2.key());
            userClickedName = false;
            break;
        }
    }

    //If the user clicked delete on the key, delete the element with that key
    if (userClickedName) map.remove(currentSouvenirName);

    currentTeam->setSouvenirList(map);

    ui->tableWidget_souvenirInfo->clearContents();
    ui->tableWidget_souvenirInfo->setRowCount(0);
    QMapIterator<QString, double> it(currentTeam->souvenirList());

    //Update the souvenir list so that the deleted souvenir is no longer displayed
    while (it.hasNext())
    {
        it.next();
        ui->tableWidget_souvenirInfo->insertRow(0);
        QString souvenir = it.key();
        QString price = QString::number(it.value(), 'f', 2);
        ui->tableWidget_souvenirInfo->setItem(0, 0, new QTableWidgetItem(souvenir));
        ui->tableWidget_souvenirInfo->setItem(0, 1, new QTableWidgetItem(price));
    }

    editFlag = true;
    ui->pushButton_delete->setEnabled(false);
}

//Clicked on a souvenir (Helper function for delete)
void MainWindow::on_tableWidget_souvenirInfo_itemClicked(QTableWidgetItem *item)
{
    currentSouvenirName = item->text();
    currentSouvenirPrice = item->text().toDouble();
    ui->pushButton_delete->setEnabled(loggedIn);
}

//Clicked on trip "go" button
void MainWindow::on_pushButton_go_clicked()
{
    tripDialog->exec();
}

//Checked or unchecked "Add To Trip" button
void MainWindow::on_checkBox_addToTrip_clicked(bool checked)
{
    if (checked)
    {
        currentTeam->toggleIsInTrip(true);
        _teamsInTrip.insert(*currentTeam);
    }
    else
    {
        currentTeam->toggleIsInTrip(false);
        _teamsInTrip.remove(*currentTeam);
    }

    displayTripNames();
}

