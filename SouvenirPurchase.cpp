#include "SouvenirPurchase.h"
#include "ui_SouvenirPurchase.h"

SouvenirPurchase::SouvenirPurchase(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SouvenirPurchase)
{
    ui->setupUi(this);
}

SouvenirPurchase::~SouvenirPurchase()
{
    delete ui;
}

void SouvenirPurchase::getTeams(QVector<Team> teams)
{
    index = 0;
    _teams = teams;
    displayTeamInfo();
    populateSouvenirTable();
    ui->groupBox_teamInfo->show();
    ui->pushButton_previous->setDisabled(true);
    ui->pushButton_next->setText("Next");
}

void SouvenirPurchase::displayTeamInfo()
{
    ui->label_teamName->setText(_teams[index].teamName());
    ui->label_stadiumName->setText("Stadium Name: " + _teams[index].stadiumName());
    ui->label_seatingCapacity->setText("Seating Capacity: "
                                       + QString::number(_teams[index].seatingCapacity()));
    ui->label_location->setText("Location: " + _teams[index].location());
    ui->label_playingSurface->setText("Playing Surface: " + _teams[index].playingSurface());
    ui->label_league->setText("League: " + _teams[index].league());
    ui->label_dateOpened->setText("Date Opened: " + QString::number(_teams[index].dateOpened()));
    ui->label_distanceToField->setText("Distance To Field: "
                                       + QString::number(_teams[index].distanceToField()));
    ui->label_typology->setText("Typology: " + _teams[index].typology());
    ui->label_rooftype->setText("Rooftype: " + _teams[index].rooftype());
}



/***************************************************************************
 * Puts the souvenirs & prices into the UI table (one Sadium displayed at a time)
 * Allows purchase of 0 to 100 quantity of each souvenir
***************************************************************************/
void SouvenirPurchase::populateSouvenirTable() {
    Team team = _teams[index];

    // Clear any items that may be left in the table
    ui->souvenirAndPriceTable->clear();

    /* Reset the number of rows (will be custom depending on the number of
     *    souvenirs available at that campus) */
    ui->souvenirAndPriceTable->setRowCount(0);

    // Set the Column Headings and Set Equal Spacing for souvenirAndPriceTable
    QStringList headers;
    headers << "Souvenir Name" << "Price ($)" << "Quantity";
    ui->souvenirAndPriceTable->setHorizontalHeaderLabels(headers);
    QHeaderView* souvenirTableHeaders = ui->souvenirAndPriceTable->horizontalHeader();
    souvenirTableHeaders->setSectionResizeMode(QHeaderView::Stretch);

    // Set the Column Headings and Set Equal Spacing for souvenirAndPriceTable
    QStringList headersSummary;
    headersSummary << "Total Quantity" << "Total Cost ($)";
    ui->summaryTable->setHorizontalHeaderLabels(headersSummary);
    QHeaderView* summaryTableHeaders = ui->summaryTable->horizontalHeader();
    summaryTableHeaders->setSectionResizeMode(QHeaderView::Stretch);

    // Retrieve the souvenir list
    QMap<QString, double> souvenirs = team.souvenirList();
    QMap<QString, double>::ConstIterator i;

    for (i = souvenirs.constBegin(); i != souvenirs.constEnd(); ++i) {
        // starting at row 0 and adding a row...
        int currentRow = ui->souvenirAndPriceTable->rowCount();
        ui->souvenirAndPriceTable->insertRow(currentRow);

        // Fill in the souvenir name and price for the current row
        QTableWidgetItem* souvenirNameItem = new QTableWidgetItem(i.key());
        ui->souvenirAndPriceTable->setItem(currentRow, 0, souvenirNameItem);

        QTableWidgetItem* souvenirPriceItem = new QTableWidgetItem(QString::number(i.value(), 'f', 2));
        ui->souvenirAndPriceTable->setItem(currentRow, 1, souvenirPriceItem);

        /* Adds QSpin Boxes so that there is a min/max amount that a user could purchase of each
         * souvenir type.*/
        QSpinBox* quantitySelector = new QSpinBox();
        quantitySelector -> setMinimum(0);
        quantitySelector -> setMaximum(100);
        ui -> souvenirAndPriceTable -> setCellWidget(currentRow, 2, quantitySelector);
    }

}

/***************************************************************************
 * Displays the name of each stadium visited on the trip, the total number of
 *   items purchased at the stadium, and the total cost at the stadium
 * Also displays the grand total cost for the trip
***************************************************************************/
void SouvenirPurchase::populateTripSummaryTable() {

    // resize and center the souveir and price table
    ui->souvenirAndPriceTable->resize(500,400);
    centerSouvenirTable();

    // clear out any exisiting data and remove purchase/previous buttons
    ui->souvenirAndPriceTable->clear();
    ui->purchaseBtn->hide();
    ui->pushButton_previous->hide();

    // Adjust columns and rows to content
    ui->souvenirAndPriceTable->resizeColumnsToContents();
    ui->souvenirAndPriceTable->resizeRowsToContents();


    QString teamName;        // stores the team name
    int numberOfItems = 0;   // stores items purchased at one stadium
    double totalCost = 0.0;  // stores total cost at one stadium

    // Change the headings of the table
    QStringList headers;
    headers << "Team Name" << "Total Items" << "Total Cost ($)";
    ui->souvenirAndPriceTable->setHorizontalHeaderLabels(headers);
    QHeaderView* souvenirTableHeaders = ui->souvenirAndPriceTable->horizontalHeader();
    souvenirTableHeaders->setSectionResizeMode(QHeaderView::Stretch);

    int numTeams = _teams.size();         // tracks the number of rows needed to display all teams
    int blankRows = 3;                    // num of blank lines to separate teams with grand total
    int totalRows = numTeams + blankRows; // total rows needed for entire table

    double grandTotalCost = 0.0;          // stores the grand total of the trip

    // Set the number of rows for souvenirAndPriceTable
    ui->souvenirAndPriceTable->setRowCount(totalRows);

    // iterate through every team on the trip and display corresponding info
    // also calculate the grand total
    for (int currRow = 0; currRow < numTeams; ++currRow) {
        teamName = _teams[currRow].teamName();
        numberOfItems = totalSouvenirsPurchased.at(currRow);
        totalCost = totalCostPerTeam.at(currRow);

        // update grand total
        grandTotalCost += totalCost;

        // Fill in the souvenir name, total items, and total cost for the current row
        ui->souvenirAndPriceTable->setItem(currRow, 0, new QTableWidgetItem(teamName));

        // displays the number of items purchased for one team
        QTableWidgetItem* itemsItem = new QTableWidgetItem(QString::number(numberOfItems));
        itemsItem->setTextAlignment(Qt::AlignVCenter);
        ui->souvenirAndPriceTable->setItem(currRow, 1, itemsItem);

        // displays the total cost at one stadium
        QTableWidgetItem* costItem = new QTableWidgetItem(QString::number(totalCost, 'f', 2));
        costItem->setTextAlignment(Qt::AlignVCenter); // Center text (optional)
        ui->souvenirAndPriceTable->setItem(currRow, 2, costItem);

    }

    // displays the grand total
    ui->souvenirAndPriceTable->setItem(totalRows - 1, 0, new QTableWidgetItem(QString("Grand Total")));
    ui->souvenirAndPriceTable->setItem(totalRows - 1, 2, new QTableWidgetItem(QString::number(grandTotalCost, 'f', 2)));

}

/***************************************************************************
 * Function called by: void SouvenirPurchase::populateTripSummaryTable()
 * Used to resize and center the souvenirAndPriceTable since the other
 *   UI elements are removed when the summary is displayed
***************************************************************************/
void SouvenirPurchase::centerSouvenirTable() {
    // Calculate the position to center the table in the dialog
    int parentWidth = this->width();
    int parentHeight = this->height();

    int tableWidth = ui->souvenirAndPriceTable->width();
    int tableHeight = ui->souvenirAndPriceTable->height();

    int x = (parentWidth - tableWidth) / 2;
    int y = (parentHeight - tableHeight) / 2;

    // Move the table to the calculated position
    ui->souvenirAndPriceTable->move(x, y);
    ui->label_teamName->move(x, 0);
}


/***************************************************************************
 * Returns the number of souvenirs purchased by the user
***************************************************************************/
int SouvenirPurchase::getNumberOfItemsPurchased() {
    return numberOfItemsPurchased;
}


/***************************************************************************
 * Returns the total cost of the items purchased by the user
***************************************************************************/
double SouvenirPurchase::getTotalCostAtStadium() {
    return totalCostAtStadium;
}

//-----------------------------BEGINNING OF GO TO SLOT FUNCTIONS------------------------------------

/***************************************************************************
 * After user presses "Add to Cart" -> updates the Summary Table with user's
 *    selections
 * User can change selections (add or delete items) and the Summary Table
 *    will update accordingly
***************************************************************************/
void SouvenirPurchase::on_purchaseBtn_clicked() {

    // Associate the two tables to variables
    QTableWidget* userSelectionTable = ui->souvenirAndPriceTable;
    QTableWidget* summaryTableCopy = ui->summaryTable;

    // initalizations
    numberOfItemsPurchased = 0;
    totalCostAtStadium = 0;


    /* go through each row of the souvenirAndPriceTable and sum the quantity
       of items purchased and total price */
    int numRows = userSelectionTable->rowCount();
    for (int row = 0; row < numRows; ++row) {
        // get individual souvenir price/quantity/total
        int quantity = qobject_cast<QSpinBox*>(userSelectionTable->cellWidget(row, 2))->value();
        double price = userSelectionTable->item(row, 1)->text().toDouble();
        double total = quantity * price;

        // add souvenir data to totals
        numberOfItemsPurchased += quantity;
        totalCostAtStadium += total;
    }

    // Fill out the Total Items and Total Price columns in summaryTable
    summaryTableCopy->setItem(0, 0, new QTableWidgetItem(QString::number(numberOfItemsPurchased)));
    summaryTableCopy->setItem(0, 1, new QTableWidgetItem(QString::number(totalCostAtStadium,  'f', 2)));
}

/***************************************************************************
 * Allows the user to move backwards during a trip and change their purchse
 *  selections
 * Variables Modified:
 *     - index : decremented
 *     - totalSouvenirsPurchase : last item in the vector is removed
 *     - totalCostPerTeam : last item in the vector is removed
***************************************************************************/
void SouvenirPurchase::on_pushButton_previous_clicked()
{
    // update parallel vectors to keep track of totals (from previous team)
    totalSouvenirsPurchased.pop_back();
    totalCostPerTeam.pop_back();

    index--;
    ui->pushButton_previous->setEnabled(index != 0);
    ui->pushButton_next->setText("Next");
    ui->groupBox_teamInfo->show();
    displayTeamInfo();
    ui->summaryTable->clear();
    populateSouvenirTable();

}

/***************************************************************************
 * Allows the user to move forward during a trip to the next stadium
 * Variables Modified:
 *     - index : incremented
 *     - totalSouvenirsPurchase : entry added to end of vector
 *     - totalCostPerTeam : entry added to end of vector
***************************************************************************/
void SouvenirPurchase::on_pushButton_next_clicked()
{
    // update parallel vectors to keep track of totals (from previous team)
    totalSouvenirsPurchased.push_back(numberOfItemsPurchased);
    totalCostPerTeam.push_back(totalCostAtStadium);

    // increment index
    index++;

    //If the user clicks the "close" button
    if (index == _teams.size() + 1) {
        close();
    }

    //If the user clicks "next" on the last team (display end screen)
    else if (index == _teams.size()) {
        // remove the summary table and team info box
        ui->groupBox_teamInfo->hide();
        ui->summaryTable->hide();

        // show the overall Trip Summary
        populateTripSummaryTable();

        ui->pushButton_next->setText("Close");
        ui->label_teamName->setText("Trip Summary:");
    } else {
        displayTeamInfo();
        ui->summaryTable->clear();
        populateSouvenirTable();
    }
    ui->pushButton_previous->setEnabled(true);
}
