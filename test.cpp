#include <iostream> 
#include <fstream>
#include "graph.h"

using namespace std;

int main() {
    // std::cout << "Informal Testing:" << std::endl;

    // ifstream file;
    // // may have to change the path bc it could be someone else's
    // file.open("/workspaces/CS 225/final-project/225-final-project/data/routes.dat");
    // string data = "";
    // while (file >> data) {
    //     std::cout << data << std::endl;
    // }
    // file.close();


    Graph g("/workspaces/CS 225/final-project/225-final-project/data/airports.dat", "/workspaces/CS 225/final-project/225-final-project/data/routes.dat");
    g.printAirports();
    g.printGraph();
    return 0;  
}