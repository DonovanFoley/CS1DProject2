#include "prim.h"
#include "stadiumdb.h"  // Ensure stadium class is included

// You can now use the PrimGraph class and its methods
int main() {
    // Create a graph with a given number of vertices
    PrimGraph<stadium, float> graph(30, UNDIRECTED_GRAPH);

    // Add edges and vertices as necessary
    // For example:
    stadium s1("Stadium 1"), s2("Stadium 2"), s3("Stadium 3");
    graph.insert(s1, s2, 10.5);
    graph.insert(s2, s3, 15.0);
    graph.insert(s1, s3, 5.0);

    // Compute the MST
    vector<Edge<stadium, float> *> mstEdges;
    float totalCost;
    graph.MST(mstEdges, totalCost);

    // Output the MST
    for (auto edge : mstEdges) {
        qDebug() << "Edge between " << **(edge->getVertex1()) << " and " << **(edge->getVertex2()) << " with weight " << edge->getWeight();
    }
    qDebug() << "Total cost: " << totalCost;

    return 0;
}

//
//these changes to graph might solve my remaining errors for prim
//#include "graph.h"
//#include "stadiumdb.h"
//#include <iostream>
//#include <vector>
//#include <unordered_map>
//#include <queue>
//
//void Graph::addEdge(int originIndex, int destinationIndex, int weight) {
//    graph[originIndex].emplace(destinationIndex, weight);
//    graph[destinationIndex].emplace(originIndex, weight);
//}
//
//void Graph::add_edge_one_way(int originIndex, int destinationIndex, int weight) {
//    graph[originIndex].emplace(destinationIndex, weight);
//}
//
//void Graph::print_graph() {
//    for (auto& [key, value] : graph) {
//        auto pq = value;
//        std::cout << key << ": ";
//        while (!pq.empty()) {
//            std::cerr << "< " << pq.top().destination << ", " << pq.top().weight << " > ";
//            pq.pop();
//        }
//        std::cerr << '\n';
//    }
//}
//
//void Graph::recursiveDFS(GraphStructure& graph, int current, std::vector<bool>& visited, const std::unordered_map<int, QString>& indexToStadium) {
//    visited[current] = true;
//    std::cout << "Visiting " << indexToStadium.at(current).toStdString() << std::endl;
//
//    while (!graph[current].empty()) {
//        Edge edge = graph[current].top();
//        graph[current].pop();
//
//        if (!visited[edge.destination]) {
//            totalDistance += edge.weight;
//            std::cout << "DISCOVERY edge (" << indexToStadium.at(current).toStdString() << " -> "
//                << indexToStadium.at(edge.destination).toStdString() << ") (" << edge.weight << ")" << std::endl;
//            recursiveDFS(graph, edge.destination, visited, indexToStadium);
//        }
//    }
//}
