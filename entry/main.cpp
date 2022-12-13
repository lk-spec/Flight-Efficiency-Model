#include <iostream> 
#include <fstream>
#include "graph.h"
#include "kosaraju.h"
#include "djik.h"
#include "bfs.h"

using namespace std;

int main() {
    // creation of the graph
    Graph g("/workspaces/CS 225/final-project/225-final-project/data/airports.dat", "/workspaces/CS 225/final-project/225-final-project/data/routes.dat");
    // Graph h("data/airports.dat", "data/routes.dat");
    // methods we used for testing our graph
    
    // prints the list of valid airports after parsing
    // g.printAirports();

    // prints the graph in an adjacency list format
    // Graph h = g.transposeGraph(g);
    // h.printOutgoingFlights("CEB");
    // BFS b;
    // vector<string> bfs = b.stepBFS(g, "BOS", 6);
    // for (unsigned i = 0; i < bfs.size(); i++) {
    //     std::cout << bfs[i] << endl;
    // }
    // prints the list of outgoing flights from a specific airport
    // g.printOutgoingFlights("CMI");
    // Kosaraju k;
    // g.printGraph();
    // k.printSCC(g);
    // cout << g.getDistance("ORD", "ATL") << endl;
    Dijkstras d;
    d.printDijkstraSearch(g, "KHH", "OGG");

    return 0;
}