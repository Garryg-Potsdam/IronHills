#include "MiddleEarthGraph.h"
#include "Heuristics.h"

using namespace std;

// this is a file of all the nodes with distance from goals
const string NODES_WITH_DISTANCES_TO_IRON_HILLS = "distancetable.txt";

// this is a file with all the local connections to other nodes
const string CONNECTIONS_BETWEEN_NODES = "connectiontable.txt";

string getStringFromQuestion(string question);

Heuristics getHeuristicsFromQuestion(string question);

int main() {    
    Graph middleEarth = Graph(NODES_WITH_DISTANCES_TO_IRON_HILLS);
    middleEarth.addEdges(CONNECTIONS_BETWEEN_NODES);    
    
	// get the starting city
	string question = "Where would you like to begin your quest?\t";
	string start = getStringFromQuestion(question);
	
	// get the heuristic nessecary
	question = "Would you like to use Distance (1), Road Quality (2) or Risk Level (3) as the heuristics?\t";
	Heuristics h = getHeuristicsFromQuestion(question);

	//need start, heuristics
	// heuristics
		// Road Quality 1
		// Distance to IH 0	
		// Risk level 2


	cout << middleEarth.toString();

	system("pause");
    return 0;
}

string getStringFromQuestion(string question){
	cout << question;
	
	string ans;

	cin >> ans;

	return ans;
}

Heuristics getHeuristicsFromQuestion(string question) {
	cout << question;

	Heuristics ans;

	cin >> ans;

	return ans;
}