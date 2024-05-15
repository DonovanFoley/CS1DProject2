#ifndef GRAPH_H
#define GRAPH_H

#include <QString>
#include "map.h"
#include <functional> // For std::greater
#include <iostream>
#include <limits>
#include <queue>
#include <stack>
#include <unordered_map>
#include <utility>
#include <vector>

#include "team.h"

const int INF = std::numeric_limits<int>::max(); // Represents infinite distance

struct Edge
{
    int destination;
    int weight;
    bool operator>(const Edge &other) const
    {
        return weight > other.weight; // Greater comparison for min-heap
    }
};

using AdjList = std::priority_queue<Edge, std::vector<Edge>, std::greater<Edge>>;
using GraphStructure = std::unordered_map<int, AdjList>;

class Graph
{
public:
    void addEdge(int originIndex, int destinationIndex, int weight);

    void add_edge_one_way(int, int, int);

    void print_graph();

    void recursiveDFS(GraphStructure graph,
                      int current,
                      std::vector<bool> &visited,
                      const std::unordered_map<int, QString> &indexToStadium,
                      int &totalDistance);
    int DFS(int startVertex,
            std::vector<bool> &visited,
            const std::unordered_map<int, QString> &indexToStadium);
    int BFS(GraphStructure graph,
            int startVertex,
            const std::unordered_map<int, QString> &indexToStadium);
    //std::vector<int> dijkstra(int start, int startVertex, int& distance);
    GraphStructure &getGraph();
    std::unordered_map<int, double> dijkstra(int startVertex, GraphStructure graph);
    void shortestPath(int currentVertex,
                      int targetVertex,
                      double &totalDistance,
                      GraphStructure &graph);
    void visitAllStadiumsRecursive(int currentVertex,
                                   std::unordered_map<int, bool> &visitedStadiums,
                                   std::unordered_map<int, double> &shortestPaths,
                                   double &totalDistance,
                                   GraphStructure &graph,
                                   QVector<int> &vertices,
                                   QVector<int> verticesInTrip);
    std::unordered_map<int, Team *> indexToTeamMap;
    void loadTeamsIntoGraph(Map &teams);
    void recursivePlanTrip(int currentVertex,
                           std::vector<int> &remainingStadiums,
                           std::unordered_map<int, double> &shortestPaths,
                           double &totalDistance,
                           GraphStructure graph,
                           QVector<int> &vertices);
    int findMSTTotalWeight(const GraphStructure& graph, int startVertex);
    std::vector<Edge> extractEdges(const GraphStructure& graph, int vertex);

private:
    GraphStructure graph;
    QVector<int> vertices;
};

#endif // GRAPH_H
