#include "utilities.h"

using namespace std;

// helper method to split a line in csv file to a vector of strings

vector<string> split_line(string line) {
    vector<string> contents;
    string s = line;
    string delimiter_char = ",";
    size_t pos = 0;
    std::string token;
    while ((pos = s.find(delimiter_char)) != std::string::npos) {
        token = s.substr(0, pos);
        contents.push_back(token);
        s.erase(0, pos + delimiter_char.length());

    }
    
    return contents;
}