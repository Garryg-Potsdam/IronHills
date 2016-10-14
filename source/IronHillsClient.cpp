#include "MiddleEarthGraph.h"

using namespace std;

const string NODES_WITH_DISTANCES_TO_IRON_HILLS = "distancetable.txt";

const string CONNECTIONS_BETWEEN_NODES = "connectiontable.txt";

int main() {    
    Graph * g;
    g = new Graph(NODES_WITH_DISTANCES_TO_IRON_HILLS);    
    //cout << g.toString() << endl;
    return 0;
}
