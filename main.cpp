#include <iostream>
#include "graph.h"


int main() {
    Graph graph;

    graph.addArc(Arc(Vertex(1), Vertex(2)));
    graph.addArc(Arc(Vertex(1), Vertex(2)));
    graph.addArc(Arc(Vertex(2), Vertex(2)));
    graph.addArc(Arc(Vertex(1), Vertex(3)));
    graph.addArc(Arc(Vertex(3), Vertex(1)));
    graph.addArc(Arc(Vertex(2), Vertex(1)));
    graph.addArc(Arc(Vertex(4), Vertex(1)));
    graph.addArc(Arc(Vertex(8), Vertex(1)));
    graph.addArc(Arc(Vertex(4), Vertex(1)));
    graph.addArc(Arc(Vertex(4), Vertex(1)));
    graph.addArc(Arc(Vertex(2), Vertex(3)));
    graph.addArc(Arc(Vertex(6), Vertex(7)));
    graph.addArc(Arc(Vertex(6), Vertex(0)));

    graph.print();
    std::cout << std::endl;
    graph.depthTraversal(Vertex(4));

    return 0;
}
