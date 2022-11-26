#include "airport.h"

using namespace std;

Airport::Airport() {

}

Airport::Airport(int id, string name, string iata, string icao, double latitude, double longitude) {
    this->id = id;
    this->name = name;
    this->iata = iata;
    this->icao = icao;
    this->longitude = longitude;
    this->latitude = latitude;
}