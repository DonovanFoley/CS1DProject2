#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <queue>
#include <unordered_map>
#include <functional> // For std::greater
#include <iostream>
#include <QString>

#include "team.h"


struct Edge
{
    int destination;
    int weight;
    bool operator>(const Edge& other) const
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

    void recursiveDFS(GraphStructure graph, int current, std::vector<bool>& visited, const std::unordered_map<int, QString>& indexToStadium, int& totalDistance);
    int DFS(int startVertex, std::vector<bool>& visited, const std::unordered_map<int, QString>&indexToStadium);
    int BFS(GraphStructure graph, int startVertex, const std::unordered_map<int, QString>& indexToStadium);
    GraphStructure& getGraph();
    int planTrip(int startVertex, const std::vector<int>& stadiums);

private:
    GraphStructure graph;
    int recursivePlanTrip(int currentVertex, std::vector<int> remainingStadiums, int currentDistance, int& minDistance);
};

#endif // GRAPH_H


