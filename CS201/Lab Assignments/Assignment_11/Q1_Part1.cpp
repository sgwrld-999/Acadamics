#include<bits/stdc++.h>
using namespace std;
/*
Problem Statement : 
Given a weighted directed graph G = (V, E). The weights can be negative also. Perform the following –
    • Detect a cycle in the graph.
*/
struct Edge {
    int src, dest, weight;
};

struct Graph {
    int V, E;
    struct Edge* edge;
};

struct Graph* createGraph(int V, int E) {
    struct Graph* graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->edge = new Edge[E];
    return graph;
}

void printArr(int dist[], int n) {
    cout << "Vertex Distance from Source" << endl;
    for (int i = 0; i < n; ++i)
        cout << i << "\t\t" << dist[i] << endl;
}

bool BellmanFord(struct Graph* graph, int src) {
    int V = graph->V;
    int E = graph->E;
    int dist[V];

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;
    
    dist[src] = 0;

    for(int i = 1 ; i < V - 1 ; i++){
        for(int j = 0 ; j < E  ; j++){
            int u = graph->edge[j].src;
            int v = graph->edge[j].dest;
            int weight = graph->edge[j].weight;
            if(dist[u] != INT_MAX && dist[u] + weight < dist[v]){
                dist[v] = dist[u] + weight;
            }
        }
    }
    for (int i = 0; i < E; i++) {
        int u = graph->edge[i].src;
        int v = graph->edge[i].dest;
        int weight = graph->edge[i].weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            return true;
        }
    }
    return false;
}

int main(){
    int V , E ;
    cout << "Enter the number of vertices and edges: " << endl;
    cin >> V >> E;
    struct Graph* graph = createGraph(V, E);
    cout << "Enter the source, destination and weight of each edge: " << endl;
    for(int i = 0 ; i < E ; i++){
        int src, dest, weight;
        cin >> src >> dest >> weight;
        graph->edge[i].src = src;
        graph->edge[i].dest = dest;
        graph->edge[i].weight = weight;
    }
    if(BellmanFord(graph, 0)){
        cout << "Graph contains negative weight cycle " << endl;
    }else{
        cout << "Graph doesn't contain negative weight cycle " << endl;
    }
    return 0;
}

/*
Sample Input/Output:
Input : 
6 8 
    0 1 5
    0 2 3
    1 3 6
    1 2 2
    2 4 4
    2 5 2
    2 3 7
    3 4 -1
Output : Graph contains negative weight cycle

Input 2 : 
6 8 
0 1 5
0 2 3
1 3 6
1 2 2
2 4 4
2 5 2
2 3 7
3 4 1

*/