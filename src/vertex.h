#ifndef GRAPH_VERTEX_H
#define GRAPH_VERTEX_H
#include <iostream>


struct Vertex {
    bool isMarked = false;
    int vertex;

    explicit Vertex(int, bool = false);
    bool operator==(Vertex) const;
    bool operator>(Vertex) const;
    bool operator<(Vertex) const;
    friend std::ostream& operator<<(std::ostream&, const Vertex&);
};


#endif
