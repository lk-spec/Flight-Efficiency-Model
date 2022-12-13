#include <catch2/catch_test_macros.hpp>
#include <iostream> 
#include <fstream>
#include <vector>
#include "graph.h"
#include "kosaraju.h"
#include "djik.h"
#include "bfs.h"

using namespace std;


/* Graph Building Cases */

// ensure that only the valid nodes are read (after parsing we discovered that there were 6054 valid airports 

TEST_CASE ("TEST_Parse_Big") {
    Graph g("/workspaces/CS 225/final-project/225-final-project/data/airports.dat", "/workspaces/CS 225/final-project/225-final-project/data/routes.dat");
    REQUIRE(g.getAirportsSize() == 6054);
}

/* BFS Cases */

// BFS test using our own small graph

TEST_CASE ("BFS Basic") {
    Graph g("/workspaces/CS 225/final-project/225-final-project/tests/b_data/b_airports.dat", "/workspaces/CS 225/final-project/225-final-project/tests/b_data/b_routes.dat");
    BFS b;
    vector<string> bfs = b.stepBFS(g, "BOS", 0);
    REQUIRE (bfs.size() == 0);
    bfs = b.stepBFS(g, "BOS", -1);
    REQUIRE (bfs.size() == 0);
}

TEST_CASE ("BFS Edge") {
    Graph g("/workspaces/CS 225/final-project/225-final-project/tests/b_data/b_airports.dat", "/workspaces/CS 225/final-project/225-final-project/tests/b_data/b_routes.dat");
    BFS b;
    // too far
    vector<string> bfs = b.stepBFS(g, "ORD", 6);
    REQUIRE (bfs.size() == 0);
    // single case
    bfs = b.stepBFS(g, "BOS", 4);
    REQUIRE (bfs.size() == 1);
}

TEST_CASE ("BFS Regular") {
    Graph g("/workspaces/CS 225/final-project/225-final-project/tests/b_data/b_airports.dat", "/workspaces/CS 225/final-project/225-final-project/tests/b_data/b_routes.dat");
    BFS b;
    vector<string> bfs = b.stepBFS(g, "ORD", 1);
    REQUIRE (bfs.size() == 4);

    bfs = b.stepBFS(g, "ORD", 2);
    REQUIRE (bfs.size() == 5);

    bfs = b.stepBFS(g, "ORD", 3);
    REQUIRE (bfs.size() == 1);
}

TEST_CASE ("BFS Big") {
    Graph g("/workspaces/CS 225/final-project/225-final-project/data/airports.dat", "/workspaces/CS 225/final-project/225-final-project/data/routes.dat");
    BFS b;
    vector<string> bfs = b.stepBFS(g, "ORD", 1);
    REQUIRE(bfs.size() == g.getNumOutgoingFlights("ORD"));
}

/* Dijkstra's Cases */ 

// shortest routes are based on real life distances between the airports in the graph

TEST_CASE ("Dijkstra Small") {
    Graph g("/workspaces/CS 225/final-project/225-final-project/tests/d_data/d_airports.dat", "/workspaces/CS 225/final-project/225-final-project/tests/d_data/d_routes.dat");
    Dijkstras d;
    vector<string> path = d.DijkstraSearch(g, "LAX", "JFK");
    vector<string> expected {"LAX", "ORD", "JFK"};
    REQUIRE (path == expected);
}

TEST_CASE ("Dijkstra Small 2") {
    Graph g("/workspaces/CS 225/final-project/225-final-project/tests/d_data/d_airports.dat", "/workspaces/CS 225/final-project/225-final-project/tests/d_data/d_routes.dat");
    Dijkstras d;
    vector<string> path = d.DijkstraSearch(g, "ORD", "JFK");
    vector<string> expected {"ORD", "JFK"};
    REQUIRE (path == expected);
}

TEST_CASE ("Dijkstras Complex") {
    Graph g("/workspaces/CS 225/final-project/225-final-project/tests/b_data/b_airports.dat", "/workspaces/CS 225/final-project/225-final-project/tests/b_data/b_routes_alt");
    Dijkstras d;
    vector<string> path = d.DijkstraSearch(g, "LHR", "SFO");
    vector<string> expected {"LHR", "DEN", "SFO"};
    REQUIRE (path == expected);
}

// test path between two airports with small degrees on actual dataset

TEST_CASE ("Dijkstra Actual") {
    Graph g("/workspaces/CS 225/final-project/225-final-project/data/airports.dat", "/workspaces/CS 225/final-project/225-final-project/data/routes.dat");
    Dijkstras d;
    d.printDijkstraSearch(g, "KHH", "OGG");
    
}
// kosaraju cases

// test on a small graph, located in the tests directory 

TEST_CASE ("Kosaraju Small") {
    Graph g("/workspaces/CS 225/final-project/225-final-project/tests/k_data/k_airports.dat", "/workspaces/CS 225/final-project/225-final-project/tests/k_data/k_routes.dat");
    Kosaraju k;
    vector<vector<string>> scc = k.getSCC(g);
    REQUIRE(scc.size() == 2);
    REQUIRE(scc[0].size() + scc[1].size() == 5);
}

/* test on actual graph was unable to work (we believe this is due to the high volume of recursive calls 
    or the graph representation of the actual dataset), but we were unable to diagnose this issue
*/

// TEST_CASE ("Kosaraju Big") {
//     Graph g("/workspaces/CS 225/final-project/225-final-project/data/airports.dat", "/workspaces/CS 225/final-project/225-final-project/data/routes.dat");
//     Kosaraju k;
//     k.printSCC(g);
// }

