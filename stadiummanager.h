#ifndef STADIUMMANAGER_H
#define STADIUMMANAGER_H

#include "graph.h"
#include "map.h"
#include <QObject>
#include <QMessageBox>
#include <QWidget>
#include <QInputDialog>
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <unordered_map>

using namespace std;

class StadiumManager: public QObject
{
    Q_OBJECT
public:
    StadiumManager(Graph& graph, Map& teams);   //new

    void loadStadiums();
    void performDFS(QWidget *parentWidget);
    void performBFS(QWidget *parentWidget);


    std::vector<int> convertTeamNamesToStadiumIndices(const std::vector<QString>& teamNames); //new
    std::vector<QString> getUserInputTeamNames(QWidget* parentWidget); //new

private:
    Graph& graph;
    Map& teams;

    unordered_map<QString, int> StadiumToIndex;
    unordered_map<int, QString> indexToStadium;

    
};

#endif // STADIUMMANAGER_H
