#include "MiddleEarthGraph.h"

using namespace std;

Graph::Graph(string nodesWithDistances) {
    locCounter = 0;
    string currentNode;
    ifstream infile;
    infile.open(nodesWithDistances.c_str());
    while (!infile.eof()) {
        getline(infile, currentNode);
        string name = currentNode.substr(0, currentNode.find(" "));
        currentNode.erase(0, currentNode.find(" ") + 1);        
        addNode(name, stoi(currentNode)); 
    }
}

int Graph::getSize() {
   return locCounter; 
}

Node Graph::getNode(string node) {
    for (int i = 0; i < locCounter; i++)
        if (locations[i]->locationName.compare(node) == 0)
            return locations[i];
}

void Graph::addNode(string location, int distance) {
    locations[locCounter] = new Node;
    locations[locCounter]->locationName = location;
    locations[locCounter]->distanceToIronHills = distance;  
    locCounter++;
}

void Graph::intToString(int i) {
    stringstream ss;
    ss << i;
    return ss.str();
}

string Graph::toString() {
    string printLocs = "";
    for (int i = 0; i < locCounter; i++) {
        printLocs += locations[i]->locationName + " ";
        printLocs += intToString(locations[i]->distanceToIronHills);
    }
    return printLocs + "\n";
}
