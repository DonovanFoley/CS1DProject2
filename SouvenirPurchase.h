
// TEST CODE: Paste into MainWindow Constructor & Comment out other code in constructor
// #include "SouvenirPurchase.h"
// SouvenirPurchase testWindow(this);
// testWindow.exec(); // Use exec() for a modal dialog, which will block input to other windows until dismissed
// std::cout << "Number of items purchased: " << testWindow.getNumberOfItemsPurchased() << std::endl;
// std::cout << "Total cost at this stadium: " << testWindow.getTotalCostAtStadium() << std::endl;

#ifndef SOUVENIRPURCHASE_H
#define SOUVENIRPURCHASE_H

#include <QDialog>
#include "team.h"

#include "QMap"
#include "QVector"
#include "QSpinBox"


namespace Ui {
class SouvenirPurchase;
}

class SouvenirPurchase : public QDialog
{
    Q_OBJECT

public:
    // will be modified to accept a vector of Teams
    explicit SouvenirPurchase(QWidget *parent = nullptr);
    int getNumberOfItemsPurchased();
    double getTotalCostAtStadium();
    ~SouvenirPurchase();

private slots:
    void on_purchaseBtn_clicked();

    void on_continueBtn_clicked();

private:
    Ui::SouvenirPurchase *ui;
    QVector<Team> teamsInTrip;
    int numberOfItemsPurchased = 0;
    double totalCostAtStadium = 0;

    void populateSouvenirTable(Team team);

};

#endif // SOUVENIRPURCHASE_H
