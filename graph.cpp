#include "graph.h"

using namespace std;

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
            // if (i == 2 || i == 4) {
            //     std::cout << str << " ";
            // }
        }
        
        if (airport_codes.find(contents[2]) == airport_codes.end()) {
            continue;
        }

        if (airport_codes.find(contents[4]) == airport_codes.end()) {
            continue;
        }

        Airport source = airport_codes[contents[2]];
        Airport dest = airport_codes[contents[4]];
        // double distance = calcDistance(source, dest);
        double d = 0;
        pair<string, double> edge = make_pair(contents[4], d);
        adjlist[contents[2]].push_back(edge);
    }

    r_file.close();
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
    cout << adjlist[airport].size();
}

void Graph::printAirports() {
    for (unsigned i = 0; i < airports.size(); i++) {
        std::cout << airports[i].getId() << " " << airports[i].getName() << " " << airports[i].getIata() << " " << airports[i].getIcao() << " " << airports[i].getLatitude() << " " << airports[i].getLongitude() << std::endl; 
    }
    std::cout << airports.size() << std::endl;
}

void Graph::generateCodesMap() {
    for (unsigned i = 0; i < airports.size(); i++) {
        airport_codes[airports[i].getIata()] = airports[i];
    }
}