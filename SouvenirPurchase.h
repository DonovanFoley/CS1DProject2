#ifndef SOUVENIRPURCHASE_H
#define SOUVENIRPURCHASE_H

#include <QDialog>
#include "QSpinBox"
#include "QTableWidget"
#include "ui_SouvenirPurchase.h"
#include <team.h>

namespace Ui {
class SouvenirPurchase;
}

class SouvenirPurchase : public QDialog
{
    Q_OBJECT

public:
    explicit SouvenirPurchase(QWidget *parent = nullptr);
    ~SouvenirPurchase();
    int getNumberOfItemsPurchased();
    double getTotalCostAtStadium();
    void displayTeamInfo();

    void getTeams(QVector<Team> teams);
    QVector<int> totalSouvenirsPurchased; // parallel vector to _teams
    QVector<double> totalCostPerTeam;     // parallel vector to _teams

private slots:
    void on_purchaseBtn_clicked();
    void on_pushButton_previous_clicked();
    void on_pushButton_next_clicked();

private:
    Ui::SouvenirPurchase *ui;
    QVector<Team> _teams;

    int index;
    void populateSouvenirTable();
    void populateTripSummaryTable();
    int numberOfItemsPurchased = 0;
    double totalCostAtStadium = 0;
    void centerSouvenirTable();
};

#endif // SOUVENIRPURCHASE_H
