#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "team.h"
#include "map.h"

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

private slots:
    void on_listWidget_teamList_currentTextChanged(const QString &currentText);

    void on_comboBox_sort_currentTextChanged(const QString &arg1);

    //void on_comboBox_sort_currentIndexChanged(int index);

    void on_comboBox_exclude_currentTextChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;

    //QVector<Team> _teams;
    //QMap<QString, Team> _teams;
    bool onlyNational;
    bool onlyAmerican;

    Map _teams;
    QMap<QString, Property> propertyMap;

};
#endif // MAINWINDOW_H
//test
