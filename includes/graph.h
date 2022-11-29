#pragma once
#include <utility>
#include <map>
#include <string>
#include <vector>
#include <fstream>
#include <unordered_map>
#include "airport.h"
#include "utilities.h"

using namespace std;

class Graph {
public:
    Graph(string airports_file, string routes_file);
    void printGraph();
    void printAirports();
    void generateCodesMap();
private:
    map<string, vector<pair<string, double>>> adjlist;
    map<string, Airport> airport_codes;
    vector<Airport> airports;
};
