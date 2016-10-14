#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

class Graph {

    struct Edge {
        string to;
        int distance, roadQuality, riskLevel;
    };

    struct Node {
        string locationName;
        int distanceToIronHills;
        Edge * edges;
    };
    
    public:
        Graph(string nodesWithDistances);
        Node* getNode(string node);
        void addNode(string location, int distance);
        int getSize();
        string toString();       
 
    private:
        int locCounter;
        Node * locations[25];
        void intToString(int i);
};
