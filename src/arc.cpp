#include "arc.h"
#include "vertex.h"



Arc::Arc(const Vertex &vertex1, const Vertex &vertex2) : vertex1(vertex1), vertex2(vertex2) {}


Arc::Arc(const Arc &other) : vertex1(other.vertex1), vertex2(other.vertex2) {}


void Arc::normalize() {
    if (vertex1 > vertex2) {
        Vertex vertex = vertex1;
        vertex1 = vertex2;
        vertex2 = vertex;
    }
}


bool Arc::includes(const Vertex& vertex) const {
    return vertex1 == vertex || vertex2 == vertex;
}


bool Arc::operator==(const Arc& other) const {
    return vertex1 == other.vertex1 && vertex2 == other.vertex2 ||
           vertex1 == other.vertex2 && vertex2 == other.vertex1;
}

std::ostream &operator<<(std::ostream &out, const Arc &other) {
    out << other.vertex1 << " --- " << other.vertex2;
    return out;
}