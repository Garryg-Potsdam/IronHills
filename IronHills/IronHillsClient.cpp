#include "MiddleEarthGraph.h"
#include "Heuristics.h"
#include "ExceptionClass.h"

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
	int input;

	cin >> input;

	switch (input)
	{
	case 1:
		ans = DISTANCE_TO_IRON_HILLS;
		break;
	case 2:
		ans = ROAD_QUALITY;
		break;
	case 3:
		ans = RISK_LEVEL;
		break;
	default:
		throw new InvalidInputFromUserException();
		break;
	}

	return ans;
}