#include <iostream> 
#include <fstream>
#include "graph.h"
#include "kosaraju.h"
#include "djik.h"
#include "bfs.h"

using namespace std;

int main() {
    // creation of the graph (may have to change routes depending on paths)
    Graph g("/workspaces/CS 225/final-project/225-final-project/data/airports.dat", "/workspaces/CS 225/final-project/225-final-project/data/routes.dat");
    
    // exampel of BFS
    BFS b;
    b.printStepBFS(g, "ORD", 1)

    // example of Dijkstra's
    Dijkstras d;
    d.printDijkstraSearch(g, "KHH", "OGG");

    // example of Kosaraju's
    Graph h("/workspaces/CS 225/final-project/225-final-project/tests/k_data/k_airports.dat", "/workspaces/CS 225/final-project/225-final-project/tests/k_data/k_routes.dat");
    Kosaraju k;
    k.printSCC(g);
    
    return 0;
}