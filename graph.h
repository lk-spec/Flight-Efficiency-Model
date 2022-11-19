#pragma once
#include <utility>
#include <map>
#include <string>
#include <vector>
#include "airport.h"

using namespace std;

class Graph {
public:
    Graph(string airports_file, string routes_file);
    void printGraph();
private:
    map<string, vector<pair<Airport, double>>> adjlist;
};
