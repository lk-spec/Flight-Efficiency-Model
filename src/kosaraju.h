#pragma once

#include "graph.h"
#include "airport.h"
#include <stack>
#include <set> 
#include <string> 
#include <vector>

using namespace std;

class Kosaraju {
public: 
    void dfs1(string source, Graph g);
    void dfs2(string source, Graph g);
    void KosarajuSearch(Graph g);
    void printSCC(Graph g);
    vector<vector<string>> getSCC(Graph g);

private:
    set<string> visited;
    stack<string> s;
    vector<vector<string>> scc;
};


