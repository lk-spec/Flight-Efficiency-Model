#pragma once
#include "graph.h"
#include "airport.h"

#include <vector>
#include <map>
#include <queue>
#include <string>
#include <iostream>
#include <algorithm>
#include <set>
#include <queue>
#include <limits.h>

using namespace std;

/* Object implementation for performing Dijkstra's algorithm on a graph g */

class Dijkstras {
    public:
        // method for performing Dijkstra's algorithm given a source and destination airport
        vector<string> DijkstraSearch(Graph g, string source, string dest);

        // returns the total distance of the path after dijkstra's was run
        double getTotalDistance();

        // helper to print the shortest path 
        void printDijkstraSearch(Graph g, string source, string dest);

    private:
        // private field to store the path_dist
        double path_dist;
};

