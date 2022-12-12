#include <iostream> 
#include <fstream>
#include "graph.h"
#include "kosaraju.h"

using namespace std;

int main() {
    // creation of the graph
    Graph g("test_data/k_airports.dat", "test_data/k_routes.dat");
    Graph h("data/airports.dat", "data/routes.dat");
    // methods we used for testing our graph
    
    // prints the list of valid airports after parsing
    // g.printAirports();

    // prints the graph in an adjacency list format
    // g.printGraph();

    // prints the list of outgoing flights from a specific airport
    // g.printOutgoingFlights("CMI");
    Kosaraju k;
    // g.printGraph();
    k.printSCC(h);
    // cout << g.getDistance("ORD", "ATL") << endl;

    return 0;
}

// plans for future
// refactor the code add helper methods and make it cleaner
// implement our three algorithms: BFS, Dijkstra's, and Kosaraju's
// write test cases for the algorithm

// questions:
// how to make a makefile and test out implementation
// is the best way that it's implemented and if not what can we do to change it
// do you think it is feasible with this implementation to correctly design the 3 algorithms
// how can we make so that we don't have to change the path on another person's device
// can we cin the file paths? 
// dynamic file path (figure out a way)