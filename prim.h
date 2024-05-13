#ifndef PRIM_H
#define PRIM_H

#include <vector>
#include <stack>
#include <QDebug>
#include <queue>
#include "graph.h"
#include "stadiumdb.h"  // Ensure stadium class is included

using namespace std;

// Enumeration types used for this graph
enum VertexEnum
{
    UNEXPLORED_VERTEX,
    VISITED_VERTEX
};

enum EdgeEnum
{
    UNEXPLORED_EDGE,
    DISCOVERY_EDGE,
    FORWARD_EDGE,
    BACK_EDGE,
    CROSS_EDGE
};

/**************************************************************************
* VERTEX CLASS
**************************************************************************/
template <typename VertexType>
class Vertex
{
    public:
        Vertex();
        Vertex(VertexType setVertexData, int setVertexIndex);
        ~Vertex();

        void setExploration(int setExplorationStatus);
        void setArriveTime(int arTime);
        void setDepartTime(int dpTime);
        void setCost(int cost);
        void setParent(Vertex<VertexType> *parentVertex);

        VertexType& operator* ();

        int  getExploration() const;
        int  getVertexIndex() const;
        int  getArriveTime() const;
        int  getDepartTime() const;
        int  getCost() const;
        Vertex<VertexType>*  getParent() const;

    private:
        VertexType 			vertexData;
        int 				vertexIndex;
        VertexEnum  		explorationStatus;
        int 				arrivalTime;
        int					departureTime;
        int					cost;
        Vertex<VertexType> *parent;
};

template <typename VertexType>
Vertex<VertexType>::Vertex()
                  : vertexData(VertexType()),
                    vertexIndex(-1),
                    explorationStatus(UNEXPLORED_VERTEX),
                    arrivalTime(0),
                    departureTime(9999999),
                    cost(INT_MAX),
                    parent(NULL)
{

}
template <typename VertexType>
Vertex<VertexType>::Vertex(VertexType setVertexData, int setVertexIndex)
                  : vertexData(setVertexData),
                    vertexIndex(setVertexIndex),
                    explorationStatus(UNEXPLORED_VERTEX),
                    arrivalTime(0),
                    departureTime(9999999),
                    cost(INT_MAX),
                    parent(NULL)
{

}

template <typename VertexType>
Vertex<VertexType>::~Vertex()
{

}

template <typename VertexType>
VertexType& Vertex<VertexType>::operator*()
{
    return vertexData;
}

template <typename VertexType>
void Vertex<VertexType>::setExploration(int setExplorationStatus)
{
    explorationStatus = VertexEnum(setExplorationStatus);
}

template <typename VertexType>
void Vertex<VertexType>::setArriveTime(int arTime)
{
    arrivalTime = arTime;
}

template <typename VertexType>
void Vertex<VertexType>::setDepartTime(int dpTime)
{
    departureTime = dpTime;
}
template <typename VertexType>
void Vertex<VertexType>::setCost(int cost)
{
    this->cost = cost;
}
template <typename VertexType>
void Vertex<VertexType>::setParent(Vertex<VertexType> *parentVertex)
{
    parent = parentVertex;
}

template <typename VertexType>
int  Vertex<VertexType>::getExploration() const
{
    return explorationStatus;
}

template <typename VertexType>
int  Vertex<VertexType>::getVertexIndex() const
{
    if (vertexIndex == -1)
    {
        throw std::runtime_error("Index not set");
    }

    return vertexIndex;
}

template <typename VertexType>
int  Vertex<VertexType>::getArriveTime() const
{
    return arrivalTime;
}
template <typename VertexType>
int  Vertex<VertexType>::getDepartTime() const
{
    return departureTime;
}

template <typename VertexType>
int  Vertex<VertexType>::getCost() const
{
    return cost;
}
template <typename VertexType>
Vertex<VertexType>*  Vertex<VertexType>::getParent() const
{
    return parent;
}

/**************************************************************************
* EDGE CLASS
**************************************************************************/
template <typename VertexType, typename WeightType>
class Edge
{
    public:
        Edge();
        Edge(Vertex<VertexType>& setVertex1,
             Vertex<VertexType>& setVertex2,
             WeightType setWeight);
        Edge(const Edge<VertexType, WeightType>& otherEdge); // Copy Constructor
        ~Edge();

        void setEdgeData(Vertex<VertexType>& setVertex1,
                         Vertex<VertexType>& setVertex2,
                         WeightType setWeight);
        void setWeight(WeightType setWeight);
        void setVertices(Vertex<VertexType>& setVertex1,
                         Vertex<VertexType>& setVertex2);
        void setExploration(EdgeEnum setExplorationStatus);
        WeightType getWeight() const;
        Vertex<VertexType>* getVertex1() const;
        Vertex<VertexType>* getVertex2() const;
        Vertex<VertexType>* getOpposite(Vertex<VertexType>& vertex) const;

    private:
        Vertex<VertexType> *vertex1;
        Vertex<VertexType> *vertex2;
        WeightType weight;
        EdgeEnum explorationStatus;
};

template <typename VertexType, typename WeightType>
Edge<VertexType, WeightType>::Edge()
                      : vertex1(NULL),
                        vertex2(NULL),
                        weight(WeightType()),
                        explorationStatus(UNEXPLORED_EDGE)
{

}
template <typename VertexType, typename WeightType>
Edge<VertexType, WeightType>::Edge(Vertex<VertexType>& setVertex1,
                                   Vertex<VertexType>& setVertex2,
                                   WeightType setWeight)
                      : vertex1(&setVertex1),
                        vertex2(&setVertex2),
                        weight(setWeight),
                        explorationStatus(UNEXPLORED_EDGE)
{

}
template <typename VertexType, typename WeightType>
Edge<VertexType, WeightType>::Edge(const Edge<VertexType, WeightType>& otherEdge)
{
    vertex1 = otherEdge.vertex1;
    vertex2 = otherEdge.vertex2;
    weight = otherEdge.weight;
    explorationStatus = otherEdge.explorationStatus;
}

template <typename VertexType, typename WeightType>
Edge<VertexType, WeightType>::~Edge()
{

}

template <typename VertexType, typename WeightType>
void Edge<VertexType, WeightType>::setEdgeData(Vertex<VertexType>& setVertex1,
                                               Vertex<VertexType>& setVertex2,
                                               WeightType setWeight)
{
    vertex1 = &setVertex1;
    vertex2 = &setVertex2;
    weight = setWeight;
}

template <typename VertexType, typename WeightType>
void Edge<VertexType, WeightType>::setWeight(WeightType setWeight)
{
    weight = setWeight;
}

template <typename VertexType, typename WeightType>
void Edge<VertexType, WeightType>::setVertices(Vertex<VertexType>& setVertex1,
                                               Vertex<VertexType>& setVertex2)
{
    vertex1 = &setVertex1;
    vertex2 = &setVertex2;
}

template <typename VertexType, typename WeightType>
void Edge<VertexType, WeightType>::setExploration(EdgeEnum setExplorationStatus)
{
    explorationStatus = setExplorationStatus;
}

template <typename VertexType, typename WeightType>
WeightType Edge<VertexType, WeightType>::getWeight() const
{
    return weight;
}

template <typename VertexType, typename WeightType>
Vertex<VertexType>* Edge<VertexType, WeightType>::getVertex1() const
{
    return vertex1;
}

template <typename VertexType, typename WeightType>
Vertex<VertexType>* Edge<VertexType, WeightType>::getVertex2() const
{
    return vertex2;
}

template <typename VertexType, typename WeightType>
Vertex<VertexType>* Edge<VertexType, WeightType>::getOpposite(Vertex<VertexType>& vertex) const
{
    if (vertex1 == &vertex)
    {
        return vertex2;
    }
    else if (vertex2 == &vertex)
    {
        return vertex1;
    }
    else
    {
        throw std::runtime_error("Vertex not found in edge");
    }
}

/**************************************************************************
* GRAPH CLASS
**************************************************************************/
template <typename VertexType, typename WeightType>
class PrimGraph
{
    public:
        PrimGraph(int numVertices, GraphType graphType);
        ~PrimGraph();

        void insert(VertexType& vertex1, VertexType& vertex2, WeightType weight);
        void incidentEdges(Vertex<VertexType>& vertex, priority_queue<Edge<VertexType,WeightType>, vector<Edge<VertexType,WeightType>>, greater<Edge<VertexType,WeightType>>> &listOfEdges);
        void PrimJarnikMSTComputation();
        void MST(vector<Edge<VertexType,WeightType> *> &edgeVector, WeightType &totalCost);
        void resetVertexEdgeExploration();

    private:
        vector<Vertex<VertexType>* > vertexList;
        vector<Edge<VertexType,WeightType>* > edgeList;
        GraphType graphType;
        int numVertices;
};

template <typename VertexType, typename WeightType>
PrimGraph<VertexType, WeightType>::PrimGraph(int numVertices, GraphType graphType)
                        : numVertices(numVertices),
                          graphType(graphType)
{
    vertexList.reserve(numVertices);
}

template <typename VertexType, typename WeightType>
PrimGraph<VertexType, WeightType>::~PrimGraph()
{

}

template <typename VertexType, typename WeightType>
void PrimGraph<VertexType, WeightType>::insert(VertexType& vertex1, VertexType& vertex2, WeightType weight)
{
    Vertex<VertexType>* v1 = new Vertex<VertexType>(vertex1, vertexList.size());
    Vertex<VertexType>* v2 = new Vertex<VertexType>(vertex2, vertexList.size() + 1);

    Edge<VertexType, WeightType>* edge = new Edge<VertexType, WeightType>(*v1, *v2, weight);
    edgeList.push_back(edge);

    vertexList.push_back(v1);
    vertexList.push_back(v2);
}

template <typename VertexType, typename WeightType>
void PrimGraph<VertexType, WeightType>::incidentEdges(Vertex<VertexType>& vertex, priority_queue<Edge<VertexType,WeightType>, vector<Edge<VertexType,WeightType>>, greater<Edge<VertexType,WeightType>>> &listOfEdges)
{
    for (auto edge : edgeList)
    {
        if (*(edge->getVertex1()) == *vertex || *(edge->getVertex2()) == *vertex)
        {
            listOfEdges.push(*edge);
        }
    }
}

template <typename VertexType, typename WeightType>
void PrimGraph<VertexType, WeightType>::PrimJarnikMSTComputation()
{
    vector<Vertex<VertexType>* > unvisitedVertices = vertexList;
    Vertex<VertexType> *currentVertex = NULL;
    Vertex<VertexType> *oppositeVertex= NULL;
    Vertex<VertexType> *sourceVertex = NULL;
    Edge<VertexType,WeightType> *edge;
    typename vector<Vertex<VertexType>* >::iterator vertexIt;
    typename vector<Vertex<VertexType>* >::iterator foundVertexIt;
    int edgeListSize = 0;
    int weight = INT_MAX;

    for (vertexIt = unvisitedVertices.begin(); vertexIt != unvisitedVertices.end(); vertexIt++)
    {
        (*vertexIt)->setCost(INT_MAX);
        (*vertexIt)->setParent(NULL);
    }

    sourceVertex = *(unvisitedVertices.begin());
    sourceVertex->setCost(0);

    while (!unvisitedVertices.empty())
    {
        priority_queue<Edge<VertexType,WeightType>, vector<Edge<VertexType,WeightType>>, greater<Edge<VertexType,WeightType>>> listOfEdges;
        int lowest = INT_MAX;

        for (vertexIt = unvisitedVertices.begin(); vertexIt != unvisitedVertices.end(); vertexIt++)
        {
            if ((*vertexIt)->getCost() < lowest)
            {
                currentVertex = *vertexIt;
                foundVertexIt = vertexIt;
                lowest = currentVertex->getCost();
            }
        }

        if (currentVertex != NULL)
        {
            unvisitedVertices.erase(foundVertexIt);
            incidentEdges(**currentVertex, listOfEdges);

            edgeListSize = listOfEdges.size();

            for (int i = 0; i < edgeListSize; i++)
            {
                edge = new Edge<VertexType, WeightType>(listOfEdges.top());
                listOfEdges.pop();
                oppositeVertex = edge->getOpposite(*currentVertex);
                weight = edge->getWeight();

                if (weight < oppositeVertex->getCost())
                {
                    oppositeVertex->setCost(weight);
                    oppositeVertex->setParent(currentVertex);
                    edge->setExploration(DISCOVERY_EDGE);
                }
                else
                {
                    if (currentVertex->getCost() != weight)
                    {
                        edge->setExploration(UNEXPLORED_EDGE);
                    }
                }
            }
        }
    }
}

template <typename VertexType, typename WeightType>
void PrimGraph<VertexType, WeightType>::MST(vector<Edge<VertexType,WeightType> *> &edgeVector, WeightType &totalCost)
{
    Edge<VertexType,WeightType> *currentEdge;
    totalCost = 0;
    int cost = 0;
    typename vector<Edge<VertexType,WeightType>* >::iterator edgeIt;
    stack<Vertex<VertexType> *> vertexStack;

    resetVertexEdgeExploration();

    PrimJarnikMSTComputation();

    for (edgeIt = edgeList.begin(); edgeIt != edgeList.end(); edgeIt++)
    {
        currentEdge = *edgeIt;

        if (currentEdge->getExploration() == DISCOVERY_EDGE)
        {
            cost = currentEdge->getWeight();
            totalCost = totalCost + cost;

            edgeVector.push_back(currentEdge);

            qDebug() << "MST edge between ";
            qDebug() << **(currentEdge->getVertex1())  << " and ";
            qDebug() << **(currentEdge->getVertex2())  << " has cost: ";
            qDebug() << currentEdge->getWeight() << endl;
        }
    }
}

template <typename VertexType, typename WeightType>
void PrimGraph<VertexType, WeightType>::resetVertexEdgeExploration()
{
    for (auto vertex : vertexList)
    {
        vertex->setExploration(UNEXPLORED_VERTEX);
    }

    for (auto edge : edgeList)
    {
        edge->setExploration(UNEXPLORED_EDGE);
    }
}

#endif // PRIM_H
