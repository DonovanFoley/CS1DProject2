#ifndef MAINWINDOW_H
#define MAINWINDOW_H
//hi
#include <QMainWindow>
#include <QAction>
#include <QMenu>
#include "team.h"
#include "map.h"
#include "logindialog.h"
#include "stadiumdb.h"
#include "tripdialog.h"
#include <QTableWidgetItem>
#include <QListWidgetItem>
#include <QMessageBox>
#include <QRegularExpression>

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

    void setCurrentSouvenir(const QString &newCurrentSouvenir);

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
    QVector<Team> _teamsInTrip;
    QMap<QString, Property> propertyMap;

    LoginDialog *loginDialog;
    TripDialog *tripDialog;
    QMenu *loginMenu;
    QAction *loginAct;
    Team *currentTeam = nullptr;
    QString currentSouvenirName;
    double currentSouvenirPrice;
    bool loggedIn = false;
    bool editFlag = true;

};
#endif // MAINWINDOW_H
//test
