#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QMenu>
#include "team.h"
#include "map.h"
#include "logindialog.h"
#include <QTableWidgetItem>
#include <QListWidgetItem>

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
    void login();

private slots:
    //void on_listWidget_teamList_currentTextChanged(const QString &currentText);
    void on_comboBox_sort_currentTextChanged(const QString &arg1);
    void on_comboBox_exclude_currentTextChanged(const QString &arg1);

    void on_listWidget_teamList_itemClicked(QListWidgetItem *item);

    void on_tableWidget_teamInfo_itemChanged();

    void on_tableWidget_souvenirInfo_itemChanged();

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
    QMap<QString, Property> propertyMap;

    LoginDialog *loginDialog;
    QMenu *loginMenu;
    QAction *loginAct;
    Team *currentTeam = nullptr;
    bool editFlag = true;

};
#endif // MAINWINDOW_H
//test
