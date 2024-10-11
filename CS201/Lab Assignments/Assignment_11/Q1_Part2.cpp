#include<bits/stdc++.h>
using namespace std;

struct Edge {
    int src ;
    int destt ;
    int weight ;
};

struct Graph {
    int V;
    int E;
    struct Edge* edge ;
};

struct Graph* createGraph(int V, int E) {
    struct Graph* graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->edge = new Edge[E];
    return graph ;
}

void printArr(int dist[], int n){
    cout << "Vertex Distance from Source" << endl;
    for(int i = 0 ; i < n ; i++){
        cout << i << "\t" << dist[i] << endl;
    }
}

//Detect a Negative Cycle in a Graph


int main(){
    return 0;
}