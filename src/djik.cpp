#include "djik.h"

using namespace std;

// Djikstras::Djikstras(Graph g, string StartAirport, string DestAirport) 
// {
//     path_vertices.clear();
//     vector<string> vertices;  

//     unordered_map<int, Airport> airportMap = g.getVertices();

//     for (auto it = airportMap.begin(); it != airportMap.end(); ++it) {
//         vertices.push_back(it->second.getAirportName());
//         if(it->second.getAirportName() == StartAirport) {
//             dist.insert(make_pair(it->second.getAirportName(), 0.0));
//             prev.insert(make_pair(it->second.getAirportName(), ""));
//             visited.insert(make_pair(it->second.getAirportName(), false));
//         }
//         else {
//             dist.insert(make_pair(it->second.getAirportName(), INT_MAX));
//             prev.insert(make_pair(it->second.getAirportName(), ""));
//             visited.insert(make_pair(it->second.getAirportName(), false));
//         }
//     }
//     pair<double,string> initial = make_pair(0.0, StartAirport);
//     Q.push(initial);

//     for(auto it = airportMap.begin(); it != airportMap.end(); ++it) {
//         adjacency_list.insert(make_pair(it->second.getAirportName(), it->second.destAPs));
//     }

//     while(Q.top().second != DestAirport) {
//         pair<double, string> currentNode = Q.top();
//         Q.pop();
//         vector<pair<int , double>> neighbors = getAdjacent(currentNode.second);
//         vector<pair<string, double>> neighborNames;
//         for (auto each : neighbors) {
//             for (auto it = airportMap.begin(); it != airportMap.end(); ++it) {
//                 if (each.first == it->first) {
//                     neighborNames.push_back(make_pair(it->second.getAirportName(), each.second));
//                 }
//             }
//         }
//         for (auto neighbor : neighborNames) {
//             if (visited[neighbor.first] == false && visited[currentNode.second] == false) {
//                 double weight = neighbor.second;
//                 if(weight + dist[currentNode.second] < dist[neighbor.first]) {
//                     dist[neighbor.first] = weight + dist[currentNode.second];
//                     prev[neighbor.first] = currentNode.second;
//                     Q.push(make_pair(dist[neighbor.first], neighbor.first)); 
//                 }
//             }
//         }
//         visited[currentNode.second] = true;
//     }
 
//     path = dist[DestAirport];

//     string key = DestAirport;
//     path_vertices.push_back(DestAirport);
//     while(key != StartAirport) {
//         path_vertices.push_back(prev[key]);
//         key = prev[key];
//     }
//     std::reverse(path_vertices.begin(), path_vertices.end());
// }

// double Djikstras::getShortestDistance() const 
// {
//   return path;
// }

// vector<string> Djikstras::getPathVertices() const 
// {
//   return path_vertices;
// }

vector<string> Dijkstras::DijkstraSearch(Graph g, string source, string dest) {
    //       initialize distances  // initialize tentative distance value
    //   initialize previous   // initialize a map that maps current node -> its previous node
    //   initialize priority_queue   // initialize the priority queue
    //   initialize visited
    // initialize the priority queue
    vector<string> path;
    priority_queue<pair<double, string>> pq;
    vector<string> vertices;
    vector<Airport> airports = g.getAirports();
    map<string, string> prev;
    map<string, double> dist;
    set<string> visited;

    dist[source] = 0.0;
    prev[source] = "";
    prev.insert(make_pair(it->second.getAirportName(), ""));

    for (unsigned i = 0; i < airports.size(); i++) {
        vertices.push_back(airports[i].getIata());
        if(aiports[i].getIata() != source) {
            dist[aiports[i].getIata()] = INT_MAX;
            prev[aiports[i].getIata()] = "";
            // visited.insert(make_pair(it->second.getAirportName(), false));
        }
    }

    pair<double,string> start = make_pair(0.0, source);
    pq.push(start);

    while(pq.top().second != source) {
        //   while the top of priority_queue is not destination:
        //       get the current_node from priority_queue
        //       for neighbor in current_node's neighbors and not in visited:
        //           if update its neighbor's distances:
        //               previous[neighbor] = current_node
        //       save current_node into visited

        //   extract path from previous
        //   return path and distance
        pair<double, string> curr = pq.top();
        pq.pop();
        vector<pair<string, double>> neighbors = g.getAdjacent(curr.second);

        for (unsigned i = 0; i < neighbors.size(); i++) {
            pair<string, double> n = neighbors[i];
            if (visted.find(n.first) == visited.end() && visted.find(curr.second) == visited.end()) {
                double dist = n.second();
                if (dist[curr.second] + dist < dist[n.first]) {
                    dist[n.first] = dist[curr.second] + dist;
                    prev[n.first] = curr.second;
                    pair<double,string> next_node = make_pair(dist[n.first], n.first);
                    pq.push(next_node)
                    // distances[neighbor.first] = weight + distances[currentNode.second];
                    // previous_nodes[neighbor.first] = currentNode.second;
                    // Q.push(make_pair(distances[neighbor.first], neighbor.first));
                }
            }
        }

        visited.insert(curr);
    }

    path = distances[dest];

    string key = DestAirport;
    path_vertices.push_back(DestAirport);
    while(key != StartAirport) {
        path_vertices.push_back(previous_nodes[key]);
        key = previous_nodes[key];
    }
    std::reverse(path_vertices.begin(), path_vertices.end());
    return path;
}