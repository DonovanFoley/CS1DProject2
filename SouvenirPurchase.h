#ifndef SOUVENIRPURCHASE_H
#define SOUVENIRPURCHASE_H

#include <QDialog>
#include <team.h>
#include "QSpinBox"
#include "QTableWidget"
#include "ui_SouvenirPurchase.h"

namespace Ui {
class SouvenirPurchase;
}

/**
 * @brief The SouvenirPurchase class handles the operations related to purchasing
 * souvenirs in a graphical user interface.
 *
 * It manages the interaction between the user and the UI for purchasing souvenirs,
 * tracking the number of items purchased and their total cost, and navigating through
 * different teams' information.
 */
class SouvenirPurchase : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Constructs a SouvenirPurchase dialog.
     * @param parent The parent widget of this dialog, default is nullptr.
     */
    explicit SouvenirPurchase(QWidget *parent = nullptr);

    /**
     * @brief Destroys the SouvenirPurchase dialog.
     */
    ~SouvenirPurchase();

    /**
     * @brief Retrieves the total number of souvenir items purchased.
     * @return Integer count of purchased items.
     */
    int getNumberOfItemsPurchased();

    /**
     * @brief Calculates the total cost of souvenirs purchased at a stadium.
     * @return Total cost as a double.
     */
    double getTotalCostAtStadium();

    /**
     * @brief Displays information about the team associated with the current selection.
     */
    void displayTeamInfo();

    /**
     * @brief Sets the teams for which souvenirs can be purchased.
     * @param teams A QVector of Team objects.
     */
    void getTeams(QVector<Team> teams);

    // Parallel vector to _teams indicating the total number of souvenirs purchased for each team.
    QVector<int> totalSouvenirsPurchased;

    // Parallel vector to _teams indicating the total cost for souvenirs purchased per team.
    QVector<double> totalCostPerTeam;

private slots:
    /**
     * @brief Slot to handle the purchase button click event.
     */
    void on_purchaseBtn_clicked();

    /**
     * @brief Slot to navigate to the previous team's information.
     */
    void on_pushButton_previous_clicked();

    /**
     * @brief Slot to navigate to the next team's information.
     */
    void on_pushButton_next_clicked();

private:
    Ui::SouvenirPurchase *ui; ///< Pointer to the user interface for the SouvenirPurchase dialog.
    QVector<Team> _teams; ///< Container of teams available for souvenir purchase.

    int index; ///< Index of the currently displayed team in the _teams vector.
    /**
     * @brief Populates the souvenir table with available items for the current team.
     */
    void populateSouvenirTable();

    /**
     * @brief Populates the trip summary table with the totals from all teams visited.
     */
    void populateTripSummaryTable();

    /**
     * @brief Centers the souvenir table in the UI.
     */
    void centerSouvenirTable();

    int numberOfItemsPurchased = 0; ///< Number of items purchased during the session.
    double totalCostAtStadium = 0; ///< Total cost of items purchased at the current stadium.
};

#endif // SOUVENIRPURCHASE_H
