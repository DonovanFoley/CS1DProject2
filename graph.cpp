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


// std::vector<int> Graph::dijkstra(int start, int endVertex, int &distance) {
//     int numberOfVertices = graph.size();
//     int startVertex = 7; // Dodger Stadium
//     // Initialize distances, visited arrays, and the path vector
//     int distances[numberOfVertices];
//     bool visited[numberOfVertices];
//     for (int i = 0; i < numberOfVertices; ++i) {
//         distances[i] = INF;
//         visited[i] = false;
//     }
//     distances[startVertex] = 0;

//     // Priority queue to store vertices with their distances
//     std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
//     pq.push({0, startVertex});

//     // Vector to store the path taken
//     std::vector<int> path(numberOfVertices, -1); // Initialize with -1 indicating no path

//     while (!pq.empty()) {
//         int currVertex = pq.top().second;
//         int currDistance = pq.top().first;
//         pq.pop();

//         // Skip if already visited
//         if (visited[currVertex])
//             continue;

//         // Mark current vertex as visited
//         visited[currVertex] = true;

//         // Update distances of adjacent vertices
//         auto adjList = graph[currVertex];
//         while (!adjList.empty()) {
//             const Edge& edge = adjList.top();
//             int neighborVertex = edge.destination;
//             int neighborWeight = edge.weight;
//             int newDistance = currDistance + neighborWeight;
//             if (newDistance < distances[neighborVertex]) {
//                 distances[neighborVertex] = newDistance;
//                 pq.push({newDistance, neighborVertex});
//                 // Update the path to the neighbor vertex
//                 path[neighborVertex] = currVertex; // Store the current vertex as the parent of the neighbor
//             }
//             adjList.pop(); // Remove the processed edge
//         }
//     }

//     distance = distances[endVertex];

//     // Construct the path from the end vertex to the start vertex using the stored path information
//     std::stack<int> shortestPath;
//     int current = endVertex;
//     while (current != -1) {
//         shortestPath.push(current);
//         current = path[current];
//     }

//     // Convert the stack to a vector to maintain the correct order of vertices
//     std::vector<int> resultPath;
//     while (!shortestPath.empty()) {
//         resultPath.push_back(shortestPath.top());
//         shortestPath.pop();
//     }

//     return resultPath;
// }


GraphStructure& Graph::getGraph()
{
    return graph;
}

std::unordered_map<int, double> Graph::dijkstra(int startVertex, GraphStructure graph)
{
    std::unordered_map<int, double> shortestPaths;
    std::priority_queue<Edge, std::vector<Edge>, std::greater<Edge>> pq;
    pq.push({startVertex, 0});
    shortestPaths[startVertex] = 0;

    while (!pq.empty())
    {
        int currentVertex = pq.top().destination;
        double currentDistance = pq.top().weight;
        pq.pop();

        while (!graph[currentVertex].empty())
        {
            Edge edge = graph[currentVertex].top();
            graph[currentVertex].pop();
            int distance = currentDistance + edge.weight;
            if (!shortestPaths.count(edge.destination) || distance < shortestPaths[edge.destination])
            {
                shortestPaths[edge.destination] = distance;
                pq.push({edge.destination, distance});
            }
        }
    }
    return shortestPaths;
}

void Graph::shortestPath(int currentVertex, int targetVertex, double& totalDistance, GraphStructure& graph)
{
    // Initialize shortest paths map with infinity for all vertices
    std::unordered_map<int, double> shortestPaths;
    for (const auto& node : graph) {
        shortestPaths[node.first] = std::numeric_limits<double>::infinity();
    }

    // Run Dijkstra's algorithm to find shortest paths from the current vertex
    shortestPaths = dijkstra(currentVertex, graph);

    // Check if a path exists to the target vertex
    if (shortestPaths[targetVertex] == std::numeric_limits<double>::infinity()) {
        std::cout << "No path exists from vertex " << currentVertex << " to vertex " << targetVertex << std::endl;
        return;
    }

    // Get the distance to the target vertex
    double distanceToTarget = shortestPaths[targetVertex];

    // Update the total distance with the distance to the target vertex
    totalDistance += distanceToTarget;
    std::cout << "Visited vertex " << targetVertex << " from vertex " << currentVertex << ". Distance: " << distanceToTarget << std::endl;
}

void Graph::visitAllStadiumsRecursive(int currentVertex, std::unordered_map<int, bool>& visitedStadiums, std::unordered_map<int, double>& shortestPaths, double& totalDistance, GraphStructure& graph)
{

    if (visitedStadiums[currentVertex])// If already visited, return
    {
        return;
    }

    // Mark the current vertex as visited
    visitedStadiums[currentVertex] = true;

    // Your existing logic to choose the next vertex and update the total distance
    std::unordered_map<int, double> localShortestPaths = dijkstra(currentVertex, graph);
    double minDistance = std::numeric_limits<double>::infinity();
    int nextVertex = -1;

    for (const auto& [vertex, distance] : localShortestPaths)
    {
        if (!visitedStadiums[vertex] && distance < minDistance)
        {
            minDistance = distance;
            nextVertex = vertex;
        }
    }

    if (nextVertex != -1)
    {
        totalDistance += minDistance;
        std::cout << "Visiting: " << nextVertex << " Distance: " << minDistance << std::endl;
        visitAllStadiumsRecursive(nextVertex, visitedStadiums, localShortestPaths, totalDistance, graph);
    }
    else
    {
        std::cout << "Completed visiting all accessible stadiums. Total distance: " << totalDistance << std::endl;
    }
}
