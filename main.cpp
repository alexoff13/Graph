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

    graph.print();
    std::cout << std::endl << std::endl;

    graph.traversal(Vertex(2));

    graph.print();
    std::cout << std::endl << std::endl;

    graph.deleteVertex(Vertex(2));

//    graph.deleteArc(Arc(Vertex(1), Vertex(2)));
//    graph.deleteArc(Arc(Vertex(1), Vertex(4)));
//    graph.deleteArc(Arc(Vertex(2), Vertex(3)));

    graph.print();

//    std::cout << "Searching for: " << 1 << " - " << graph.searchVertex(Vertex(1)) << std::endl;
//    std::cout << "Searching for: " << 2 << " - " << graph.searchVertex(Vertex(2)) << std::endl;
//    std::cout << "Searching for: " << 8 << " - " << graph.searchVertex(Vertex(8)) << std::endl;
//    std::cout << "Searching for: " << 4 << " - " << graph.searchVertex(Vertex(4)) << std::endl;
//    std::cout << "Searching for: " << 0 << " - " << graph.searchVertex(Vertex(0)) << std::endl;
//
//    std::cout << "Searching for: " << 1 << " " << 3 << " - " << graph.searchArc(Arc(Vertex(1), Vertex(3))) << std::endl;
//    std::cout << "Searching for: " << 2 << " " << 2 << " - " << graph.searchArc(Arc(Vertex(2), Vertex(2))) << std::endl;
//    std::cout << "Searching for: " << 8 << " " << 1 << " - " << graph.searchArc(Arc(Vertex(8), Vertex(1))) << std::endl;
//    std::cout << "Searching for: " << 4 << " " << 5 << " - " << graph.searchArc(Arc(Vertex(4), Vertex(5))) << std::endl;
//    std::cout << "Searching for: " << 2 << " " << 3 << " - " << graph.searchArc(Arc(Vertex(2), Vertex(3))) << std::endl;

    return 0;
}
