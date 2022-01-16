#include "vertex.h"


Vertex::Vertex(int id, bool isMarked) : id(id), isMarked(isMarked) {}


Vertex::Vertex(const Vertex &other) = default;


bool Vertex::operator==(const Vertex& other) const {
    return id == other.id;
}


bool Vertex::operator!=(const Vertex& other) const {
    return id != other.id;
}


bool Vertex::operator>(const Vertex& other) const {
    return id > other.id;
}


bool Vertex::operator<(const Vertex& other) const {
    return id < other.id;
}

std::ostream &operator<<(std::ostream &out, const Vertex &other) {
    out << other.id << (other.isMarked ? "*" : "");
    return out;
}