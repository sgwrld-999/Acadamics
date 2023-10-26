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

void DFS(int node,int vertices,vector<vector<int> >& gph,vector<bool>& visitedNodes,vector<int>& visit){
    if(visitedNodes[node] == true)
        return ;
    visitedNodes[node] = true ;
    visit.push_back(node);
    for (int i = 1; i < vertices + 1; i++)
    {
        if(gph[node][i] == 1 && visitedNodes[i] == false){
            DFS(i,vertices,gph,visitedNodes,visit);
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
    gph = methodTwoToRepresentUsingAjcMat(gph, vertices, direction);
    printgph(gph, vertices);
    DFS(1,vertices,gph,visitedNodes,visit);
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
