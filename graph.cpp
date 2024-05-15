// graph.cpp

#include "graph.h"
#include <queue>
#include <limits>
#include <functional> // For greater<T>

using namespace std;

void Graph::addEdge(const string &src, const string &dest, double weight) {
    adjList[src].push_back(make_pair(dest, weight));
    adjList[dest].push_back(make_pair(src, weight)); // undirected graph
}

vector<Edge> Graph::primMST() const {
    priority_queue<pair<double, string>, vector<pair<double, string>>, greater<>> pq;
    map<string, double> key;
    map<string, bool> inMST;
    map<string, string> parent;

    for (const auto &pair : adjList) {
        key[pair.first] = numeric_limits<double>::max();
        inMST[pair.first] = false;
        parent[pair.first] = "";
    }

    string start = adjList.begin()->first;
    pq.push(make_pair(0.0, start));
    key[start] = 0.0;

    while (!pq.empty()) {
        string u = pq.top().second;
        pq.pop();

        if (inMST[u]) continue;
        inMST[u] = true;

        for (const auto &i : adjList.at(u)) {
            string v = i.first;
            double weight = i.second;

            if (!inMST[v] && key[v] > weight) {
                key[v] = weight;
                pq.push(make_pair(key[v], v));
                parent[v] = u;
            }
        }
    }

    vector<Edge> mst;
    for (const auto &pair : parent) {
        if (!pair.second.empty()) {
            mst.push_back({pair.second, pair.first, key[pair.first]});
        }
    }

    return mst;
}
=======
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

void Graph::print_graph() 
{
  for (auto& [key, value]: graph) 
  {
    auto pq = value;

    std::cerr << key << ':';

    while(!pq.empty())
    {
      std::cerr << " {" << pq.top().destination << ", " << pq.top().weight << "}"; 
      pq.pop();
    }

    std::cerr << '\n';
  }
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
