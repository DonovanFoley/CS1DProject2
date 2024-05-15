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

/**
 * @brief The Edge structure represents an edge in a graph with a weight and a destination vertex.
 */
struct Edge
{
    int destination; ///< The index of the destination vertex
    int weight; ///< The weight of the edge
    /**
     * @brief Defines comparison for Edge to facilitate a min-heap based on edge weight.
     * @param other The other edge to compare to.
     * @return True if this edge's weight is greater than the other's.
     */
    bool operator>(const Edge &other) const {
        return weight > other.weight; // Greater comparison for min-heap
    }
};

using AdjList = std::priority_queue<Edge, std::vector<Edge>, std::greater<Edge>>;
using GraphStructure = std::unordered_map<int, AdjList>;

/**
 * @brief The Graph class represents a directed graph using adjacency lists.
 */
class Graph
{
public:
    /**
     * @brief Adds a directed edge from one vertex to another with a specific weight.
     * @param originIndex The index of the origin vertex.
     * @param destinationIndex The index of the destination vertex.
     * @param weight The weight of the edge.
     */
    void addEdge(int originIndex, int destinationIndex, int weight);

    /**
     * @brief Adds an edge in one direction between two vertices.
     * @param origin The index of the origin vertex.
     * @param destination The index of the destination vertex.
     * @param weight The weight of the edge.
     */
    void add_edge_one_way(int, int, int);

    /**
     * @brief Prints the graph to standard output.
     */
    void print_graph();

    /**
     * @brief Conducts a recursive Depth-First Search starting from a given vertex.
     * @param graph The graph structure.
     * @param current The current vertex index.
     * @param visited A reference to a vector indicating if a vertex has been visited.
     * @param indexToStadium A map from vertex index to stadium name.
     * @param totalDistance Reference to the total distance traveled.
     */
    void recursiveDFS(GraphStructure graph,
                      int current,
                      std::vector<bool> &visited,
                      const std::unordered_map<int, QString> &indexToStadium,
                      int &totalDistance);

    /**
     * @brief Performs a Depth-First Search starting from a given vertex.
     * @param startVertex The starting vertex index.
     * @param visited A reference to a vector indicating if a vertex has been visited.
     * @param indexToStadium A map from vertex index to stadium name.
     * @return The count of vertices visited.
     */
    int DFS(int startVertex,
            std::vector<bool> &visited,
            const std::unordered_map<int, QString> &indexToStadium);

    /**
     * @brief Performs a Breadth-First Search starting from a given vertex.
     * @param graph The graph structure.
     * @param startVertex The starting vertex index.
     * @param indexToStadium A map from vertex index to stadium name.
     * @return The number of levels visited during the search.
     */
    int BFS(GraphStructure graph,
            int startVertex,
            const std::unordered_map<int, QString> &indexToStadium);
    //std::vector<int> dijkstra(int start, int startVertex, int& distance);


    /**
     * @brief Retrieves a reference to the internal graph structure.
     * @return Reference to the graph structure.
     */
    GraphStructure &getGraph();

    /**
     * @brief Computes the shortest paths from a start vertex to all other vertices using Dijkstra's algorithm.
     * @param startVertex The starting vertex index.
     * @param graph The graph structure.
     * @return A map of vertex indices to the shortest path costs from the start vertex.
     */
    std::unordered_map<int, double> dijkstra(int startVertex, GraphStructure graph);

    /**
     * @brief Calculates the shortest path between two vertices using Dijkstra's algorithm.
     * @param currentVertex The starting vertex index.
     * @param targetVertex The target vertex index.
     * @param totalDistance Reference to the variable storing the total distance of the path.
     * @param graph Reference to the graph structure.
     */
    void shortestPath(int currentVertex,
                      int targetVertex,
                      double &totalDistance,
                      GraphStructure &graph);

    /**
     * @brief Visits all stadiums recursively, computing the total travel distance.
     * @param currentVertex The current vertex index.
     * @param visitedStadiums Map marking stadiums that have been visited.
     * @param shortestPaths Map storing the shortest path distances from the start vertex.
     * @param totalDistance Reference to the total distance covered.
     * @param graph Reference to the graph structure.
     * @param vertices Vector of vertex indices representing the trip route.
     * @param verticesInTrip Vector of vertex indices included in the current trip.
     */
    void visitAllStadiumsRecursive(int currentVertex,
                                   std::unordered_map<int, bool> &visitedStadiums,
                                   std::unordered_map<int, double> &shortestPaths,
                                   double &totalDistance,
                                   GraphStructure &graph,
                                   QVector<int> &vertices,
                                   QVector<int> verticesInTrip);

    /**
     * @brief Map of vertex indices to Team pointers.
     */
    std::unordered_map<int, Team *> indexToTeamMap;

    /**
     * @brief Loads team information into the graph structure.
     * @param teams Reference to the Map containing team data.
     */
    void loadTeamsIntoGraph(Map &teams);


    /**
     * @brief Plans a trip recursively by visiting all remaining stadiums.
     * @param currentVertex The current vertex index.
     * @param remainingStadiums Vector of remaining stadium indices to visit.
     * @param shortestPaths Map storing shortest path distances from the start vertex.
     * @param totalDistance Reference to the total distance covered during the trip.
     * @param graph Reference to the graph structure.
     * @param vertices Vector of vertex indices representing the trip route.
     */
    void recursivePlanTrip(int currentVertex,
                           std::vector<int> &remainingStadiums,
                           std::unordered_map<int, double> &shortestPaths,
                           double &totalDistance,
                           GraphStructure graph,
                           QVector<int> &vertices);

    int findMSTTotalWeight(const GraphStructure& graph, int startVertex);
    std::vector<Edge> extractEdges(const GraphStructure& graph, int vertex);

private:
    GraphStructure graph; ///< The graph's adjacency list representation.
    QVector<int> vertices; ///< Vector of vertices in the graph.
};

#endif // GRAPH_H
