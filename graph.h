// graph.h

#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <map>
#include <string>

namespace std {

struct Edge {
    string src, dest;
    double weight;
};

class Graph {
private:
    map<string, vector<pair<string, double>>> adjList;

public:
    void addEdge(const string &src, const string &dest, double weight);
    vector<Edge> primMST() const;
};

}

#endif // GRAPH_H
