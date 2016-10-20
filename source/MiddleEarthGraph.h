#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

class Graph {

    // Edge with opposite location, distance, road quality and risk level
    struct Edge {
        string to;
        int distance, roadQuality, riskLevel;
    };

    // Node with current location distance to iron hills and a list of edges as well as edge count
    struct Node {
        string locationName;
        int distanceToIronHills;
        int edgeCount;
        Edge edges[8];
    };

    public:

        // Graph Constuctor
        // Parameters: nodesWithDistances - take a specificly formatted file's name and
        //                                  builds a graph with it
        Graph(string nodesWithDistances);

        // Parameters: node - string name of the node wanted
        // Returns: the node with the name passed in
        int getNode(string node);

        // Parameters: location - the name of the node being added
        //             distance - the distance from that current node
        //                        to the destination
        // Post-Condition: creates a new node adds it to the locations list
        //                 and increments locCounter
        void addNode(string location, int distance);

        // Returns: int representing the amount of nodes in graph
        int getSize();

        // Parameters : from - the current location
        //                to - the location the edge goes to
        //                 d - the distance of the edge
        //                rq - the road quality of the edge
        //                rl - the risk level of the edge
        // Post-Condition: addes an edge to the from node
        void addEdge(string from, string to, int d, int rq, int rl);

        // Parameters: nodeConnData - a file of a specific format for adding edges
        void addEdges(string nodeConnData);

        // Post-Condition: Builds a string of all the node data and prints
        // Returns: printLocs - the constructed string of data
        string toString();

    private:
        int locCounter;
        Node locations[25];

        // Parameters: i - the int to be converted to a string
        // Returns: the string of a passed in int
        string intToString(int i);

        // Parameters: s - a string to convert to an int
        // Returns: an int that was converted from a string
        int stringToInt(string s);
};
