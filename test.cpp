#include <iostream> 
#include <fstream>

using namespace std;

int main() {
    std::cout << "Hello World!";
    ifstream file;
    file.open("/workspaces/CS225/Final-Project/225-final-project/data/routes.dat");
    string data = "";
    while (file >> data) {
        std::cout << data << std::endl;
    }
    file.close();
    return 0;  
}