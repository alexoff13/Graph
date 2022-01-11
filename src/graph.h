#ifndef GRAPH_GRAPH_H
#define GRAPH_GRAPH_H
#include "arc.h"


class Graph {
    Arc* head = nullptr;
    Arc* tail = nullptr;

public:
    Graph();
    ~Graph();
    bool addArc(Arc);
    bool deleteArc(Arc);
    bool deleteVertex(Vertex);
    bool searchArc(Arc);
    bool searchVertex(Vertex);
    void print();
};


#endif
