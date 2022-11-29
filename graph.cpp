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

    // this creates a list of aiport nodes
    // using that list and the routes file, we need to create a list of valid routes, which we can then use to create the edges of the graoph
    // for the distance portion of each edge (double) we will have to create a helper function to calculate that distance
    a_file.close();
}

void Graph::printGraph() {
    std::cout << "This is my graph" << std::endl;
}
// created branch
void Graph::printAirports() {
    for (unsigned i = 0; i < airports.size(); i++) {
        std::cout << airports[i].getId() << " " << airports[i].getName() << " " << airports[i].getIata() << " " << airports[i].getIcao() << " " << airports[i].getLatitude() << " " << airports[i].getLongitude() << std::endl; 
    }
    std::cout << airports.size() << std::endl;
}