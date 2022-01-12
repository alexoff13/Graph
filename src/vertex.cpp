#include "vertex.h"


Vertex::Vertex(int id, bool isMarked) {
    this->id = id;
    this->isMarked = isMarked;
}


bool Vertex::operator==(Vertex other) const {
    return id == other.id;
}


bool Vertex::operator!=(Vertex other) const {
    return id != other.id;
}


bool Vertex::operator>(Vertex other) const {
    return id > other.id;
}


bool Vertex::operator<(Vertex other) const {
    return id < other.id;
}


std::ostream &operator<<(std::ostream &out, const Vertex &other) {
    out << other.id << (other.isMarked ? "*" : "");
    return out;
}