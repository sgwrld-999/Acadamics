#include<bits/stdc++.h>
using namespace std; 
vector<vector<int> > methodOneToRepresentUsingAjcMat(vector<vector<int> >& gph,int vertices){
//Input one is enter the entire Adj matrix 
/*
    vertices : 4
    Edges : 4
    ip : 
    0 1 1 0
    1 0 1 0 
    1 1 0 1 
    0 0 1 0
*/
cout << "Enter the adjaceny matrix." ;
    for (int i = 1; i < vertices + 1; i++)
    {
        for (int j = 1; j < vertices + 1 ; j++)
        {
            cin >> gph[i][j];
        }
    }
    return gph ;
}
vector<vector<int> > methodTwoToRepresentUsingAjcMat(vector<vector<int> >& gph,int vertices,int direction){
//Enter the pair of vetices which have the edge
/*
    vertices : 4
    Edges : 4
    ip : 
    0 1
    0 2
    1 2 
    2 3
*/
cout << "Enter the pair of the vertex you want to create an edge" ;
    for (int i = 1; i < vertices + 1; i++)
    {
       int u , v;
       cin >> u >> v ;
        gph[v][u] = 1;
            if(direction == 0)
                gph[u][v] = 1;
    }
    return gph ;
}
void printgph(vector<vector<int> >&gph,int vertices){
    cout << "Printing the graph :" << endl ;
    for (int i = 1; i < vertices + 1; i++)
    {
        for (int j = 1; j < vertices + 1 ; j++)
        {
            cout << gph[i][j] << " ";
        }
        cout << endl ;
    }
}

void BFS(int node,vector<vector<int> >& gph,vector<bool>& visitedNodes,vector<int>& visit, int vertices){
    queue<int> que ;
    que.push(node);
    visitedNodes[node] = true;
    while(!que.empty()){
        int frontNode = que.front();
        que.pop();
        visit.push_back(frontNode);
        for(int i = 0 ; i < vertices ; i++){
            if(!visitedNodes[gph[frontNode][i]]){
                que.push(gph[frontNode][i]);
                visitedNodes[gph[frontNode][i]] = true ;
            }
        }
    }
}
int main(int argc, char const *argv[])
{
    int vertices;
    cout << "Enter the number of vertices in the graph: " << endl;
    cin >> vertices;
    
    int direction;
    cout << "Enter 0 for the undirected graph and 1 for the directed graph: " << endl;
    cin >> direction;

    vector<vector<int>> gph(vertices + 1, vector<int>(vertices + 1, 0));
    vector<bool> visitedNodes(vertices + 1, false);
    vector<int> visit;

    if (direction == 0) {
        // Assuming it's an undirected graph
        gph = methodOneToRepresentUsingAjcMat(gph, vertices);
    }
    else {
        // Assuming it's a directed graph
        gph = methodTwoToRepresentUsingAjcMat(gph, vertices, direction);
    }

    printgph(gph, vertices);
    for (int i = 0; i < vertices ; i++)
    {
        BFS(i,gph,visitedNodes,visit,vertices);
    }
   cout << "Printing the visit vector: [";
    for (int i = 0; i < visit.size(); i++) {
        cout << visit[i];
        if (i < visit.size() - 1) {
            cout << " , ";
        }
    }
    cout << "]" << endl;
    
    return 0;
}
