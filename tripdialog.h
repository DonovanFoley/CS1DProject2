#ifndef TRIPDIALOG_H
#define TRIPDIALOG_H

#include <QDialog>
#include "SouvenirPurchase.h"
#include "map.h"

namespace Ui {
class TripDialog;
}

/**
 * @brief The TripDialog class manages the user interface for planning and navigating through trips.
 */
class TripDialog : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Constructs a TripDialog with an optional parent widget.
     *
     * This dialog facilitates the planning and viewing of trips involving multiple teams.
     * @param parent The parent widget of this dialog, default is nullptr.
     */
    explicit TripDialog(QWidget *parent = nullptr);

    /**
     * @brief Populates the dialog with a vector of teams for trip planning.
     *
     * @param teams Vector of Team objects to be used in the trip.
     */
    void getTeams(QVector<Team> teams);

    /**
     * @brief Displays information about the currently selected team in the trip.
     */
    void displayTeamInfo();

    /**
     * @brief Destroys the TripDialog.
     */
    ~TripDialog();

private slots:
    /**
     * @brief Handles the action to navigate to the previous team in the trip.
     */
    void on_pushButton_previous_clicked();

    /**
     * @brief Handles the action to navigate to the next team in the trip.
     */
    void on_pushButton_next_clicked();

private:
    QVector<Team> _teams; ///< Vector of teams participating in the trip.
    int index; ///< Index of the currently displayed team in the vector.
    Ui::TripDialog *ui; ///< Pointer to the user interface for the TripDialog.
};

#endif // TRIPDIALOG_H
