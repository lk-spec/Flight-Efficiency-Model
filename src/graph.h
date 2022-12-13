#pragma once
#include <utility>
#include <map>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cmath>
#include "airport.h"
#include "utilities.h"

using namespace std;

class Graph {
public:
    Graph();
    Graph(string airports_file, string routes_file);
    void printGraph();
    void printAirports();
    void generateCodesMap();
    void printOutgoingFlights(string airport);
    unsigned getNumOutgoingFlights(string airport);
    unsigned getAirportsSize();
    vector<Airport> getAirports();
    string getRandomSource();
    vector<pair<string, double>> getAdjAirports(string airport);
    Airport getAirportObj(string airport);
    static Graph transposeGraph(const Graph& g);
    long double calcDistance(string source, string dest);
    long double toRadians(const long double degree);
    double getDistance(string source, string dest);

private:
    map<string, vector<pair<string, double>>> adjlist;
    map<string, vector<string>> adjlistNoDist;
    map<string, Airport> airport_codes;
    vector<Airport> airports;
};


