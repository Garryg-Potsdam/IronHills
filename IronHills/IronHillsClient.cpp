#include "MiddleEarthGraph.h"

using namespace std;

// this is a file of all the nodes with distance from goals
const string NODES_WITH_DISTANCES_TO_IRON_HILLS = "distancetable.txt";

// this is a file with all the local connections to other nodes
const string CONNECTIONS_BETWEEN_NODES = "connectiontable.txt";

int main() {    
    Graph middleEarth = Graph(NODES_WITH_DISTANCES_TO_IRON_HILLS);
    middleEarth.addEdges(CONNECTIONS_BETWEEN_NODES);    
    
	cout << middleEarth.getSize();
	cout << middleEarth.toString();

	system("pause");
    return 0;
}
