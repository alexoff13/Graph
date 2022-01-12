#ifndef GRAPH_GRAPH_H
#define GRAPH_GRAPH_H
#include "arc.h"
#include <stack>


using ArcStack = std::stack<Arc*>;


class Graph {
    Arc* head = nullptr;
    Arc* tail = nullptr;

private:
    void unmarkAllVertices();
    void markVertex(Vertex);
    void vertexTraversal(ArcStack&, Vertex);

public:
    Graph();
    ~Graph();
    bool addArc(Arc);
    bool deleteArc(Arc);
    bool deleteVertex(Vertex);
    bool searchArc(Arc);
    bool searchVertex(Vertex);
    void print();
    void depthTraversal(Vertex vertex);
};


#endif
