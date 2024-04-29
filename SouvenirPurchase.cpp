#include "SouvenirPurchase.h"
#include "ui_SouvenirPurchase.h"


SouvenirPurchase::SouvenirPurchase(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SouvenirPurchase)
{
    ui->setupUi(this);


    // For testing purposes only
    // A list of teams will be passed in via the constructor
    QMap<QString, double> s;
    s.insert("Baseball", 10.99);
    s.insert("Lanyard", 2);
    s.insert("Magnet", 4.50);
    s.insert("Glove", 32.40);

    teamsInTrip.push_back((Team("Arizona Diamondbacks", "Chase Field", 48686, "Phoenix, Arizona", "Grass", "National", 1998, 407, "Retro Modern", "Retractable", s)));
    teamsInTrip.push_back(Team("Atlanta Braves", "SunTrust Park", 41149, "Cumberland, Georgia", "Grass", "National", 2017, 400, "Retro Modern", "Open", s));
    teamsInTrip.push_back(Team("Baltimore Orioles", "Oriole Park at Camden Yards", 45971, "Baltimore, Maryland", "Grass", "American", 1992, 410, "Retro Classic", "Open", s));
    teamsInTrip.push_back(Team("Chicago Cubs", "Wrigley Field", 41268, "Chicago, Illinois", "Grass", "National", 1914, 400, "Jewel Box", "Open", s));

    Team testTeam = teamsInTrip.at(0);

    populateSouvenirTable(testTeam);
}

SouvenirPurchase::~SouvenirPurchase()
{
    delete ui;
}


/***************************************************************************
 * Puts the souvenirs & prices into the UI table (one Sadium displayed at a time)
 * Allows purchase of 0 to 100 quantity of each souvenir
***************************************************************************/
void SouvenirPurchase::populateSouvenirTable(Team team) {

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
        ui->souvenirAndPriceTable->setItem(currentRow, 0, new QTableWidgetItem(i.key()));
        ui->souvenirAndPriceTable->setItem(currentRow, 1, new QTableWidgetItem(QString::number(i.value(), 'f', 2)));

        /* Adds QSpin Boxes so that there is a min/max amount that a user could purchase of each
         * souvenir type.*/
        QSpinBox* quantitySelector = new QSpinBox();
        quantitySelector -> setMinimum(0);
        quantitySelector -> setMaximum(100);
        ui -> souvenirAndPriceTable -> setCellWidget(currentRow, 2, quantitySelector);
    }
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
    QTableWidget* summaryTable = ui->summaryTable;

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
    summaryTable->setItem(0, 0, new QTableWidgetItem(QString::number(numberOfItemsPurchased)));
    summaryTable->setItem(0, 1, new QTableWidgetItem(QString::number(totalCostAtStadium,  'f', 2)));
}

void SouvenirPurchase::on_continueBtn_clicked()
{
    this->close();
}

