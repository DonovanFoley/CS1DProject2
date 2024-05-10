#include "stadiummanager.h"
#include <QMessageBox>
#include <QObject>
#include <algorithm>
#include <climits> 

void StadiumManager::loadStadiums()
{
    //qDebug() << "Current directory:" << QDir::currentPath();
    QString filePath = "/Users/cameline/Desktop/StadiumManager/Distance between stadiums.csv";

    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly))
     {
        cerr << "Failed to open file: " << filePath.toStdString() << endl;
        return;
    }

    QTextStream in(&file);
    QString header = in.readLine();
    int index = 0;
    while (!in.atEnd()) {
        QString line = in.readLine();
        cerr << "Reading line: " << line.toStdString() << endl;  // Debug output for each line


        QStringList fields = line.split(',');

        if (fields.size() < 3) {
            cerr << "Skipping malformed line." << endl;
            continue;
        }

        QString origin = fields.at(0).trimmed().toLower();
        QString destination = fields.at(1).trimmed().toLower();
        int distance = fields.at(2).toInt();

        if (StadiumToIndex.find(origin) == StadiumToIndex.end())
        {
            cerr << "Adding new stadium:" << origin.toStdString() << endl;
            StadiumToIndex[origin] = index;
            indexToStadium[index] = origin;
            index++;
        }
        if (StadiumToIndex.find(destination) == StadiumToIndex.end())
        {
            cerr << "Adding new stadium:" << destination.toStdString() << endl;
            StadiumToIndex[destination] = index;
            indexToStadium[index] = destination;
            index++;
        }

        graph.addEdge(StadiumToIndex[origin], StadiumToIndex[destination], distance);
    }

    cerr << "Stadiums loaded: " << StadiumToIndex.size() << endl; // Debug output for map size
}


void StadiumManager::performDFS(QWidget *parentWidget)
{
    int totalDistance = 0;
    std::vector<bool> visited;
    QString searchKey = "oracle park"; // "Oracle Park" converted to lowercase
    if (StadiumToIndex.find(searchKey) != StadiumToIndex.end())
    {
        int startVertex = StadiumToIndex[searchKey];
        totalDistance = graph.DFS(startVertex, visited, indexToStadium);
        QMessageBox::information(parentWidget, "Total Distance", "Total Distance: " + QString::number(totalDistance));
    }
    else
    {
        cerr << "Oracle Park not found in the stadium list." << endl;
    }
}

void StadiumManager::performBFS(QWidget *parentWidget)
{
    int totalDistance = 0;
    QString searchKey = "target field"; // "Target Field" converted to lowercase
    if (StadiumToIndex.find(searchKey) != StadiumToIndex.end())
    {
        int startVertex = StadiumToIndex[searchKey];
        GraphStructure graphCopy = graph.getGraph();
        totalDistance = graph.BFS(graphCopy, startVertex, indexToStadium);
        QMessageBox::information(parentWidget, "Total Distance", "Total Distance: " + QString::number(totalDistance));
    }
    else
    {
        cerr << "Target Field not found in the stadium list." << endl;
    }
}

int Graph::planTrip(int startVertex, const std::vector<int>& stadiums) {
    int minDistance = INT_MAX;
    return recursivePlanTrip(startVertex, stadiums, 0, minDistance);
}

int Graph::recursivePlanTrip(int currentVertex, std::vector<int> remainingStadiums, int currentDistance, int& minDistance) {
    if (remainingStadiums.empty()) {
        return currentDistance;  // Base case: all stadiums visited
    }

    for (auto it = remainingStadiums.begin(); it != remainingStadiums.end(); ++it) {
        int nextVertex = *it;
        // Finding the weight from the current vertex to the next vertex
        int distanceToNext = INT_MAX;
        while (!graph[currentVertex].empty()) {
            Edge edge = graph[currentVertex].top();
            graph[currentVertex].pop();
            if (edge.destination == nextVertex) {
                distanceToNext = edge.weight;
                break;
            }
        }

        if (distanceToNext != INT_MAX) {  // If a valid edge was found
            std::vector<int> newRemaining = remainingStadiums;
            newRemaining.erase(it);  // Remove the next vertex from remaining list
            int totalDistance = recursivePlanTrip(nextVertex, newRemaining, currentDistance + distanceToNext, minDistance);
            if (totalDistance < minDistance) {
                minDistance = totalDistance;  // Update the minimum distance found
            }
        }
    }

    return minDistance;
}
