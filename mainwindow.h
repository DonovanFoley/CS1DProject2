#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <team.h>

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

private slots:
    void on_listWidget_teamList_currentTextChanged(const QString &currentText);

private:
    Ui::MainWindow *ui;

    //QVector<Team> _teams;
    QMap<QString, Team> _teams;
};
#endif // MAINWINDOW_H
//test
