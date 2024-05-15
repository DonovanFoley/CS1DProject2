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

/**
 * @brief The StadiumManager class manages the interactions and logic for stadium graph operations, such as traversals and team-to-stadium mappings.
 */
class StadiumManager : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief Constructs a StadiumManager to handle graph operations for a given set of stadiums and teams.
     * @param graph Reference to a Graph representing stadium connections.
     * @param teams Reference to a Map holding team data.
     */
    StadiumManager(Graph &graph, Map &teams);

    int performMST(QWidget *parentWidget);

    /**
     * @brief Performs a Depth-First Search (DFS) traversal starting from a user-selected stadium.
     * @param parentWidget The parent widget used for displaying dialog boxes.
     */
    void performDFS(QWidget *parentWidget);

    /**
     * @brief Performs a Breadth-First Search (BFS) traversal starting from a user-selected stadium.
     * @param parentWidget The parent widget used for displaying dialog boxes.
     */
    void performBFS(QWidget *parentWidget);

    /**
     * @brief Converts a list of team names to their corresponding stadium indices.
     * @param teamNames A vector of QStrings containing team names.
     * @return A vector of integers representing the indices of the stadiums associated with the team names.
     */
    std::vector<int> convertTeamNamesToStadiumIndices(const std::vector<QString> &teamNames);

    /**
     * @brief Prompts the user to input team names and returns them.
     * @param parentWidget The parent widget used for displaying input dialogs.
     * @return A vector of QStrings containing the inputted team names.
     */
    std::vector<QString> getUserInputTeamNames(QWidget *parentWidget);

private:
    Graph &graph; ///< Reference to the graph managing stadium connections.
    Map &teams; ///< Reference to the map managing team data.

    unordered_map<QString, int> StadiumToIndex; ///< Maps stadium names to their respective indices.
    unordered_map<int, QString> indexToStadium; ///< Maps indices to their respective stadium names.
};

#endif // STADIUMMANAGER_H
