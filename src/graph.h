#ifndef GRAPH_GRAPH_H
#define GRAPH_GRAPH_H
#include "arc.h"
#include <stack>
#include <queue>


using ArcStack = std::stack<Arc*>;
using ArcQueue = std::queue<Arc*>;
using VertexQueue = std::queue<Vertex>;


class Graph {
private:
    Arc* head = nullptr;
    Arc* tail = nullptr;

    int getIncidentCount(const Vertex &vertex);
    void unmarkAllArcs();
    void unmarkAllVertices();
    void markVertex(const Vertex &vertex);
    void arcTraversal(ArcStack &arcs, Vertex vertex, ArcQueue *buffer);
    void vertexTraversal(ArcStack &arcs, Vertex vertex, VertexQueue *buffer);
    bool isConnected();
    bool isEuler();
    bool areVerticesConnected(const Vertex &vertex1, const Vertex &vertex2);
    Arc* getIncidentArc(const Vertex &vertex, int passes = 0);

public:
    Graph();
    Graph(Graph &other);
    ~Graph();
    bool addArc(const Arc &arc);
    bool deleteArc(const Arc &arc);
    bool deleteVertex(const Vertex &vertex);
    bool searchArc(const Arc &arc);
    bool searchVertex(const Vertex &arc);
    void print();
    void depthArcTraversal(const Vertex &vertex, ArcQueue *buffer = nullptr);
    void depthVertexTraversal(const Vertex &vertex, VertexQueue *buffer = nullptr);
    void findEulerCycle(const Vertex &vertex);
    explicit operator bool() const;
};


#endif