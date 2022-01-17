#ifndef GRAPH_ARC_H
#define GRAPH_ARC_H
#include <iostream>
#include "vertex.h"


class Arc {
public:
    Arc* prev = nullptr;
    Arc* next = nullptr;
    bool isMarked = false;
    Vertex vertex1;
    Vertex vertex2;

    Arc(const Vertex&, const Vertex&);
    Arc(const Arc&);
    void normalize();
    [[nodiscard]] bool includes(const Vertex&) const;
    bool operator==(const Arc&) const;
    friend std::ostream& operator<<(std::ostream&, const Arc&);
};


#endif