#include "graph.h"


int Graph::getIncidentCount(const Vertex& vertex) {
    int count = 0;
    Arc* runner = head;
    while (*this && runner == head || runner != nullptr) {
        if (runner->vertex1 == vertex) {
            ++count;
        }
        if (runner->vertex2 == vertex) {
            ++count;
        }
        runner = runner->next;
    }
    return count;
}


void Graph::unmarkAllArcs() {
    Arc* runner = head;
    while (*this && runner == head || runner != nullptr) {
        runner->isMarked = false;
        runner = runner->next;
    }
}


void Graph::unmarkAllVertices() {
    Arc* runner = head;
    while (*this && runner == head || runner != nullptr) {
        runner->vertex1.isMarked = runner->vertex2.isMarked = false;
        runner = runner->next;
    }
}


void Graph::markVertex(const Vertex& vertex) {
    Arc* runner = head;
    while (*this && runner == head || runner != nullptr) {
        if (runner->vertex1 == vertex) {
            runner->vertex1.isMarked = true;
        }
        if (runner->vertex2 == vertex) {
            runner->vertex2.isMarked = true;
        }
        runner = runner->next;
    }
}


bool Graph::isConnected() {
    // If graph is empty, it cannot be connected
    if (head == nullptr) {
        return false;
    }
    // If graph has only a loop arc, it's connected
    if (head == tail && head->vertex1 == head->vertex2) {
        return true;
    }

    auto firstVertexGroup = VertexQueue();
    depthVertexTraversal(head->vertex1, &firstVertexGroup);

    // Making new graph from found vertex group
    Graph graph;
    while (!firstVertexGroup.empty()) {
        graph.addArc(Arc(Vertex(firstVertexGroup.front()), Vertex(firstVertexGroup.front())));
        firstVertexGroup.pop();
    }

    // Checking that there's no else vertex groups
    Arc* runner = head;
    while (runner == head || runner != nullptr) {
        if (!graph.searchVertex(runner->vertex1) || !graph.searchVertex(runner->vertex2)) {
            return false;
        }
        runner = runner->next;
    }

    return true;
}


bool Graph::isEuler() {
    if (!isConnected()) {
        return false;
    }
    unmarkAllVertices();

    Arc* runner = head;
    while (runner == head || runner != nullptr) {
        if (!runner->vertex1.isMarked) {
            if (getIncidentCount(runner->vertex1) % 2) {
                return false;
            }
            markVertex(runner->vertex1);
        }
        if (!runner->vertex2.isMarked) {
            if (getIncidentCount(runner->vertex2) % 2) {
                return false;
            }
            markVertex(runner->vertex2);
        }
        runner = runner->next;
    }

    unmarkAllVertices();
    return true;
}


Arc* Graph::getIncidentArc(const Vertex &vertex, int passes) {
    Arc* runner = head;
    Arc* incidentArc = nullptr;
    while (head != nullptr && runner == head || runner != nullptr) {
        if (runner->includes(vertex)) {
            incidentArc = runner;
            if (passes == 0) {
                return incidentArc;
            }
            --passes;
        }
        runner = runner->next;
    }
    return incidentArc;
}


bool Graph::areVerticesConnected(const Vertex &vertex1, const Vertex &vertex2) {
    VertexQueue traversal;
    depthVertexTraversal(vertex1, &traversal);
    while (!traversal.empty()) {
        if (traversal.front() == vertex2) {
            return true;
        }
        traversal.pop();
    }
    return false;
}


Graph::Graph() {
    head = tail = nullptr;
}


Graph::Graph(Graph& other) {
    if (other.head != nullptr) {
        head = new Arc(*other.head);
        Arc* runner = head;
        Arc* otherRunner = other.head->next;
        while (otherRunner != nullptr) {
            runner->next = new Arc(*otherRunner);
            runner->next->prev = runner;
            runner = runner->next;
            otherRunner = otherRunner->next;
        }
        tail = runner;
    }
}


Graph::~Graph() {
    while (head) {
        tail = head->next;
        delete head;
        head = tail;
    }
}


bool Graph::addArc(const Arc& arc) {
    Arc* newArc = new Arc(arc);
    newArc->normalize();

    if (head == nullptr) {
        head = tail = newArc;
    } else {
        // This block removes adding duplicate arc
        // if (searchArc(*newArc)) {
        //     return false;
        // }

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
    }
    return true;
}


bool Graph::deleteArc(const Arc& arc) {
    Arc* current = head;

    if (*this && head == tail && *head == arc) {
        delete head;
        head = tail = nullptr;
        return true;
    }

    while (*this && current == head || current != nullptr) {
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


bool Graph::deleteVertex(const Vertex& vertex) {
    bool isFound = false;
    while (searchVertex(vertex)) {
        Arc* runner = head;
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


bool Graph::searchArc(const Arc& arc) {
    Arc* runner = head;
    while (*this && runner == head || runner != nullptr) {
        if (*runner == arc) {
            return true;
        }
        runner = runner->next;
    }
    return false;
}


bool Graph::searchVertex(const Vertex& vertex) {
    return getIncidentCount(vertex) > 0;
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


void Graph::depthArcTraversal(const Vertex& vertex, ArcQueue* buffer) {
    if (!searchVertex(vertex)) {
        if (buffer == nullptr) {
            std::cout << "This vertex does not exists" << std::endl;
        }
        return;
    }
    unmarkAllArcs();
    unmarkAllVertices();

    ArcStack arcs;
    if (buffer == nullptr) {
        std::cout << "Arcs were visited in the following order: ";
    }
    arcTraversal(arcs, vertex, buffer);
    if (buffer == nullptr) {
        std::cout << std::endl;
    }
    unmarkAllArcs();
    unmarkAllVertices();
}


void Graph::arcTraversal(ArcStack &arcs, Vertex vertex, ArcQueue* buffer) {
    // Marking the temporary id
    markVertex(vertex);
    vertex.isMarked = true;

    // Pushing all arcs outgoing from the temporary id
    Arc* runner = head;
    while (runner == head || runner != nullptr) {
        if (runner->includes(vertex)) {
            arcs.push(runner);
        }
        runner = runner->next;
    }

    // Changing the temporary id
    while (!arcs.empty()) {
        if (arcs.top()->vertex1 != vertex && !arcs.top()->vertex1.isMarked) {
            vertex = arcs.top()->vertex1;
        }
        if (arcs.top()->vertex2 != vertex && !arcs.top()->vertex2.isMarked) {
            vertex = arcs.top()->vertex2;
        }
        if (arcs.top()->vertex1.isMarked && arcs.top()->vertex2.isMarked && !arcs.top()->isMarked) {
            if (buffer == nullptr) {
                std::cout << "(" << arcs.top()->vertex1 << ", " << arcs.top()->vertex2 << ") ";
            } else {
                // May does not work, but I don't give a shit, because I won't use this
                buffer->push(arcs.top());
            }
            arcs.top()->isMarked = true;
        }
        arcs.pop();
        if (!vertex.isMarked) {
            arcTraversal(arcs, vertex, buffer);
        }
    }
}


void Graph::depthVertexTraversal(const Vertex& vertex, VertexQueue* buffer) {
    if (!searchVertex(vertex)) {
        if (buffer == nullptr) {
            std::cout << "This vertex does not exists" << std::endl;
        }
        return;
    }
    unmarkAllVertices();

    ArcStack arcs;
    if (buffer == nullptr) {
        std::cout << "Vertices were visited in the following order: " << vertex;
    } else {
        buffer->push(Vertex(vertex));
    }
    vertexTraversal(arcs, vertex, buffer);
    if (buffer == nullptr) {
        std::cout << std::endl;
    }
    unmarkAllVertices();
}


void Graph::vertexTraversal(ArcStack &arcs, Vertex vertex, VertexQueue* buffer) {
    // Marking the temporary id
    markVertex(vertex);
    vertex.isMarked = true;

    // Pushing all arcs outgoing from the temporary id
    Arc* runner = head;
    while (runner == head || runner != nullptr) {
        if (runner->includes(vertex)) {
            arcs.push(runner);
        }
        runner = runner->next;
    }

    // Changing the temporary id
    while (!arcs.empty()) {
        if (arcs.top()->vertex1 != vertex && !arcs.top()->vertex1.isMarked) {
            vertex = arcs.top()->vertex1;
        }
        if (arcs.top()->vertex2 != vertex && !arcs.top()->vertex2.isMarked) {
            vertex = arcs.top()->vertex2;
        }
        arcs.pop();
        if (!vertex.isMarked) {
            if (buffer == nullptr) {
                std::cout << ", " << vertex;
            } else {
                buffer->push(Vertex(vertex));
            }
            vertexTraversal(arcs, vertex, buffer);
        }
    }
}


void Graph::findEulerCycle(const Vertex& vertex) {
    if (!searchVertex(vertex)) {
        std::cout << "This vertex does not exists, so cycle cannot be found" << std::endl;
        return;
    }
    if (!isEuler()) {
        std::cout << "There are no euler cycles" << std::endl;
        return;
    }

    ArcQueue arcs;
    Arc* currentArc;
    Vertex currentVertex = vertex;
    int passes = 0;
    while (*this) {
        Arc* currentArcPointer = getIncidentArc(currentVertex, passes);
        if (currentArcPointer != nullptr) {
            currentArc = new Arc(*currentArcPointer);
            deleteArc(*currentArc);

            // If there are no else incident arcs, or vertices are still connected, we choose this arc
            if (getIncidentCount(currentVertex) - passes == 0 ||
                areVerticesConnected(currentArc->vertex1, currentArc->vertex2)) {
                arcs.push(currentArc);

                currentVertex = currentArc->vertex1 != currentVertex ? currentArc->vertex1 : currentArc->vertex2;
                passes = 0;
            // Just pass current arc. On the next iteration will be taken the next arc
            } else {
                addArc(*currentArc);
                ++passes;
                delete currentArc;
            }
        }
    }

    // Unpacking arcs, printing and adding back
    std::cout << "Euler cycle: " << vertex;
    currentVertex = vertex;
    while (!arcs.empty()) {
        currentVertex = arcs.front()->vertex1 != currentVertex ? arcs.front()->vertex1 : arcs.front()->vertex2;
        std::cout << " --- " << currentVertex;
        addArc(*arcs.front());
        delete arcs.front();
        arcs.pop();
    }
    std::cout << std::endl;
}


Graph::operator bool() const {
    return head != nullptr;
}