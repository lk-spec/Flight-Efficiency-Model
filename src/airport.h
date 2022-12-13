#pragma once
#include <string> 

using namespace std;

/* Object implementation for our node/vertex */

class Airport {
public:
    // constructors 
    Airport();
    Airport(int id, string name, string iata, string icao, double latitude, double longitude);

    // getters for accessing atributes
    int getId();
    string getName();
    string getIata();
    string getIcao();
    double getLatitude();
    double getLongitude();

private:
    // data fields
    int id;
    string name;
    string iata;
    string icao;
    double longitude;
    double latitude;
};