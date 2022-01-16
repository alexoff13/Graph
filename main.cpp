#include <iostream>
#include "graph.h"


int main() {
    Graph graph;

//    graph.addArc(Arc(Vertex(1), Vertex(2)));
//    graph.addArc(Arc(Vertex(2), Vertex(3)));
//    graph.addArc(Arc(Vertex(3), Vertex(4)));
//    graph.addArc(Arc(Vertex(4), Vertex(2)));
//    graph.addArc(Arc(Vertex(2), Vertex(5)));
//    graph.addArc(Arc(Vertex(5), Vertex(1)));

//    graph.addArc(Arc(Vertex(1), Vertex(2)));
//    graph.addArc(Arc(Vertex(2), Vertex(3)));
//    graph.addArc(Arc(Vertex(3), Vertex(1)));
//    graph.addArc(Arc(Vertex(1), Vertex(4)));
//    graph.addArc(Arc(Vertex(1), Vertex(3)));
//    graph.addArc(Arc(Vertex(3), Vertex(3)));
//    graph.addArc(Arc(Vertex(3), Vertex(5)));
//    graph.addArc(Arc(Vertex(4), Vertex(5)));

    graph.addArc(Arc(Vertex(1), Vertex(2)));
    graph.addArc(Arc(Vertex(1), Vertex(4)));
    graph.addArc(Arc(Vertex(1), Vertex(5)));
    graph.addArc(Arc(Vertex(1), Vertex(6)));
    graph.addArc(Arc(Vertex(2), Vertex(3)));
    graph.addArc(Arc(Vertex(2), Vertex(4)));
    graph.addArc(Arc(Vertex(2), Vertex(4)));
    graph.addArc(Arc(Vertex(3), Vertex(7)));
    graph.addArc(Arc(Vertex(3), Vertex(8)));
    graph.addArc(Arc(Vertex(3), Vertex(4)));
    graph.addArc(Arc(Vertex(4), Vertex(5)));
    graph.addArc(Arc(Vertex(4), Vertex(5)));
    graph.addArc(Arc(Vertex(5), Vertex(6)));
    graph.addArc(Arc(Vertex(8), Vertex(7)));

    graph.print();
    std::cout << std::endl;
    graph.depthTraversal(Vertex(1));
    std::cout << std::endl;
    graph.findEulerCycle(Vertex(6));

    return 0;
}