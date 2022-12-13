#pragma once

#include "graph.h"
#include "airport.h"
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;

/* Object implementation for performing BFS search on a graph G */

class BFS {
public:

    // BFS implmentation that returns all airports that are n steps away from the source vector
    vector<string> stepBFS(Graph g, string source, int steps);

    // helper method to print the output
    void printStepBFS(Graph g, string source, int steps);

};