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
    // default constructor
    Graph();

    // constructor that takes in file paths
    Graph(string airports_file, string routes_file);

    // helpers to print graph/nodes
    void printGraph();

    void printAirports();

    // generates a map from IATA codes to their corresponding airport object
    void generateCodesMap();

    // helper to print adjacent nodes
    void printOutgoingFlights(string airport);

    // helper to get number of adjacent nodes
    unsigned getNumOutgoingFlights(string airport);

    unsigned getAirportsSize();

    // retreive list of nodes in the graph
    vector<Airport> getAirports();

    // generate a random vertex (was unused)
    string getRandomSource();

    // get list of neighboring nodes
    vector<pair<string, double>> getAdjAirports(string airport);

    // get the airport representation of the object
    Airport getAirportObj(string airport);

    // method to transpose graph for Kosaraju's
    static Graph transposeGraph(const Graph& g);

    // methods to calc long/lat distance adapted from GeeksForGeeks
    long double calcDistance(string source, string dest);
    long double toRadians(const long double degree);

    // Get the distance between two nodes connected by an edge
    double getDistance(string source, string dest);

private:
    // adjacency list representation of graph
    map<string, vector<pair<string, double>>> adjlist; 
    // <source> -> vector {<dest, distance>, ... }
    map<string, vector<string>> adjlistNoDist;
    // map IATA codes to airport objects
    map<string, Airport> airport_codes;
    // list of vertices
    vector<Airport> airports;
};


