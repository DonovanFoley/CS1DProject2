#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QAction>
#include <QFileDialog>
#include <QListWidgetItem>
#include <QMainWindow>
#include <QMenu>
#include <QMessageBox>
#include <QRegularExpression>
#include <QTableWidgetItem>
#include <filesystem>

#include "SouvenirPurchase.h"
#include "logindialog.h"
#include "map.h"
#include "stadiumdb.h"
#include "stadiummanager.h"
#include "team.h"
#include "tripdialog.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

/**
 * @brief The MainWindow class serves as the central GUI component of the application, managing interactions and displays of various data and functionalities.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Constructs a MainWindow with an optional parent widget.
     * @param parent The parent widget of this window, default is nullptr.
     */
    MainWindow(QWidget *parent = nullptr);

    /**
     * @brief Destroys the MainWindow.
     */
    ~MainWindow();

    /**
     * @brief Displays team names in the GUI.
     */
    void displayTeamNames();

    /**
     * @brief Displays detailed information about a team in the GUI.
     */
    void displayTeamInfo();

    /**
     * @brief Displays souvenir information in the GUI.
     */
    void displaySouvenirInfo();

    /**
     * @brief Displays trip names in the GUI.
     */
    void displayTripNames();

    /**
     * @brief Handles the user login process.
     */
    void login();

    /**
     * @brief Handles file selection by the user for any necessary file input operations.
     */
    void choose_file();

    /**
     * @brief Executes Dijkstra's algorithm to find shortest paths.
     */
    void djikstras();

    void MST();

    /**
     * @brief Executes a Depth-First Search algorithm.
     */
    void DFS();

    /**
     * @brief Executes a Breadth-First Search algorithm.
     */
    void BFS();

    /**
     * @brief Specific function that focuses on actions related to Marlins Park.
     */
    void marlinsPark();

    /**
     * @brief Sets the currently selected souvenir's name.
     * @param newCurrentSouvenir The new name of the current souvenir.
     */
    void setCurrentSouvenir(const QString &newCurrentSouvenir);

private slots:
    void on_comboBox_sort_currentTextChanged(const QString &arg1);
    void on_comboBox_exclude_currentTextChanged(const QString &arg1);
    void on_listWidget_teamList_itemClicked(QListWidgetItem *item);
    void on_tableWidget_teamInfo_itemChanged();
    void on_tableWidget_souvenirInfo_itemChanged();
    void on_pushButton_add_clicked();
    void on_pushButton_delete_clicked();
    void on_tableWidget_souvenirInfo_itemClicked(QTableWidgetItem *item);
    void on_pushButton_go_clicked();
    void on_checkBox_addToTrip_clicked(bool checked);
    void on_comboBox_tripType_currentTextChanged(const QString &arg1);

private:
    Ui::MainWindow *ui; ///< Pointer to the user interface for the MainWindow.

    // QVector<Team> _teams; ///< A QVector containing teams, currently unused in the implementation.
    // QMap<QString, Team> _teams; ///< A QMap mapping team names to Team objects, currently unused.

    /**
     * @brief Flag to indicate filtering teams from the National League only.
     */
    bool onlyNational = false;

    /**
     * @brief Flag to indicate filtering teams from the American League only.
     */
    bool onlyAmerican = false;

    /**
     * @brief Flag to indicate filtering stadiums with an open roof only.
     */
    bool onlyOpenRoof = false;

    /**
     * @brief Flag to indicate filtering trips to show only the routes with the greatest distance.
     */
    bool onlyGreatestDistance = false;

    /**
     * @brief Flag to indicate filtering trips to show only the routes with the smallest distance.
     */
    bool onlySmallestDistance = false;


    Map _teams; ///< Manages teams and associated data.
    Graph graph; ///< Graph structure for managing trips and routes.
    QVector<Team> _teamsInTrip; ///< Teams included in the current trip.
    QMap<QString, Property> propertyMap; ///< Map of properties used for sorting and filtering.

    LoginDialog *loginDialog; ///< Dialog for user authentication.
    TripDialog *tripDialog; ///< Dialog for planning trips.

    StadiumsDB database; ///< Database for managing stadium data.

    QMenu *loginMenu; ///< Menu for login actions.
    QAction *loginAct; ///< Action for triggering the login dialog.

    QMenu *fileMenu; ///< Menu for file-related actions.
    QAction *openDBAct; ///< Action for opening a database file.

    QMenu *presetMenu; ///< Menu for preset trips.
    QAction *MSTAct; ///< Action for a MST trip.
    QAction *DFSAct; ///< Action for a DFS trip.
    QAction *BFSAct; ///< Action for a BFS trip.
    QAction *marlinsParkAct; ///< Action for a Marlins Park trip.

    Team *currentTeam = nullptr; ///< Currently selected team.
    QString currentSouvenirName; ///< Name of the currently selected souvenir.
    double currentSouvenirPrice; ///< Price of the currently selected souvenir.
    bool loggedIn = false; ///< Flag indicating whether the user is logged in.
    bool editFlag = true; ///< Flag for enabling or disabling edit functionalities.
};

#endif // MAINWINDOW_H
