#pragma once
#include <string> 

using namespace std;

class Airport {
public:
    Airport();
    Airport(int id, string name, string iata, string icao, double latitude, double longitude);
    int getId();
    string getName();
    string getIata();
    string getIcao();
    double getLatitude();
    double getLongitude();

private:
    int id;
    string name;
    string iata;
    string icao;
    double longitude;
    double latitude;
};