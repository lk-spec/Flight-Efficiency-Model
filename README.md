# 225-final-project

README

Group Members
vanjani3
Lrk4
Suhaask3
Krishvd2
Overview:
Our project uses the airports.dat and routes.dat files from the Open Flights dataset to find the shortest path between two airports. To do this, we had to first clean the data, and then create a graph with the vertices as airports and the edges as the routes between them. We used BFS, Dijkstras Algorithm, and Kosaraju’s algorithm to complete this task
GitHub Repo:
https://github.com/rohanvan123/225-final-project.git
Files used: 
Airport: Airport Object that contains information on the id, name, IATA code, ICAO code, latitude, and longitude
Graph: Constructed the graph from the data files
BFS: Did a BFS on the graph to find the closest airports to the source airport
Dijkstra: Used Dijkstra’s Algorithm to find the shortest path between two airports
Kosarajus: Implementation of Kosaraju’s algorithm
Test: Tests our graph and algorithms
 
How to run the main program:
make main

To execute:
./main


How to run the test suite:
Make test

To execute:
./test
