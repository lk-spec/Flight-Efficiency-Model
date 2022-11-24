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

        Airport ap(contents[0], contents[1], contents[4], contents[5], contents[6], contents[7]);
        
        contents.clear();
    }
    a_file.close();
}

void Graph::printGraph() {
    std::cout << "This is my graph" << std::endl;
}