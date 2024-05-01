/* #include "ui_graph.h"

Graph::Graph(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Graph)
{
    ui->setupUi(this);
}

Graph::~Graph()
{
    delete ui;
} */

#include "graph.h"

void Graph::addEdge(int originIndex, int destinationIndex, int weight)
{
    graph[originIndex].emplace(Edge{destinationIndex, weight});
    graph[destinationIndex].emplace(Edge{originIndex, weight});
}

void Graph::recursiveDFS(GraphStructure graph, int current, vector<bool>& visited, const unordered_map<int, QString>& indexToStadium, int& totalDistance)
{

    visited[current] = true;
    std::cout << "Visiting " << indexToStadium.at(current).toStdString() << endl;

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

/*int Graph::BFS(GraphStructure graph, int startVertex, const unordered_map<int, QString>& indexToStadium)
{
    int totalDistance = 0;
    vector<bool> visited(graph.size(), false);
    queue<int> q;

    q.push(startVertex);
    visited[startVertex] = true;
    //std::cout << "Visiting " << indexToStadium.at(current).toStdString() << endl;

    while (!q.empty())
    {
        int current = q.front();
        q.pop();
        std::cout << "Visiting " << indexToStadium.at(current).toStdString() << endl;

        AdjList& neighbors = graph[current];
        while (!neighbors.empty())
        {
            const Edge& edge = neighbors.top();
            //neighbors.pop();

            if (!visited[edge.destination])
            {
                visited[edge.destination] = true;
                q.push(edge.destination);
                totalDistance = totalDistance + edge.weight;
            }
            neighbors.pop();
        }
    }

    cout << "The total distance travelled by BFS in milage is: " << totalDistance << endl;
    return totalDistance;
}*/
/*int Graph::BFS(GraphStructure graph, int startVertex, const unordered_map<int, QString>& indexToStadium) {
    int totalDistance = 0;
    vector<bool> visited(graph.size(), false);
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;

    // Initialize the queue with all edges from the start vertex
    auto& startEdges = graph[startVertex];
    while (!startEdges.empty())
    {
        pq.push(startEdges.top());
        startEdges.pop();
    }
    visited[startVertex] = true;
    cout << "Starting BFS at " << indexToStadium.at(startVertex).toStdString() << endl;

    while (!pq.empty())
    {
        Edge currentEdge = pq.top();
        pq.pop();
        int currentVertex = currentEdge.destination;

        if (!visited[currentVertex])
        {
            visited[currentVertex] = true;
            totalDistance = totalDistance + currentEdge.weight;
            cout << "Visiting " << indexToStadium.at(currentVertex).toStdString() << endl;

            // Push all adjacent unvisited vertices into the queue
            auto& edges = graph[currentVertex];
            while (!edges.empty())
            {
                Edge adj = edges.top();
                edges.pop();
                if (!visited[adj.destination])
                {
                    pq.push(adj);
                }
            }
        }
    }

    cout << "The total distance travelled by BFS in mileage is: " << totalDistance << endl;
    return totalDistance;
} */

/*int BFS(GraphStructure& graph, int startVertex)
{
    int totalDistance = 0;
    vector<bool> visited(graph.size(), false);
    queue<int> q;  // Main BFS queue for layer-by-layer exploration

    visited[startVertex] = true;
    q.push(startVertex);
    cout << "Starting BFS at vertex " << startVertex << endl;

    while (!q.empty())
    {
        int current = q.front();
        q.pop();
        cout << "Visiting vertex " << current << endl;

        vector<Edge> tempEdges;  // To store edges for current node and sort them by weight
        if (!visited[current])
        {
            visited[current] = true;
            //Edge topEdge = graph[current].top();
           // graph[current].pop();
            //tempEdges.push_back(topEdge);
        }

        // Sort edges by weight so that we can add them back to the priority queue in the correct order
        sort(tempEdges.begin(), tempEdges.end(), [](const Edge& a, const Edge& b) {
            return a.weight < b.weight;
        });

        for (const Edge& edge : tempEdges) {
            if (!visited[edge.destination]) {
                //visited[edge.destination] = true;
                q.push(edge.destination);
                totalDistance += edge.weight;
                cout << "visiting " << edge.destination  << endl;
                //graph[current].push(edge);  // Reinsert the edge as we might need it for future references
            }
        }
    }

    cout << "The total distance travelled by BFS in mileage is: " << totalDistance << endl;
    return totalDistance;
} */

int Graph::BFS(GraphStructure graph, int startVertex, const unordered_map<int, QString>& indexToStadium) {
    int totalDistance = 0;
    queue<int> q;
    vector<bool> visited(graph.size(), false);

    // Enqueue the start vertex and mark it as visited
    q.push(startVertex);
    visited[startVertex] = true;

    // Continue until the queue is empty
    while (!q.empty()) {
        // Dequeue a vertex from the queue
        int currentVertex = q.front();
        q.pop();

        // Process the current vertex (for example, print it)
        cout << "Visiting " << indexToStadium.at(currentVertex).toStdString() << endl;

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

    cout << "The total distance travelled by BFS in mileage is: " << totalDistance << endl;
    return totalDistance;
}



int Graph::DFS(int startVertex, vector<bool>& visited, const unordered_map<int, QString>&indexToStadium)
{
    int totalDistance = 0;
    visited.resize(graph.size(), false);
    recursiveDFS(graph, startVertex, visited, indexToStadium,totalDistance);

    cout << "The total distance travelled by DFS in milage is: " << totalDistance << endl;
    return totalDistance;
}


GraphStructure& Graph::getGraph()
{
    return graph;
}
