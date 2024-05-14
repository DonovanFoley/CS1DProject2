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
    // souvenirPurchaseDialog = new SouvenirPurchase;

    ui->tableWidget_teamInfo->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);

    //Set up actions
    loginAct = new QAction("Login to Admin", this);

    openDBAct = new QAction("Open Databae...", this);

    DFSAct = new QAction("Perform DFS", this);
    BFSAct = new QAction("Perform BFS", this);
    marlinsParkAct = new QAction("Marlins Park Preset", this);

    //Set up toolbar
    loginMenu = menuBar()->addMenu("&Login");
    loginMenu->addAction(loginAct);
    connect(loginAct, &QAction::triggered, this, &MainWindow::login);

    fileMenu = menuBar()->addMenu("&File");
    fileMenu->addAction(openDBAct);
    connect(openDBAct, &QAction::triggered, this, &MainWindow::choose_file);

    presetMenu = menuBar()->addMenu("&Presets");
    presetMenu->addAction(DFSAct);
    presetMenu->addAction(BFSAct);
    presetMenu->addAction(marlinsParkAct);
    connect(DFSAct, &QAction::triggered, this, &MainWindow::DFS);
    connect(BFSAct, &QAction::triggered, this, &MainWindow::BFS);
    connect(marlinsParkAct, &QAction::triggered, this, &MainWindow::marlinsPark);

    //Dummy teams for testing purposes
    QMap<QString, double> s;
    s.insert("Souvenir item", 15.59);
    s.insert("Second Souvenir item", 10.05);

    if(std::filesystem::exists("stadiums.db"))
    {
      database.set_file("stadiums.db");
      database.populate_teams(_teams);
      database.populate_souvenirs(_teams);
      graph = database.make_graph(_teams);
    }

    propertyMap["Team Name"] = teamName;
    propertyMap["Stadium Name"] = stadiumName;
    propertyMap["Park Typology"] = typology;
    propertyMap["Date Opened"] = dateOpened;
    propertyMap["Seating Capacity"] = seatingCapacity;

    _teams.sort(teamName);
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

    for (int i = 0; i < _teams.size(); i++) {
        if (onlyAmerican) {
            if (_teams(i)->league() == "American")
                ui->listWidget_teamList->addItem(_teams(i)->teamName());
        } else if (onlyNational) {
            if (_teams(i)->league() == "National")
                ui->listWidget_teamList->addItem(_teams(i)->teamName());
        } else if (onlyOpenRoof) {
            if (_teams(i)->rooftype() == "Open")
                ui->listWidget_teamList->addItem(_teams(i)->teamName());
        } else if (onlyGreatestDistance) {
            if (_teams(i)->distanceToField() > max) {
                ui->listWidget_teamList->clear();
                ui->listWidget_teamList->addItem(_teams(i)->teamName());
                max = _teams(i)->distanceToField();
            }
        } else if (onlySmallestDistance) {
            if (_teams(i)->distanceToField() < min) {
                ui->listWidget_teamList->clear();
                ui->listWidget_teamList->addItem(_teams(i)->teamName());
                min = _teams(i)->distanceToField();
            }
        } else {
            ui->listWidget_teamList->addItem(_teams(i)->teamName());
        }
    }
}

void MainWindow::displayTeamInfo()
{
    ui->tableWidget_teamInfo->setItem(0, 0, new QTableWidgetItem(currentTeam->teamName()));
    ui->tableWidget_teamInfo->setItem(0, 1, new QTableWidgetItem(currentTeam->stadiumName()));
    ui->tableWidget_teamInfo
        ->setItem(0, 2, new QTableWidgetItem(QString::number(currentTeam->seatingCapacity())));
    ui->tableWidget_teamInfo->setItem(0, 3, new QTableWidgetItem(currentTeam->location()));
    ui->tableWidget_teamInfo->setItem(0, 4, new QTableWidgetItem(currentTeam->playingSurface()));
    ui->tableWidget_teamInfo->setItem(0, 5, new QTableWidgetItem(currentTeam->league()));
    ui->tableWidget_teamInfo
        ->setItem(0, 6, new QTableWidgetItem(QString::number(currentTeam->dateOpened())));
    ui->tableWidget_teamInfo
        ->setItem(0, 7, new QTableWidgetItem(QString::number(currentTeam->distanceToField())));
    ui->tableWidget_teamInfo->setItem(0, 8, new QTableWidgetItem(currentTeam->typology()));
    ui->tableWidget_teamInfo->setItem(0, 9, new QTableWidgetItem(currentTeam->rooftype()));
}

void MainWindow::displaySouvenirInfo()
{
    if(!currentTeam) return;

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
    //If there are no teams in the trip, immediately exit
    if (_teamsInTrip.size() == 0) {
        ui->pushButton_go->setEnabled(false);
        ui->label_tripNames->clear();
        return;
    }
    ui->pushButton_go->setEnabled(true);

    QString names = "";
    names.append(_teamsInTrip[0].stadiumName());
    for (int i = 1; i < _teamsInTrip.size(); i++) {
        names.append(" → ");
        names.append(_teamsInTrip[i].stadiumName());
    }
    ui->label_tripNames->setText(names);
}

void MainWindow::login()
{
    loginDialog->exec();
    if (loginDialog->ok() && loginDialog->password() == "*Saddleback") {
        QMessageBox::information(this, "Admin", "Logged In Successfully");
        ui->pushButton_add->setEnabled(currentTeam != nullptr);
        ui->tableWidget_teamInfo->setEditTriggers(QAbstractItemView::DoubleClicked);
        ui->tableWidget_souvenirInfo->setEditTriggers(QAbstractItemView::DoubleClicked);
        loggedIn = true;
    }
    loginDialog->reset();
}

void MainWindow::choose_file() {
  QString filename = QFileDialog::getOpenFileName(this, "Open Database",
                                                  "/home",
                                                  "SQLite files (*.db *.sqlite *.sqlite3)");
  database.set_file(filename);
  database.populate_teams(_teams);
  database.populate_souvenirs(_teams);

  displayTeamNames();
  //displaySouvenirInfo();
}

//Djikstras from Dodger Stadium to one other selected team (instruction #1)
void MainWindow::djikstras()
{
    //Team *dodgers = _teams["Los Angeles Dodgers"];
    int distance = 0;
    QString text;
    text.append("Los Angeles Dodgers -> ");
    //graph.dijkstra(currentTeam->id(), distance);
    //qDebug() << distance;//
    text.append(currentTeam->teamName() + " (" + QString::number(distance) + ")");
    ui->label_tripNames->setText(text);

    //Reset
    for (int i = 0; i < _teams.size(); i++) _teams(i)->toggleIsInTrip(false);
    _teamsInTrip.clear();
    ui->checkBox_addToTrip->setChecked(false);
}

void MainWindow::DFS()
{
    StadiumManager stadiumManager(graph, _teams);
    stadiumManager.performDFS(this);
}

void MainWindow::BFS()
{
    StadiumManager stadiumManager(graph, _teams);
    stadiumManager.performBFS(this);
}

void MainWindow::marlinsPark()
{
    _teamsInTrip.clear();
    std::unordered_map<int, double> shortestPaths;
    std::unordered_map<int, bool> visitedStadiums;
    double totalDistance = 0;
    QVector<int> vertices;
    // Assuming '15' is Marlins Park
    graph.visitAllStadiumsRecursive(15, visitedStadiums, shortestPaths, totalDistance, graph.getGraph(), vertices);
    std::cout << "Minimum distance to visit all stadiums starting from Marlins Park: " << totalDistance << std::endl;
    _teamsInTrip.append(*_teams["Miami Marlins"]);
    for (int i = 0; i < vertices.size(); i++)
    {
        for(int x = 0; x < _teams.size(); x++)
        {
            if (_teams(x)->id() == vertices[i])
            {
                _teamsInTrip.append(*_teams(x));
            }
        }
    }
    displayTripNames();

}

//-----------------------------BEGINNING OF GO TO SLOT FUNCTIONS------------------------------------

//Update display info when a team is clicked
void MainWindow::on_listWidget_teamList_itemClicked(QListWidgetItem *item)
{
    editFlag = false;
    currentTeam = _teams[item->text()];
    // qDebug("Current team has been changed");
    //If the user deselects a team
    if (item->text() == "") {
        //ui->tableWidget_teamInfo->clear();
        return;
    }

    ui->checkBox_addToTrip->setEnabled(true);
    ui->checkBox_addToTrip->setChecked(currentTeam->isInTrip());
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
    if (currentTeam != nullptr) {
        for (int i = 0; i < ui->listWidget_teamList->count(); i++) {
            if (ui->listWidget_teamList->item(i)->text()
                == ui->tableWidget_teamInfo->item(0, 0)->text()) {
                ui->listWidget_teamList->setCurrentRow(i);
                currentTeam = _teams[ui->listWidget_teamList->item(i)->text()];
            }
        }
    }
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
    if (currentTeam != nullptr) {
        for (int i = 0; i < ui->listWidget_teamList->count(); i++) {
            if (ui->listWidget_teamList->item(i)->text()
                == ui->tableWidget_teamInfo->item(0, 0)->text()) {
                ui->listWidget_teamList->setCurrentRow(i);
                currentTeam = _teams[ui->listWidget_teamList->item(i)->text()];
            }
        }
    }
}

//Edit team info upon changing the table
void MainWindow::on_tableWidget_teamInfo_itemChanged()
{
    if (!editFlag)
        return;

    //Check for numbers in string properties (invalid input)
    if (ui->tableWidget_teamInfo->item(2, 0)->text().toInt() == 0
        || ui->tableWidget_teamInfo->item(6, 0)->text().toInt() == 0
        || ui->tableWidget_teamInfo->item(7, 0)->text().toInt() == 0
        || ui->tableWidget_teamInfo->item(0, 0)->text().toInt() != 0
        || ui->tableWidget_teamInfo->item(1, 0)->text().toInt() != 0
        || ui->tableWidget_teamInfo->item(3, 0)->text().toInt() != 0
        || ui->tableWidget_teamInfo->item(4, 0)->text().toInt() != 0
        || ui->tableWidget_teamInfo->item(5, 0)->text().toInt() != 0
        || ui->tableWidget_teamInfo->item(8, 0)->text().toInt() != 0
        || ui->tableWidget_teamInfo->item(9, 0)->text().toInt() != 0) {
        editFlag = false;
        displayTeamInfo();
        editFlag = true;
        QMessageBox::warning(this, "Invalid Input", "Invalid Input");
        return;
    }

    currentTeam->setTeamName(ui->tableWidget_teamInfo->item(0, 0)->text());
    currentTeam->setStadiumName(ui->tableWidget_teamInfo->item(1, 0)->text());
    currentTeam->setSeatingCapacity(ui->tableWidget_teamInfo->item(2, 0)->text().toInt());
    currentTeam->setLocation(ui->tableWidget_teamInfo->item(3, 0)->text());
    currentTeam->setPlayingSurface(ui->tableWidget_teamInfo->item(4, 0)->text());
    currentTeam->setLeague(ui->tableWidget_teamInfo->item(5, 0)->text());
    currentTeam->setDateOpened(ui->tableWidget_teamInfo->item(6, 0)->text().toInt());
    currentTeam->setDistanceToField(ui->tableWidget_teamInfo->item(7, 0)->text().toInt());
    currentTeam->setTypology(ui->tableWidget_teamInfo->item(8, 0)->text());
    currentTeam->setRooftype(ui->tableWidget_teamInfo->item(9, 0)->text());

    //Call the combo box sorting method and then print new team names
    on_comboBox_sort_currentTextChanged(ui->comboBox_sort->currentText());

    //Update trip teams in real time if the data is changed after they've been added
    if (currentTeam->isInTrip()) {
        for (int i = 0; i < _teamsInTrip.size(); i++) {
            if (_teamsInTrip[i].id() == currentTeam->id()) {
                _teamsInTrip[i] = *currentTeam;
            }
        }
    }
    displayTripNames
        ();
}

//Edit team object info upon changing the souvenir table
void MainWindow::on_tableWidget_souvenirInfo_itemChanged()
{
    bool ok;
    if (!editFlag)
        return;

    QMap<QString, double> souvenirList;
    //Check for invalid user input

    for (int i = 0; i < ui->tableWidget_souvenirInfo->rowCount(); i++) {
        ui->tableWidget_souvenirInfo->item(i, 1)->text().toDouble(&ok);
        if (ui->tableWidget_souvenirInfo->item(i, 0)->text().toInt() != 0 || !ok) {
            editFlag = false;
            displaySouvenirInfo();
            editFlag = true;
            QMessageBox::warning(this, "Invalid Input", "Invalid Input");
            return;
        }
    }

    for (int i = 0; i < ui->tableWidget_souvenirInfo->rowCount(); i++) {
        souvenirList[ui->tableWidget_souvenirInfo->item(i, 0)->text()]
            = ui->tableWidget_souvenirInfo->item(i, 1)->text().toDouble();
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

//Delete souvenir buttons
void MainWindow::on_pushButton_delete_clicked()
{
    bool userClickedName = true;
    editFlag = false;

    QMap<QString, double> map = currentTeam->souvenirList();

    //If the user clicked delete on the price, search the map until we find the element with the price
    QMapIterator<QString, double> it2(currentTeam->souvenirList());
    while (it2.hasNext()) {
        it2.next();
        if (it2.value() == currentSouvenirPrice) {
            map.remove(it2.key());
            userClickedName = false;
            break;
        }
    }

    //If the user clicked delete on the key, delete the element with that key
    if (userClickedName)
        map.remove(currentSouvenirName);

    currentTeam->setSouvenirList(map);

    ui->tableWidget_souvenirInfo->clearContents();
    ui->tableWidget_souvenirInfo->setRowCount(0);
    QMapIterator<QString, double> it(currentTeam->souvenirList());

    //Update the souvenir list so that the deleted souvenir is no longer displayed
    while (it.hasNext()) {
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
    //if (_teamsInTrip.size() == 0) return;

    SouvenirPurchase *souvenirPurchaseDialog = new SouvenirPurchase;

    souvenirPurchaseDialog->getTeams(_teamsInTrip);
    souvenirPurchaseDialog->exec();

    delete souvenirPurchaseDialog;

    // commented out by celeste:
    // tripDialog->getTeams(_teamsInTrip);
    // tripDialog->exec();
}

//Checked or unchecked "Add To Trip" button
void MainWindow::on_checkBox_addToTrip_clicked(bool checked)
{
    double totalDistance = 0;
    //If the user is adding team to the trip
    if (checked)
    {
        currentTeam->toggleIsInTrip(true);
        _teamsInTrip.append(*currentTeam);
    }
    else //If user is removing team from the trip
    {
        currentTeam->toggleIsInTrip(false);
        for (int i = 0; i < _teamsInTrip.size(); i++) {
            if (_teamsInTrip[i].teamName() == currentTeam->teamName()) {
                _teamsInTrip.remove(i);
                break;
            }
        }
    }

    //If we are doing djikstras from Dodger Stadium to one other selected team
    if (_teamsInTrip.size() > 1 && ui->comboBox_tripType->currentText() == "Order Specified Using Shortest Path")
    {
        displayTripNames();

        for (int i = 0; i < _teamsInTrip.size() - 1; i++)
        {
            double distance = 0;
            graph.shortestPath(_teamsInTrip[i].id(), _teamsInTrip[i+1].id(), distance, graph.getGraph());
            totalDistance += distance;
        }
        QString text = ui->label_tripNames->text();
        text.append(" (" + QString::number(totalDistance) + ")");
        ui->label_tripNames->setText(text);
    }
    else
    {
        displayTripNames();
    }

}

//Trip type box changed
void MainWindow::on_comboBox_tripType_currentTextChanged(const QString &arg1)
{
    for (int i = 0; i < _teams.size(); i++)
    {
        _teams(i)->toggleIsInTrip(false);
    }
    ui->checkBox_addToTrip->setChecked(false);
    ui->label_tripNames->clear();
    ui->pushButton_go->setEnabled(false);
    _teamsInTrip.clear();

    //if (arg1 == "One Other Team Starting At Dodger Stadium")
    //{
        //Algorithm 1
    //}
    if (arg1 == "Order Specified Using Shortest Path")
    {
        //Algorithm 2
    }
    else if (arg1 == "All Teams Starting At Marlins Park")
    {
        //Algorithm 3
    }
    else if (arg1 == "Recursively Choose The Closest Team")
    {
        //Algorithm 4
    }
}
