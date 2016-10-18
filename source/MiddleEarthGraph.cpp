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
    for (int i = 0; i < 25; i++) {
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

// Parameters : from - the current location
//                to - the location the edge goes to
//                 d - the distance of the edge
//                rq - the road quality of the edge
//                rl - the risk level of the edge
// Post-Condition: addes an edge to the from node
void Graph::addEdge(string from, string to, int d, int rq, int rl) {
    int temp = getNode(from);    
    locations[temp].edges[locations[temp].edgeCount].to = to;
    locations[temp].edges[locations[temp].edgeCount].distance = d;
    locations[temp].edges[locations[temp].edgeCount].roadQuality = rq;
    locations[temp].edges[locations[temp].edgeCount].riskLevel = rl;
    locations[temp].edgeCount++;
}

// Parameters: nodeConnData - a file of a specific format for adding edges
void Graph::addEdges(string nodeConnData) {
    string from;
    ifstream infile;
    infile.open(nodeConnData.c_str());
    
    for (int t = 0; t < 23; t++) {
        getline(infile, from);
        string total;
        getline(infile, total);
        int x = stringToInt(total);
        int d, rq, rl;
        string to;
	
        for (int i = 0; i < x; i++) {
            getline(infile, to);
            string temp;
            getline(infile, temp);
            d = stringToInt(temp.substr(0, temp.find(" ")));
            temp.erase(0, temp.find(" ") + 1);
            rq = stringToInt(temp.substr(0, temp.find(" ")));
            temp.erase(0, temp.find(" ") + 1);
            rl = stringToInt(temp);	    
	    addEdge(from, to, d, rq, rl);
	    addEdge(to, from, d, rq, rl);
        }
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
int Graph::getNode(string node) {
    for (int i = 0; i < locCounter; i++)
        if (locations[i].locationName.compare(node) == 0)
            return i;
}

// Parameters: location - the name of the node being added
//             distance - the distance from that current node
//                        to the destination
// Post-Condition: creates a new node adds it to the locations list
//                 and increments locCounter
void Graph::addNode(string location, int distance) {
    locations[locCounter].locationName = location;
    locations[locCounter].distanceToIronHills = distance;
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
        printLocs += "\n" + locations[i].locationName + " : ";
        printLocs += "Distance To IronHills: " + intToString(locations[i].distanceToIronHills);
        printLocs += "\n\n";
	for (int j = 0; j < locations[i].edgeCount; j++) {
	    printLocs += "\tEdges:";
	    printLocs += "\tTo: " + locations[i].edges[j].to;
	    printLocs += "\tDistance: " + intToString(locations[i].edges[j].distance);
	    printLocs += "\tRoad Quality: " + intToString(locations[i].edges[j].roadQuality);
	    printLocs += "\tRisk Level: " + intToString(locations[i].edges[j].riskLevel);
	    printLocs += "\n";
	    printLocs += "|-----------------------------------------------------------------------------------------------|\n";
	}
    }    
    return printLocs;
}