#include "vertex.h"


Vertex::Vertex(int vertex, bool isMarked) {
    this->vertex = vertex;
    this->isMarked = isMarked;
}


bool Vertex::operator==(Vertex other) const {
    return vertex == other.vertex;
}


bool Vertex::operator!=(Vertex other) const {
    return vertex != other.vertex;
}


bool Vertex::operator>(Vertex other) const {
    return vertex > other.vertex;
}


bool Vertex::operator<(Vertex other) const {
    return vertex < other.vertex;
}

std::ostream &operator<<(std::ostream &out, const Vertex &other) {
    out << other.vertex << (other.isMarked ? "*" : "");
    return out;
}
