#include <catch2/catch_test_macros.hpp>
#include <iostream> 
#include <fstream>
#include "graph.h"

TEST_CASE ("TEST_Parse_Big") {
    Graph g("/workspaces/CS 225/final-project/225-final-project/data/airports.dat", "/workspaces/CS 225/final-project/225-final-project/data/routes.dat");
    REQUIRE(g.getAirportsSize() == 6054);
}
