#ifndef GRAPH_VERTEX_H
#define GRAPH_VERTEX_H
#include <iostream>


class Vertex {
public:
    bool isMarked = false;
    int id;

    explicit Vertex(int = 0, bool = false);
    Vertex(const Vertex&);

    bool operator==(const Vertex&) const;
    bool operator!=(const Vertex&) const;
    bool operator>(const Vertex&) const;
    bool operator<(const Vertex&) const;
    friend std::ostream& operator<<(std::ostream&, const Vertex&);
};


#endif