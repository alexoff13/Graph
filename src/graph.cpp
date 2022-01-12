#include "graph.h"


void Graph::unmarkAllVertices() {
    Arc* runner = head;
    while (runner == head || runner != nullptr) {
        runner->vertex1.isMarked = runner->vertex2.isMarked = false;
        runner = runner->next;
    }
}


void Graph::markVertex(Vertex vertex) {
    Arc* runner = head;
    while (runner == head || runner != nullptr) {
        if (runner->vertex1 == vertex) {
            runner->vertex1.isMarked = true;
        }
        if (runner->vertex2 == vertex) {
            runner->vertex2.isMarked = true;
        }
        runner = runner->next;
    }
}


Graph::Graph() {
    head = tail = nullptr;
}


Graph::~Graph() {
    while (head) {
        tail = head->next;
        delete head;
        head = tail;
    }
}


bool Graph::addArc(Arc arc) {
    Arc* newArc = new Arc(arc);
    newArc->normalize();

    if (head == nullptr) {
        head = tail = newArc;
        return true;
    } else {
        if (searchArc(*newArc)) {
            return false;
        }

        Arc *current = head;
        while (current == head || current != nullptr) {
            if (newArc->vertex1 == current->vertex1 && newArc->vertex2 < current->vertex2 ||
                newArc->vertex1 < current->vertex1) {
                if (current->prev == nullptr) {
                    newArc->next = current;
                    current->prev = newArc;
                    head = newArc;
                } else {
                    current->prev->next = newArc;
                    newArc->prev = current->prev;
                    current->prev = newArc;
                    newArc->next = current;
                }
                return true;
            }
            current = current->next;
        }

        tail->next = newArc;
        newArc->prev = tail;
        tail = newArc;

        return true;
    }
}


bool Graph::deleteArc(Arc arc) {
    Arc* current = head;

    if (head == tail && *head == arc) {
        delete head;
        head = tail = nullptr;
    }

    while (current == head || current != nullptr) {
        if (*current == arc) {
            if (current == head) {
                head = current->next;
                head->prev = nullptr;
            } else if (current == tail) {
                tail = current->prev;
                tail->next = nullptr;
            } else {
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }
            delete current;
            return true;
        }
        current = current->next;
    }

    return false;
}


bool Graph::deleteVertex(Vertex vertex) {
    bool isFound = false;
    while (searchVertex(vertex)) {
        Arc *runner = head;
        while (runner == head || runner != nullptr) {
            if (runner->includes(vertex)) {
                isFound = deleteArc(Arc(runner->vertex1, runner->vertex2));
                break;
            }
            runner = runner->next;
        }
    }
    return isFound;
}


bool Graph::searchArc(Arc arc) {
    Arc* runner = head;
    while (runner == head || runner != nullptr) {
        if (*runner == arc) {
            return true;
        }
        runner = runner->next;
    }
    return false;
}


bool Graph::searchVertex(Vertex vertex) {
    Arc* runner = head;
    while (runner == head || runner != nullptr) {
        if (runner->vertex1 == vertex || runner->vertex2 == vertex) {
            return true;
        }
        runner = runner->next;
    }
    return false;
}


void Graph::print() {
    if (head == nullptr) {
        std::cout << "Graph is empty" << std::endl;
    } else {
        Arc* runner = head;
        while (runner == head || runner != nullptr) {
            std::cout << *runner << std::endl;
            runner = runner->next;
        }
    }
}


void Graph::depthTraversal(Vertex vertex) {
    if (!searchVertex(vertex)) {
        std::cout << "This vertex does not exists";
    }
    unmarkAllVertices();

    ArcStack arcs;
    std::cout << "Vertices were visited in the following order: " << vertex;
    vertexTraversal(arcs, vertex);
    std::cout << std::endl;
    unmarkAllVertices();
}


void Graph::vertexTraversal(ArcStack &arcs, Vertex vertex) {
    // Marking the temporary vertex
    markVertex(vertex);
    vertex.isMarked = true;

    // Pushing all arcs outgoing from the temporary vertex
    Arc* runner = head;
    while (runner == head || runner != nullptr) {
        if (runner->includes(vertex)) {
            arcs.push(runner);
        }
        runner = runner->next;
    }

    // Changing the temporary vertex
    while (!arcs.empty()) {
        if (arcs.top()->vertex1 != vertex && !arcs.top()->vertex1.isMarked) {
            vertex = arcs.top()->vertex1;
        }
        if (arcs.top()->vertex2 != vertex && !arcs.top()->vertex2.isMarked) {
            vertex = arcs.top()->vertex2;
        }
        arcs.pop();
        if (!vertex.isMarked) {
            std::cout << ", " << vertex;
            vertexTraversal(arcs, vertex);
        }
    }
}




