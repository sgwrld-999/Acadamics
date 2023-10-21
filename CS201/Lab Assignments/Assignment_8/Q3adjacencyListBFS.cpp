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
    vector<int> visitedNodes ; // It'll store the explored notes.lłl
    void BFS(int node){
        queue<int> que ;// To insert the value of the visited node and explore thier neighbours.
        que.push(node);
        visit[node] = true;
        while (!que.empty())
        {
            int frontnode = que.front();// Storeing the value of the front node
            que.pop();// Poping the element in the front
            visitedNodes.push_back(frontnode); // Storing it the explored node array or the ans array
            for (auto i : adjacencyList[frontnode])
            {
                if(!visit[i]){
                    que.push(i); // We'll push the value of the if it's not visited
                    visit[i] = true ;// mark the node/vertex as visited in the map
                }
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

    // Perform BFS from each vertex to check for connectivity.
    bool flag = true;
    for (int i = 0; i < vertices; i++) {
        obj.BFS(i);
    }

    // Check if all nodes are visited to determine graph connectivity.
    for (int i = 0; i < vertices; i++) {
        if (!obj.visit[i]) {
            flag = false;
            cout << "The graph is not connected." << endl;
            break;  // No need to check further, it's not connected.
        }
    }

    if (flag) {
        cout << "The graph is connected." << endl;
    }

    return 0;
}
