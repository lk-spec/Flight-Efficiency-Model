#include "djik.h"

using namespace std;

// Dijkstra's Search Algorithm

vector<string> Dijkstras::DijkstraSearch(Graph g, string source, string dest) {
    // base case
    if (source == dest) {
        return vector<string> {source};
    }

    vector<string> path;
    // code to implement min heap
    priority_queue<pair<double, string>, vector<pair<double, string>>, greater<pair<double, string>>> pq;
    vector<string> vertices;
    vector<Airport> airports = g.getAirports();
    map<string, string> prev;
    map<string, double> dist;
    set<string> visited;

    dist[source] = 0.0;
    prev[source] = "";

    for (unsigned i = 0; i < airports.size(); i++) {
        vertices.push_back(airports[i].getIata());
        if(airports[i].getIata() != source) {
            dist[airports[i].getIata()] = INT_MAX;
            prev[airports[i].getIata()] = "";
        }
    }

    pair<double,string> start = make_pair(0.0, source);
    pq.push(start);

    while(pq.top().second != dest) {
        pair<double, string> curr = pq.top();
        pq.pop();
        vector<pair<string, double>> neighbors = g.getAdjAirports(curr.second);

        for (unsigned i = 0; i < neighbors.size(); i++) {
            pair<string, double> n = neighbors[i];
            if (visited.find(n.first) == visited.end() && visited.find(curr.second) == visited.end()) {
                double distance = n.second;
                if (dist[curr.second] + distance < dist[n.first]) {
                    // found a neighbor with a shorter distance

                    dist[n.first] = dist[curr.second] + distance;
                    prev[n.first] = curr.second;
                    pair<double,string> next_node = make_pair(dist[n.first], n.first);
                    pq.push(next_node);
                }
            }
        }

        visited.insert(curr.second);
    }

    // reverse this path

    string key = dest;
    path.push_back(dest);
    while(key != source) {
        path.push_back(prev[key]);
        key = prev[key];
    }

    path_dist = dist[dest];
    std::reverse(path.begin(), path.end());
    return path;
}

// return the total distance of the path after dijkstra's was called

double Dijkstras::getTotalDistance() {
    return path_dist;
}

// print the output path from source to dest based on data

void Dijkstras::printDijkstraSearch(Graph g, string source, string dest) {
    vector<string> path = DijkstraSearch(g, source, dest);
    cout << "Path: ";
    for (unsigned i = 0; i < path.size() - 1; i++) {
        cout << path[i] << " -> ";
    }
    cout << path[path.size() - 1] << endl;
    cout << "total distance: " << path_dist << endl;
}