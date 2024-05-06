#include "graph.h"

void Graph::addEdge(int originIndex, int destinationIndex, int weight)
{
    graph[originIndex].emplace(Edge{destinationIndex, weight});
    graph[destinationIndex].emplace(Edge{originIndex, weight});
}

void Graph::add_edge_one_way(int originIndex, int destinationIndex, int weight) 
{
  graph[originIndex].emplace(Edge{destinationIndex, weight});
}

void Graph::recursiveDFS(GraphStructure graph, int current, std::vector<bool>& visited, const std::unordered_map<int, QString>& indexToStadium, int& totalDistance)
{

    visited[current] = true;
    std::cout << "Visiting " << indexToStadium.at(current).toStdString() << std::endl;

    while (!graph[current].empty())
    {
        Edge edge = graph[current].top();
        graph[current].pop();

        if (!visited[edge.destination])
        {
            totalDistance = totalDistance  + edge.weight;
           // cout << "Discovery edge: " << indexToStadium.at(current).toStdString() << " --> "
            //          << indexToCityMap.at(edge.destination).toStdString() << " (weight: " << edge.weight << ")" << endl;
            recursiveDFS(graph, edge.destination, visited, indexToStadium, totalDistance);
        }
    }

    //cout << "The total distance travelled by DFS in milage is: " << totalDistance << endl;
}


int Graph::BFS(GraphStructure graph, int startVertex, const std::unordered_map<int, QString>& indexToStadium) {
    int totalDistance = 0;
    std::queue<int> q;
    std::vector<bool> visited(graph.size(), false);

    // Enqueue the start vertex and mark it as visited
    q.push(startVertex);
    visited[startVertex] = true;

    // Continue until the queue is empty
    while (!q.empty()) {
        // Dequeue a vertex from the queue
        int currentVertex = q.front();
        q.pop();

        // Process the current vertex (for example, print it)
        std::cout << "Visiting " << indexToStadium.at(currentVertex).toStdString() << std::endl;

        // Traverse all adjacent vertices of the dequeued vertex
        while (!graph[currentVertex].empty())
        {
            Edge edge = graph[currentVertex].top();
            graph[currentVertex].pop();

            if (!visited[edge.destination]) {
                // If the adjacent vertex has not been visited, enqueue it and mark it as visited
                q.push(edge.destination);
                visited[edge.destination] = true;

                totalDistance = totalDistance + edge.weight;
            }
        }
    }

    std::cout << "The total distance travelled by BFS in mileage is: " << totalDistance << std::endl;
    return totalDistance;
}



int Graph::DFS(int startVertex, std::vector<bool>& visited, const std::unordered_map<int, QString>&indexToStadium)
{
    int totalDistance = 0;
    visited.resize(graph.size(), false);
    recursiveDFS(graph, startVertex, visited, indexToStadium,totalDistance);

    std::cout << "The total distance travelled by DFS in milage is: " << totalDistance << std::endl;
    return totalDistance;
}


GraphStructure& Graph::getGraph()
{
    return graph;
}
