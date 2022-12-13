#pragma once

#include "graph.h"
#include "airport.h"
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;

class BFS {
public:
    vector<string> stepBFS(Graph g, string source, int steps);
    void printStepBFS(Graph g, string source, int steps);
private:

};