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
    
	try {

		// get the starting city
		string question = "Where would you like to begin your quest?\t";
		string start = getStringFromQuestion(question);

		// get the heuristic nessecary
		question = "Would you like to use Distance (1), Road Quality (2) or Risk Level (3) as the heuristics?\t";
		Heuristics h = getHeuristicsFromQuestion(question);

		middleEarth.aStar(start, h);
		cout << middleEarth.toString();

	}
	catch (...){
		string quote = "It's a dangerous business, Frodo, going out your door. ";
		quote += "You step onto the road, and if you don't keep your feet, there's no knowing where you might be swept off to.";
		cout << quote << endl << endl;

		cout << "But some exception was thrown, and we're dead. We failed to make it, to our Dwarvish home.";
	}

	system("pause");
    return 0;
}

string getStringFromQuestion(string question) {
	cout << question;
	
	string ans;

	getline(cin, ans);

	return ans;
}

Heuristics getHeuristicsFromQuestion(string question) {
	cout << question;

	int input;

	cin >> input;

	cout << "You typed " << input << endl;

	switch (input)
	{
	case 1:
		return DISTANCE;
		break;
	case 2:
		return ROAD_QUALITY;
		break;
	case 3:
		return RISK_LEVEL;
		break;
	default:
		throw new InvalidInputFromUserException();
		break;
	}
}