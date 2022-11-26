#pragma once
#include <string> 

using namespace std;

class Airport {
public:
    Airport();
    Airport(int id, string name, string iata, string icao, double latitude, double longitude);
    // create getters + setters
    // create method to print an Airport's contents for testing purposes

private:
    int id;
    string name;
    string iata;
    string icao;
    double longitude;
    double latitude;
};