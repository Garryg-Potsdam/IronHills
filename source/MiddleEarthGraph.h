#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Graph {

    struct Edge {
        Node * to;
        int distance, roadQuality, riskLevel;
    };

    struct Node {
        string locationName;
        int distanceToIronHills;
        Edge * edges;
    };
    
    public:
        Graph(string nodesWithDistances);
        //Node getNode(string);        
        
    private:
        Node locations[25];    
};
