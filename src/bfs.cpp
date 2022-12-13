#include "bfs.h"

vector<string> BFS::stepBFS(Graph g, string source, int steps) {
    queue<string> q;
    set<string> visited;
    map<string, int> step_count;
    vector<string> out;
    
    if (steps <= 0) {
        return out;
    }

    q.push(source);
    visited.insert(source);
    step_count[source] = 0;

    while (!q.empty()) {
        string curr = q.front();
        q.pop();

        if (step_count[curr] > steps) {
            break;
        } else if (step_count[curr] == steps) {
            out.push_back(curr);
            continue;
        }


        vector<pair<string, double>> neighbors = g.getAdjAirports(curr);
        for (unsigned i = 0; i < neighbors.size(); i++) {
            if (visited.find(neighbors[i].first) == visited.end()) {
                visited.insert(neighbors[i].first);
                q.push(neighbors[i].first);
                step_count[neighbors[i].first] = step_count[curr] + 1;
            }
        }
    }

    return out;

}

void BFS::printStepBFS(Graph g, string source, int steps) {
    vector<string> bfs = stepBFS(g, source, steps);
    cout << "airports that are " << steps << " flight(s) away from " << source << ": ";
    for (unsigned i = 0; i < bfs.size(); i++){
        cout << bfs[i] << " ";
    }
    cout << "\n";
}