#include "stadiummanager.h"
#include <QMessageBox>
#include <QObject>

// void StadiumManager::loadStadiums()
// {
//     //qDebug() << "Current directory:" << QDir::currentPath();
//     QString filePath = "/Users/cameline/Desktop/StadiumManager/Distance between stadiums.csv";

//     QFile file(filePath);
//     if (!file.open(QIODevice::ReadOnly)) {
//         cerr << "Failed to open file: " << filePath.toStdString() << endl;
//         return;
//     }

//     QTextStream in(&file);
//     QString header = in.readLine();
//     int index = 0;
//     while (!in.atEnd()) {
//         QString line = in.readLine();
//         cerr << "Reading line: " << line.toStdString() << endl; // Debug output for each line

//         QStringList fields = line.split(',');

//         if (fields.size() < 3) {
//             cerr << "Skipping malformed line." << endl;
//             continue;
//         }

//         QString origin = fields.at(0).trimmed().toLower();
//         QString destination = fields.at(1).trimmed().toLower();
//         int distance = fields.at(2).toInt();

//         if (StadiumToIndex.find(origin) == StadiumToIndex.end()) {
//             cerr << "Adding new stadium:" << origin.toStdString() << endl;
//             StadiumToIndex[origin] = index;
//             indexToStadium[index] = origin;
//             index++;
//         }
//         if (StadiumToIndex.find(destination) == StadiumToIndex.end()) {
//             cerr << "Adding new stadium:" << destination.toStdString() << endl;
//             StadiumToIndex[destination] = index;
//             indexToStadium[index] = destination;
//             index++;
//         }

//         //graph.addEdge(StadiumToIndex[origin], StadiumToIndex[destination], distance);
//     }

//     cerr << "Stadiums loaded: " << StadiumToIndex.size() << endl; // Debug output for map size
// }

/*StadiumManager::StadiumManager(Graph& graph, Map& teams) : graph(graph), teams(teams)
{
    for(int i = 0; i < teams.size(); i++)
    {
        StadiumToIndex[i] = team.id();
    }
    for(int i = 0; i < teams.size(); i++)
    {
        indexToStadium; = team.id();
    }
}*/

StadiumManager::StadiumManager(Graph &graph, Map &teams)
    : graph(graph)
    , teams(teams)
{
    for (int i = 0; i < teams.size(); i++) {
        Team &team = *teams(i); // Dereference the pointer
        QString stadiumNameLower = team.stadiumName().toLower();
        indexToStadium[team.id()] = stadiumNameLower;
        StadiumToIndex[stadiumNameLower] = team.id();

        //indexToStadium[team.id()] = team.stadiumName();
    }
}

void StadiumManager::performDFS(QWidget *parentWidget)
{
    int totalDistance = 0;
    //std::vector<bool> visited;
    std::vector<bool> visited(graph.getGraph().size(), false);
    QString searchKey = "Oracle Park"; // "Oracle Park" converted to lowercase
    searchKey = searchKey.toLower();

    if (StadiumToIndex.find(searchKey) != StadiumToIndex.end()) {
        int startVertex = StadiumToIndex[searchKey];
        GraphStructure graphCopy = graph.getGraph();
        totalDistance = graph.DFS(startVertex, visited, indexToStadium);
        //cout << "DFS Total Distnce: " << totalDistance << endl;
        QMessageBox::information(parentWidget,
                                 "DFS Total Distance",
                                 "Total Distance: " + QString::number(totalDistance));
    } else {
        cerr << "Oracle Park not found in the stadium list." << endl;
    }
}

void StadiumManager::performBFS(QWidget *parentWidget)
{
    int totalDistance = 0;
    QString searchKey = "Target Field"; // "Target Field" converted to lowercase
    searchKey = searchKey.toLower();
    if (StadiumToIndex.find(searchKey) != StadiumToIndex.end()) {
        int startVertex = StadiumToIndex[searchKey];
        GraphStructure graphCopy = graph.getGraph();
        totalDistance = graph.BFS(graphCopy, startVertex, indexToStadium);
        //cout << "BFS Total Distnce: " << totalDistance << endl;
        QMessageBox::information(parentWidget,
                                 "BFS Total Distance",
                                 "Total Distance: " + QString::number(totalDistance));
    } else {
        cerr << "Target Field not found in the stadium list." << endl;
    }
}

std::vector<QString> StadiumManager::getUserInputTeamNames(QWidget *parentWidget)
{
    bool ok;
    QString text = QInputDialog::getText(parentWidget,
                                         "Enter Team Names",
                                         "Team names, separated by commas (e.g., Lakers, Bulls):",
                                         QLineEdit::Normal,
                                         "",
                                         &ok);
    if (ok && !text.isEmpty()) {
        QStringList names = text.split(",");
        std::vector<QString> trimmedNames;
        for (QString &name : names) {
            trimmedNames.push_back(name.trimmed());
        }
        return trimmedNames;
    }
    return {};
}

std::vector<int> StadiumManager::convertTeamNamesToStadiumIndices(
    const std::vector<QString> &teamNames)
{
    std::vector<int> indices;

    for (const auto &name : teamNames) {
        int id = teams.findStadiumIndex(name);
        if (id != -1) {
            indices.push_back(id);
        } else {
            // Log or report an issue when a team name is not found
            qWarning() << "Warning: Team name" << name << "was not found in the map.";
        }
    }

    if (indices.empty()) {
        qWarning() << "No valid team names were found in the input list.";
    }

    return indices;
}
