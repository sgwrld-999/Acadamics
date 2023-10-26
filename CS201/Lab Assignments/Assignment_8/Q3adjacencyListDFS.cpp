#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    // Method 2 of creating the graph using the map and list<int>/vector<int>
    /*
    Direction 1 ----> Directed graph
    Direction 0 ----> Undirected graph
    */
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
    unordered_map<int,bool> visit;//We can use array/vector as well but it'll bound us to the interger only.
    vector<int> visitedNodes ; // It'll store the explored notes.
    void DFS(int node){
        if(visit[node] == true){return;}//If the node is already visited then the call will be returned.
        visit[node] = true;
        for(auto i : adjacencyList[node]){
            if(!visit[i]){
                DFS(i);
            }
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

    // Perform DFS from each vertex to check for connectivity.
    bool flag = true;
    obj.DFS(1);
    for(auto i : obj.visit){
        if(i.second == false){
            flag = false;
            cout << "The graph is not connected." << endl;
            break;
        }
    }
    
    if (flag) {
        cout << "The graph is connected." << endl;
    }

    return 0;
}

/*
Input : 
Vertices = 8
Edges = 11
pair of edges = 
1 2
1 3
2 3 
2 4 
2 5
3 5 
5 6
3 7
3 8
7 8 
4 5
*/