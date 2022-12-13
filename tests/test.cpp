#include <catch2/catch_test_macros.hpp>
#include <iostream> 
#include <fstream>
#include <vector>
#include "graph.h"
#include "kosaraju.h"
#include "djik.h"
#include "bfs.h"

using namespace std;


// Graph Cases

TEST_CASE ("TEST_Parse_Big") {
    Graph g("/workspaces/CS 225/final-project/225-final-project/data/airports.dat", "/workspaces/CS 225/final-project/225-final-project/data/routes.dat");
    REQUIRE(g.getAirportsSize() == 6054);
}

// test that no other airports are used

// BFS Cases

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

// Dijkstra's Cases

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

// test path between two airports with small degrees
TEST_CASE ("Dijkstra Actual") {
    Graph g("/workspaces/CS 225/final-project/225-final-project/data/airports.dat", "/workspaces/CS 225/final-project/225-final-project/data/routes.dat");
    Dijkstras d;
    d.printDijkstraSearch(g, "KHH", "OGG");
    
}
// kosaraju cases

TEST_CASE ("Kosaraju Small") {
    Graph g("/workspaces/CS 225/final-project/225-final-project/tests/k_data/k_airports.dat", "/workspaces/CS 225/final-project/225-final-project/tests/k_data/k_routes.dat");
    Kosaraju k;
    vector<vector<string>> scc = k.getSCC(g);
    REQUIRE(scc.size() == 2);
    REQUIRE(scc[0].size() + scc[1].size() == 5);
}

// TEST_CASE ("Kosaraju Big") {
//     Graph g("/workspaces/CS 225/final-project/225-final-project/data/airports.dat", "/workspaces/CS 225/final-project/225-final-project/data/routes.dat");
//     Kosaraju k;
//     k.printSCC(g);
// }

