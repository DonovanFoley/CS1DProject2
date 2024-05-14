#ifndef MAINWINDOW_H
#define MAINWINDOW_H
//hi
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
#include "team.h"
#include "tripdialog.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void displayTeamNames();
    void displayTeamInfo();
    void displaySouvenirInfo();
    void displayTripNames();
    void login();
    void choose_file();
    void djikstras();

    void setCurrentSouvenir(const QString &newCurrentSouvenir);

    // added 5/13
    std::vector<QString> teamNameInTrip;
    std::vector<QString> createTeamNameVec(QVector<Team> _teamsInTrip);

private slots:
    //void on_listWidget_teamList_currentTextChanged(const QString &currentText);
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
    Ui::MainWindow *ui;

    //QVector<Team> _teams;
    //QMap<QString, Team> _teams;
    bool onlyNational = false;
    bool onlyAmerican = false;
    bool onlyOpenRoof = false;
    bool onlyGreatestDistance = false;
    bool onlySmallestDistance = false;

    Map _teams;
    Graph graph;
    QVector<Team> _teamsInTrip;
    QMap<QString, Property> propertyMap;

    LoginDialog *loginDialog;
    TripDialog *tripDialog;

    StadiumsDB database;

    QMenu *loginMenu;
    QAction *loginAct;

    QMenu *fileMenu;
    QAction *openDBAct;

    Team *currentTeam = nullptr;
    QString currentSouvenirName;
    double currentSouvenirPrice;
    bool loggedIn = false;
    bool editFlag = true;


};
#endif // MAINWINDOW_H
//test
