#pragma once
#include <string> 

using namespace std;

class Airport {
public:
    Airport();
    Airport(int id, string name, string iata, string icao, double longitude, double latitude);
    // create getters + setters

private:
    int id;
    string name;
    string iata;
    string icao;
    double longitude;
    double latitude;
};