#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    // Method 2 of creating the graph using the map and list<int>/vector<int>
    /*
    Direction 1 ----> Directed graph
    Direction 0 ----> Undirected graph
    */
   // Adjacency List is a way to represent a graph using a map of list of list 
   // where the key represents the node and the list represents the adjacent nodes of the ket node.
   //The list can be represent using the any list format Data structre like vector, list, array etc in any language.
    unordered_map<int, list<int>> adjacencyList;

    void addEdge(int u, int v, int direction) {
        adjacencyList[u].push_back(v);
        if (direction == 0) {
            adjacencyList[v].push_back(u);
        }
    }

    void printAdjacencyList() {
        for (auto i : adjacencyList) {
            cout << i.first << "-->";
            for (auto j : i.second) {
                cout << j << " ";
            }
            cout << endl;
        }
    }
};

int main(int argc, char const* argv[]) {
    int vertices, edges;
    cout << "Enter the number of vertices in the graph: ";
    cin >> vertices;
    cout << "Enter the number of edges in the graph: ";
    cin >> edges;
    int direction;
    cout << "Enter 0 for Undirected graph or 1 for Digraph: ";
    cin >> direction;
    Graph obj;
    cout << "Enter the vertices where the edge lies between (u, v) : " << endl;
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        obj.addEdge(u, v, direction);
    }
    // Printing the Graph:
    obj.printAdjacencyList();
    return 0;
}
