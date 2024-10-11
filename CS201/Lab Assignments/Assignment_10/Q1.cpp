#include <bits/stdc++.h>
using namespace std;

class Edge {
public:
    int src, dest, weight;
};

class Graph {
public:
    int V, E; // V -> Vertices, E -> Edges
    Edge* edge; // Edges of the graph which is an array of Edge class
};

class Node {
public:
    int data; // Data to be stored in the node
    Node* next; // Pointer to the next node
    Node* prev; // Pointer to the previous node
};

class DoublyLinkedList {
public:
    Node* head;
    Node* tail;
    Node* representative; 

    DoublyLinkedList(int data) { // Constructor
        head = new Node();
        tail = new Node();
        representative = new Node();
        head->data = data;
        tail->data = data;
        representative->data = data;
        head->prev = nullptr;
        head->next = tail;
        tail->prev = head;
        tail->next = nullptr;
    }

    void insert(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->prev = tail;
        newNode->next = nullptr;
        tail->next = newNode;
        tail = newNode;
    }

    Node* findSet(int data) {
        Node* node = head;
        while (node != nullptr) {
            if (node->data == data) {
                representative = node;
                return node;
            }
            node = node->next;
        }
        return nullptr;
    }

    void Union(DoublyLinkedList* list) {
        Node* node = list->head;
        while (node != nullptr) {
            node->prev = tail;
            tail->next = node;
            tail = node;
            node = node->next;
        }
    }
};

class Subset {
public:
    DoublyLinkedList* set; // Array of sets
    int rank;
};

int find(Subset subsets[], int i) {
    if (subsets[i].set->representative->data != i)
        subsets[i].set->representative = subsets[i].set->findSet(i);

    return subsets[i].set->representative->data;
}

void Union(Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].set->Union(subsets[yroot].set);
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].set->Union(subsets[xroot].set);
    else {
        subsets[yroot].set->Union(subsets[xroot].set);
        subsets[xroot].rank++;
    }
}

int myComp(const void* a, const void* b) { // Custom comparator function for sorting the edges
    Edge* a1 = (Edge*)a;
    Edge* b1 = (Edge*)b;
    return a1->weight > b1->weight;
}

void KruskalMST(Graph* graph) {
    int V = graph->V;
    Edge result[V];
    int e = 0;
    int i = 0;
    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), myComp);
    Subset* subsets = new Subset[V];
    for (int v = 0; v < V; ++v) {
        subsets[v].set = new DoublyLinkedList(v);
        subsets[v].rank = 0;
    }
    while (e < V - 1 && i < graph->E) {
        Edge next_edge = graph->edge[i++];
        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);
        if (x != y) {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }
    cout << "Following are the edges in the constructed MST\n";
    int minimumCost = 0;
    for (i = 0; i < e; ++i) {
        cout << result[i].src << " -- " << result[i].dest << " == " << result[i].weight << endl;
        minimumCost += result[i].weight;
    }
    cout << "Minimum Cost Spanning Tree: " << minimumCost << endl;
}

int main() {
    int testCases = 0;
    cin >> testCases;
    while (testCases--) {
        int V, E;
        cin >> V >> E;
        Graph* graph = new Graph;
        graph->V = V;
        graph->E = E;
        graph->edge = new Edge[E];
        for (int i = 0; i < E; ++i) {
            int src, dest, weight;
            cin >> src >> dest >> weight;
            graph->edge[i].src = src;
            graph->edge[i].dest = dest;
            graph->edge[i].weight = weight;
        }
        KruskalMST(graph);
    }
    return 0;
}
/*
Sample inputs : 
1: 

4 5
0 1 2
0 2 4
1 2 1
1 3 5
2 3 3

2: 
7 10
0 1 4
0 3 2
1 2 6
1 3 8
1 4 7
2 4 6
2 5 2
3 4 9
4 5 10
5 6 5

3:
5 7
0 1 2
0 2 4
1 2 1
1 3 5
2 3 3
3 4 7
0 4 6

5:
3 3
0 1 1
0 2 2
1 2 3

6:
5 6
0 1 5
0 3 10
1 2 2
2 3 5
2 4 7
3 4 1
*/