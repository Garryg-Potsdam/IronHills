#include "MiddleEarthGraph.h"

using namespace std;

// Graph Constuctor
// Parameters: nodesWithDistances - take a specificly formatted file's name and 
//                                  builds a graph with it
Graph::Graph(string nodesWithDistances) {
    locCounter = 0;
    string currentNode;
    ifstream infile;
    infile.open(nodesWithDistances.c_str());
    
    // this loops builds the nodes line by line
    // it also does the parsing
    while (!infile.eof()) {
        getline(infile, currentNode);
        string name = currentNode.substr(0, currentNode.find(" "));
        currentNode.erase(0, currentNode.find(" ") + 1);
        string temp;
        int x;
        if (currentNode.find(" ") != -1) {
            name += " " + currentNode.substr(0, currentNode.find(" "));
            currentNode.erase(0, currentNode.find(" ") + 1);
        }
        addNode(name, stringToInt(currentNode));
    }
}

// Parameters: s - a string to convert to an int
// Returns: an int that was converted from a string
int Graph::stringToInt(string s) {
    int x;
    stringstream ss(s);
    ss >> x;
    return x;
}

// Returns: int representing the amount of nodes in graph
int Graph::getSize() {
   return locCounter - 1; 
}

// Parameters: node - string name of the node wanted
// Returns: the node with the name passed in
Graph::Node* Graph::getNode(string node) {
    for (int i = 0; i < locCounter; i++)
        if (locations[i]->locationName.compare(node) == 0)
            return locations[i];
}

// Parameters: location - the name of the node being added
//             distance - the distance from that current node
//                        to the destination
// Post-Condition: creates a new node adds it to the locations list
//                 and increments locCounter
void Graph::addNode(string location, int distance) {
    locations[locCounter] = new Node;
    locations[locCounter]->locationName = location;
    locations[locCounter]->distanceToIronHills = distance;  
    locCounter++;
}

// Parameters: i - the int to be converted to a string
// Returns: the string of a passed in int
string Graph::intToString(int i) {
    stringstream ss;
    ss << i;
    return ss.str();
}

// Post-Condition: Builds a string of all the node data and prints
// Returns: printLocs - the constructed string of data
string Graph::toString() {
    string printLocs = "";
    for (int i = 0; i < getSize(); i++) {
        printLocs += locations[i]->locationName + " ";
        printLocs += intToString(locations[i]->distanceToIronHills);
        printLocs += "\n";
    }
    return printLocs;
}
