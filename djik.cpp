#include "Djikstras.h"
#include <map>
#include <climits>
#include <stack>

using namespace std;


bool Djikstras::vertexExists(string node) 
{
    if (adjacency_list.find(node) == adjacency_list.end()) {
        return false;
    }
    return true;
}


vector<pair<int, double>> Djikstras::getAdjacent(string source) 
{
    auto lookup = adjacency_list.find(source);
    vector<string> result;

    if (lookup == adjacency_list.end())
        return vector<pair<int,double>>();

    else {
        vector<pair<int,double>> vertex_list;
        unordered_map<int, Flight> &map = adjacency_list.at(source);
        for (auto it = map.begin(); it != map.end(); it++)
        {
            vertex_list.push_back(make_pair(it->first, it->second.getWeight()));
        }
        return vertex_list;
    }
}

Djikstras::Djikstras(Graph g, string StartAirport, string DestAirport) 
{
    path_vertices.clear();
    vector<string> vertices;  

    unordered_map<int, Airport> airportMap = g.getVertices();

    for (auto it = airportMap.begin(); it != airportMap.end(); ++it) {
        vertices.push_back(it->second.getAirportName());
        if(it->second.getAirportName() == StartAirport) {
            dist.insert(make_pair(it->second.getAirportName(), 0.0));
            prev.insert(make_pair(it->second.getAirportName(), ""));
            visited.insert(make_pair(it->second.getAirportName(), false));
        }
        else {
            dist.insert(make_pair(it->second.getAirportName(), INT_MAX));
            prev.insert(make_pair(it->second.getAirportName(), ""));
            visited.insert(make_pair(it->second.getAirportName(), false));
        }
    }
    pair<double,string> initial = make_pair(0.0, StartAirport);
    Q.push(initial);

    for(auto it = airportMap.begin(); it != airportMap.end(); ++it) {
        adjacency_list.insert(make_pair(it->second.getAirportName(), it->second.destAPs));
    }

    while(Q.top().second != DestAirport) {
        pair<double, string> currentNode = Q.top();
        Q.pop();
        vector<pair<int , double>> neighbors = getAdjacent(currentNode.second);
        vector<pair<string, double>> neighborNames;
        for (auto each : neighbors) {
            for (auto it = airportMap.begin(); it != airportMap.end(); ++it) {
                if (each.first == it->first) {
                    neighborNames.push_back(make_pair(it->second.getAirportName(), each.second));
                }
            }
        }
        for (auto neighbor : neighborNames) {
            if (visited[neighbor.first] == false && visited[currentNode.second] == false) {
                double weight = neighbor.second;
                if(weight + dist[currentNode.second] < dist[neighbor.first]) {
                    dist[neighbor.first] = weight + dist[currentNode.second];
                    prev[neighbor.first] = currentNode.second;
                    Q.push(make_pair(dist[neighbor.first], neighbor.first)); 
                }
            }
        }
        visited[currentNode.second] = true;
    }
 
    path = dist[DestAirport];

    string key = DestAirport;
    path_vertices.push_back(DestAirport);
    while(key != StartAirport) {
        path_vertices.push_back(prev[key]);
        key = prev[key];
    }
    std::reverse(path_vertices.begin(), path_vertices.end());
}

double Djikstras::getShortestDistance() const 
{
  return path;
}

vector<string> Djikstras::getPathVertices() const 
{
  return path_vertices;
}