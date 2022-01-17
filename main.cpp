#include <iostream>
#include "graph.h"


int main() {
    Graph graph;

//    graph.addArc(Arc(Vertex(1), Vertex(6)));
//    graph.addArc(Arc(Vertex(1), Vertex(7)));
//    graph.addArc(Arc(Vertex(6), Vertex(7)));
//    graph.addArc(Arc(Vertex(7), Vertex(5)));
//    graph.addArc(Arc(Vertex(5), Vertex(3)));
//    graph.addArc(Arc(Vertex(7), Vertex(3)));

    for (int i = 1;i < 10; ++i) {
        graph.addArc(Arc(Vertex(i), Vertex(i + 1)));
        graph.addArc(Arc(Vertex(i), Vertex(2 * i)));
    }
    graph.print();
    std::cout << std::endl;

    for (int i = 1; i < 11; i += 2) {
        graph.deleteVertex(Vertex(i));
    }
    graph.print();
    std::cout << std::endl;

    for (int i = 1;i < 10; ++i) {
        graph.addArc(Arc(Vertex(i), Vertex(i + 1)));
        graph.addArc(Arc(Vertex(i), Vertex(2 * i)));
    }
    graph.print();
    std::cout << std::endl;

    std::cout << std::endl;
    graph.depthVertexTraversal(Vertex(1));
    std::cout << std::endl;
    graph.depthArcTraversal(Vertex(1));
    std::cout << std::endl;
    graph.findEulerCycle(Vertex(1));

    return 0;
}