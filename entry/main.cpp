#include <iostream> 
#include <fstream>
#include "graph.h"
#include "kosaraju.h"
#include "bfs.h"

using namespace std;

int main() {
    // creation of the graph
    Graph g("/workspaces/CS 225/final-project/225-final-project/tests/b_data/b_airports.dat", "/workspaces/CS 225/final-project/225-final-project/tests/b_data/b_routes.dat");
    // Graph h("data/airports.dat", "data/routes.dat");
    // methods we used for testing our graph
    
    // prints the list of valid airports after parsing
    // g.printAirports();

    // prints the graph in an adjacency list format
    // Graph h = g.transposeGraph(g);
    // h.printOutgoingFlights("CEB");
    BFS b;
    vector<string> bfs = b.stepBFS(g, "BOS", 6);
    for (unsigned i = 0; i < bfs.size(); i++){
        std::cout << bfs[i] << endl;
    }
    // prints the list of outgoing flights from a specific airport
    // g.printOutgoingFlights("CMI");
    // Kosaraju k;
    // g.printGraph();
    // k.printSCC(g);
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