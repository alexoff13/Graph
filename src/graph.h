#ifndef GRAPH_GRAPH_H
#define GRAPH_GRAPH_H
#include "arc.h"
#include <stack>
#include <queue>


using ArcStack = std::stack<Arc*>;
using VertexQueue = std::queue<Vertex>;


class Graph {
    Arc* head = nullptr;
    Arc* tail = nullptr;

private:
    int getIncidentCount(const Vertex& vertex);
    void unmarkAllVertices();
    void markVertex(const Vertex&);
    void vertexTraversal(ArcStack&, Vertex, VertexQueue*);
    bool isConnected();
    bool isEuler();
    bool areVerticesConnected(const Vertex&, const Vertex&);
    Arc* getIncidentArc(const Vertex&, int = 0);

public:
    Graph();
    Graph(Graph&);
    ~Graph();
    bool addArc(const Arc&);
    bool deleteArc(const Arc&);
    bool deleteVertex(const Vertex&);
    bool searchArc(const Arc&);
    bool searchVertex(const Vertex&);
    void print();
    void depthTraversal(const Vertex&, VertexQueue* = nullptr);
    void findEulerCycle(const Vertex&);
    explicit operator bool() const;
};


#endif