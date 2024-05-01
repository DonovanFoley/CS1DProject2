/*#ifndef STADIUMMANAGER_H
#define STADIUMMANAGER_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class StadiumManager;
}
QT_END_NAMESPACE

class StadiumManager : public QMainWindow
{
    Q_OBJECT

public:
    StadiumManager(QWidget *parent = nullptr);
    ~StadiumManager();

private:
    Ui::StadiumManager *ui;
};
#endif // STADIUMMANAGER_H */


#ifndef STADIUMMANAGER_H
#define STADIUMMANAGER_H

#include "graph.h"
#include <QObject>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <unordered_map>

using namespace std;

class StadiumManager: public QObject
{
     Q_OBJECT
public:
    void loadStadiums();
    void performDFS(QWidget *parentWidget);
    void performBFS(QWidget *parentWidget);

private:
    Graph graph;
    unordered_map<QString, int> StadiumToIndex;
    unordered_map<int, QString> indexToStadium;
};

#endif // STADIUMMANAGER_H


