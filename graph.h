#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <queue>
#include <unordered_map>
#include <functional> // For std::greater
#include <iostream>
#include <QString>
using namespace std;

struct Edge
{
    int destination;
    int weight;
    bool operator>(const Edge& other) const
    {
        return weight > other.weight; // Greater comparison for min-heap
    }
};

using AdjList = priority_queue<Edge, vector<Edge>, greater<Edge>>;
using GraphStructure = std::unordered_map<int, AdjList>;

class Graph
{
public:
    void addEdge(int originIndex, int destinationIndex, int weight);
    void recursiveDFS(GraphStructure graph,int current, vector<bool>& visited, const unordered_map<int, QString>& indexToStadium, int& totalDistance);
    int DFS(int startVertex, vector<bool>& visited, const unordered_map<int, QString>&indexToStadium);
    int BFS(GraphStructure graph, int startVertex, const unordered_map<int, QString>& indexToStadium);
    GraphStructure& getGraph();

private:
    GraphStructure graph;
};

#endif // GRAPH_H


