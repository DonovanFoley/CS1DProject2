#ifndef STADIUMMANAGER_H
#define STADIUMMANAGER_H

#include <QFile>
#include <QInputDialog>
#include <QMessageBox>
#include <QObject>
#include <QStringList>
#include <QTextStream>
#include <QWidget>
#include "graph.h"
#include "map.h"
#include <unordered_map>

using namespace std;

class StadiumManager : public QObject
{
    Q_OBJECT
public:
    StadiumManager(Graph &graph, Map &teams); //new

    //void loadStadiums();
    void performDFS(QWidget *parentWidget);
    void performBFS(QWidget *parentWidget);
    int performMST(QWidget *parentWidget);

    std::vector<int> convertTeamNamesToStadiumIndices(const std::vector<QString> &teamNames); //new
    std::vector<QString> getUserInputTeamNames(QWidget *parentWidget);                        //new

private:
    Graph &graph;
    Map &teams;

    unordered_map<QString, int> StadiumToIndex;
    unordered_map<int, QString> indexToStadium;
};

#endif // STADIUMMANAGER_H
