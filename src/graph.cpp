#include "graph.h"

using namespace std;

Graph::Graph() {}

Graph::Graph(string airports_file, string routes_file) {
    ifstream a_file;
    a_file.open(airports_file);
    string line;

    while (std::getline(a_file, line)) {
        vector<string> contents = split_line(line);

        // create helper method to clean contents
        for (unsigned i = 0; i < contents.size(); i++) {
            string str = contents[i];
            // code to remove quotes within string
            if (str.size() >= 2 && str[0] == '\"') {
                str.erase(0, 1);
                str.erase(str.size() - 1, str.size());
            }
            contents[i] = str;
            // std::cout << str << " ";
        }
        // std::cout << "\n";

        // also create helper method to validate content
        // check if content is valid; 
        if (contents[0] == "N" || contents[1] == "N" || contents[4] == "N" || contents[5] == "N" || contents[6] == "N" || contents[7] == "N" || 
            contents[0] == "\\N" || contents[1] == "\\N" || contents[4] == "\\N" || contents[5] == "\\N" || contents[6] == "\\N" || contents[7] == "\\N") {
            continue; 
        }

        int id = 0;
        double latitude = 0;
        double longitude = 0;
        try {
            latitude = stod(contents[6]);
            longitude = stod(contents[7]);
            id = stoi(contents[0]);
        } catch (std::invalid_argument) {
            continue;
        }

        Airport ap(id, string(contents[1]), string(contents[4]), string(contents[5]), latitude, longitude);
        airports.push_back(ap);
        contents.clear();

    }

    a_file.close();
    generateCodesMap();

    ifstream r_file;
    r_file.open(routes_file);
    line = "";
    while (std::getline(r_file, line)) {
        vector<string> contents = split_line(line);

        // create helper method to clean contents
        for (unsigned i = 0; i < contents.size(); i++) {
            string str = contents[i];
            // code to remove quotes within string
            if (str.size() >= 2 && str[0] == '\"') {
                str.erase(0, 1);
                str.erase(str.size() - 1, str.size());
            }
            contents[i] = str;
        }
        
        if (airport_codes.find(contents[2]) == airport_codes.end()) {
            continue;
        }

        if (airport_codes.find(contents[4]) == airport_codes.end()) {
            continue;
        }

        double d = calcDistance(contents[2], contents[4]);
        pair<string, double> edge = make_pair(contents[4], d);
        // adjlist[contents[2]].push_back(edge);
        if(find(adjlistNoDist[contents[2]].begin(), adjlistNoDist[contents[2]].end(), contents[4]) == adjlistNoDist[contents[2]].end()) {
            adjlist[contents[2]].push_back(edge);
            adjlistNoDist[contents[2]].push_back(contents[4]);
        }
        
    }

    r_file.close();
}

void Graph::generateCodesMap() {
    for (unsigned i = 0; i < airports.size(); i++) {
        airport_codes[airports[i].getIata()] = airports[i];
    }
}

void Graph::printGraph() {
    for (auto & key_val : adjlist) {
        cout << key_val.first << " -> ";
        for (unsigned i = 0; i < key_val.second.size(); i++) {
            cout << key_val.second[i].first << " ";
        }
        cout << "\n";
    }
}

void Graph::printOutgoingFlights(string airport) {
    cout << airport << " -> ";
    for (unsigned i = 0; i < adjlist[airport].size(); i++) {
        cout << adjlist[airport][i].first << " ";
    }
    cout << adjlist[airport].size() << std::endl;
}

void Graph::printAirports() {
    for (unsigned i = 0; i < airports.size(); i++) {
        std::cout << airports[i].getId() << " " << airports[i].getName() << " " << airports[i].getIata() << " " << airports[i].getIcao() << " " << airports[i].getLatitude() << " " << airports[i].getLongitude() << std::endl; 
    }
    std::cout << airports.size() << std::endl;
}

unsigned Graph::getAirportsSize() {
    return airports.size();
}

string Graph::getRandomSource() {
    return airports[0].getIata();
}

vector<pair<string, double>> Graph::getAdjAirports(string airport) {
    if (adjlist.find(airport) != adjlist.end() && adjlist[airport].size() != 0) {
        return adjlist[airport];
    }
    vector<pair<string, double>> v;
    return v;
}

Airport Graph::getAirportObj(string airport) {
    return airport_codes[airport];
}

vector<Airport> Graph::getAirports() {
    return airports;
}

// static helper functions

Graph Graph::transposeGraph(const Graph& g) {
    Graph h;
    h.airports = g.airports;
    h.airport_codes = g.airport_codes;
    for (auto & p : g.adjlist) {
        for (unsigned i = 0; i < p.second.size(); i++) {
            pair<string, double> edge = make_pair(p.first, p.second[i].second);
            h.adjlist[p.second[i].first].push_back(edge);
        }
    }
    return h;
}

// code to calculate lat/long distance, adapted from https://www.geeksforgeeks.org/program-distance-two-points-earth/
long double Graph::calcDistance(string source, string dest) {
    // Convert the latitudes
    // and longitudes
    // from degree to radians.
    Airport s = airport_codes[source];
    Airport d = airport_codes[dest];
    long double lat1 = toRadians(s.getLatitude());
    long double long1 = toRadians(s.getLongitude());
    long double lat2 = toRadians(d.getLatitude());
    long double long2 = toRadians(d.getLongitude());
     
    // Haversine Formula
    long double dlong = long2 - long1;
    long double dlat = lat2 - lat1;
 
    long double ans = pow(sin(dlat / 2), 2) +
                          cos(lat1) * cos(lat2) *
                          pow(sin(dlong / 2), 2);
 
    ans = 2 * asin(sqrt(ans));
 
    // Radius of Earth in
    // Kilometers, R = 6371
    // Use R = 3956 for miles
    long double R = 6371;
     
    // Calculate the result
    ans = ans * R;
 
    return ans;
}

long double Graph::toRadians(const long double degree) {
    // cmath library in C++
    // defines the constant
    // M_PI as the value of
    // pi accurate to 1e-30
    long double one_deg = (M_PI) / 180;
    return (one_deg * degree);
}

double Graph::getDistance(string source, string dest) {
    return calcDistance(source, dest);
}

unsigned Graph::getNumOutgoingFlights(string airport) {
    if (adjlist.find(airport) != adjlist.end() && adjlist[airport].size() != 0) {
        return adjlist[airport].size();
    }
    return 0;
}