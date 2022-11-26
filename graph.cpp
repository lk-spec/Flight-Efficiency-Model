#include "graph.h"
#include "utilities.h"

using namespace std;

Graph::Graph(string airports_file, string routes_file) {
    ifstream a_file;
    a_file.open(airports_file);
    string line;
    while (std::getline(a_file, line)) {
        vector<string> contents;
        string s = line;
        string delimiter_char = ",";
        size_t pos = 0;
        std::string token;
        while ((pos = s.find(delimiter_char)) != std::string::npos) {
            token = s.substr(0, pos);
            contents.push_back(token);
            // std::cout << token << std::endl;
            s.erase(0, pos + delimiter_char.length());

        }

        
        for (unsigned i = 0; i < contents.size(); i++) {
            string str = contents[i];
            if (str.size() >= 2 && str[0] == '\"') {
                str.erase(0, 1);
                str.erase(str.size() - 1, str.size());
            }
            std::cout << str << " ";
        }
        std::cout << "\n";

        if (contents[0] == "N" || contents[1] == "N" || contents[4] == "N" || contents[5] == "N" || contents[6] == "N" || contents[7] == "N") {
            continue; 
        }

        double latitude = stod(contents[6]);
        double longitude = stod(contents[7]);
        int id = stoi(contents[0]);

        // Airport ap(id, string(contents[1]), string(contents[4]), string(contents[5]), latitude, longitude);
        Airport ap;
        airports.push_back(ap);
        
        contents.clear();
    }
    std::cout << airports.size() << std::endl;
    a_file.close();
}

void Graph::printGraph() {
    std::cout << "This is my graph" << std::endl;
}