#include "kosaraju.h"

using namespace std;

// dfs on the transposed graph to get the right order of nodes in the stack

void Kosaraju::dfs1(string source, Graph g) {
    visited.insert(source);
    vector<pair<string, double>> neighbors = g.getAdjAirports(source); 
    for (unsigned i = 0; i < neighbors.size(); i++) {
        if (visited.find(neighbors[i].first) == visited.end()) {
            dfs1(neighbors[i].first, g);
        }
    }

    s.push(source);
}

// second dfs to get sccs

void Kosaraju::dfs2(string source, Graph g) {
    visited.insert(source);
    scc.back().push_back(source);
    vector<pair<string, double>> neighbors = g.getAdjAirports(source);
    for (unsigned i = 0; i < neighbors.size(); i++) {
        if (visited.find(neighbors[i].first) == visited.end()) {
            dfs2(neighbors[i].first, g);
        }
    }
}

// main Kosaraju algorithm

void Kosaraju::KosarajuSearch(Graph g) {
    vector<Airport> airports = g.getAirports();
    for (unsigned i = 0; i < airports.size(); i++) {
        if (visited.find(airports[i].getIata()) == visited.end()) {
            dfs1(airports[i].getIata(), g.transposeGraph(g));
        }
    }

    visited.clear();
    while (!s.empty()) {
        string curr = s.top();
        s.pop();

        if (visited.find(curr) == visited.end()) {
            scc.emplace_back();
            dfs2(curr, g);
        }
    }
}

// print the strongly connected components in a more fashionable way

void Kosaraju::printSCC(Graph g) {
    KosarajuSearch(g);
    for (unsigned i = 0; i < scc.size(); i++) {
        cout << "SCC" << i << ": ";
        for (unsigned j = 0; j < scc[i].size(); j++) {
            cout << scc[i][j] << ", ";
        }
        cout << "\n";
    }
}

// returns the actuall list of scc (useful for testing)

vector<vector<string>> Kosaraju::getSCC(Graph g) {
    KosarajuSearch(g);
    return scc;
}