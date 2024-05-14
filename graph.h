#ifndef GRAPH_H
#define GRAPH_H

#include <QString>
#include <functional> // For std::greater
#include <iostream>
#include <memory> // For std::unique_ptr
#include <queue>
#include <unordered_map>
#include <vector>

#include "team.h"

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

    GraphStructure &getGraph();

    void recursivePlanTrip(int currentVertex,
                                  std::vector<int> &remainingStadiums,
                                  std::unordered_map<int, double> &shortestPaths,
                                  double &totalDistance,
                                  GraphStructure graph,
                                  std::vector<int> &tripOrder);

    std::unordered_map<int, double> dijkstra(int startVertex, GraphStructure graph);

private:
    GraphStructure graph;
};

#endif // GRAPH_H
