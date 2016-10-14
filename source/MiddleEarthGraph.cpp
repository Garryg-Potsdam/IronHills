#include "MiddleEarthGraph.h"

Graph::Graph(string nodesWithDistances) {
    string currentNode;
    ifstream infile;
    infile.open(nodesWithDistances);
    while (!infile.eof) {
        getline(infile, currentNode);
        cout << currentNode;
    }
}
