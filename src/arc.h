#ifndef GRAPH_ARC_H
#define GRAPH_ARC_H
#include <iostream>
#include "vertex.h"


struct Arc {
    Arc* prev = nullptr;
    Arc* next = nullptr;
    Vertex vertex1;
    Vertex vertex2;

    Arc(const Vertex &vertex1, const Vertex &vertex2);
    void normalize();
    [[nodiscard]] bool includes(Vertex) const;
    bool operator==(Arc) const;
    friend std::ostream& operator<<(std::ostream&, const Arc&);
};


#endif