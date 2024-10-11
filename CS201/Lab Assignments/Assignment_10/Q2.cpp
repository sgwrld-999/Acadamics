
#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int dest;
    int weight;
};

struct Graph {
    int V;
    list<Edge>* adjList;
};
Graph* createGraph(int V) {
    Graph* graph = new Graph;
    graph->V = V;
    graph->adjList = new list<Edge>[V];
    return graph;
}
void addEdge(Graph* graph, int src, int dest, int weight) {
    Edge edge = { dest, weight };
    graph->adjList[src].push_back(edge);
    edge.dest = src;
    graph->adjList[dest].push_back(edge);
}
int findMinCutEdge(Graph* graph, vector<bool>& inCut) {
    int minWeight = INT_MAX;
    int minEdge = -1;
    for (int u = 0; u < graph->V; u++) {
        if (inCut[u]) {
            for (auto& edge : graph->adjList[u]) {
                if (!inCut[edge.dest] && edge.weight < minWeight) {
                    minWeight = edge.weight;
                    minEdge = edge.dest;
                }
            }
        }
    }
    return minEdge;
}
void primMST(Graph* graph) {
    vector<bool> inCut(graph->V, false);
    inCut[0] = true;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (auto& edge : graph->adjList[0]) {
        pq.push({ edge.weight, edge.dest });
    }
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if (inCut[u]) {
            continue;
        }
        inCut[u] = true;
        int minCutEdge = findMinCutEdge(graph, inCut);
        if (minCutEdge != -1) {
            cout << "Edge: " << u << " - " << minCutEdge << endl;
            for (auto& edge : graph->adjList[minCutEdge]) {
                if (inCut[edge.dest]) {
                    pq.push({ edge.weight, edge.dest });
                }
            }
        }
    }
}

int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;
    Graph* graph = createGraph(V);
    for (int i = 0; i < E; i++) {
        int src, dest, weight;
        cin >> src >> dest >> weight;
        addEdge(graph, src, dest, weight);
    }
    primMST(graph);
    return 0;
}
