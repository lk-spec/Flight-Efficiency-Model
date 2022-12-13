#pragma once
#include "graph.h"
#include "plane.h"
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

class Dijkstras {
    public:
        vector<string> DijkstraSearch(Graph g, string source, string dest);
        double getTotalDistance();
        void printDijkstraSearch(Graph g, string source, string dest);
    private:
        double path_dist;
};

