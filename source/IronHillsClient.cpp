#include "MiddleEarthGraph.h"

using namespace std;

// this is a file of all the nodes with distance from goals
const string NODES_WITH_DISTANCES_TO_IRON_HILLS = "distancetable.txt";

// this is a file with all the local connections to other nodes
const string CONNECTIONS_BETWEEN_NODES = "connectiontable.txt";

int main() {    
    Graph * g;
    g = new Graph(NODES_WITH_DISTANCES_TO_IRON_HILLS);
    g->addEdges(CONNECTIONS_BETWEEN_NODES);    
    cout << g->toString();
    return 0;
}
