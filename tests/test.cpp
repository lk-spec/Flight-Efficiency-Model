#include <catch2/catch_test_macros.hpp>
#include <iostream> 
#include <fstream>
#include <vector>
#include "graph.h"
#include "kosaraju.h"

using namespace std;

TEST_CASE ("TEST_Parse_Big") {
    Graph g("/workspaces/CS 225/final-project/225-final-project/data/airports.dat", "/workspaces/CS 225/final-project/225-final-project/data/routes.dat");
    REQUIRE(g.getAirportsSize() == 6054);
}

// test that no other airports are used


// kosaraju cases

TEST_CASE ("Kosaraju Small") {
    Graph g("/workspaces/CS 225/final-project/225-final-project/tests/k_data/k_airports.dat", "/workspaces/CS 225/final-project/225-final-project/tests/k_data/k_routes.dat");
    Kosaraju k;
    vector<vector<string>> scc = k.getSCC(g);
    REQUIRE(scc.size() == 2);
    REQUIRE(scc[0].size() + scc[1].size() == 5);
}

TEST_CASE ("Kosaraju Big") {
    Graph g("/workspaces/CS 225/final-project/225-final-project/data/airports.dat", "/workspaces/CS 225/final-project/225-final-project/data/routes.dat");
    Kosaraju k;
    k.printSCC(g);
}
