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
