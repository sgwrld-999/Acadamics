#include<bits/stdc++.h>
using namespace std; 
vector<vector<int> > methodOneToRepresentUsingAjcMat(vector<vector<int> >& gph,int vertices){
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
int main(int argc, char const *argv[])
{
    int vertices ;
    cout << "Enter the number of vertices in the graph :" << endl ;
    cin >> vertices ;
    int direction ;
    cout << "Enter 0 for the undirected graph and 1 for the directed graph : " << endl ;
    cin >> direction ;
    vector<vector<int> >gph(vertices+1,vector<int>(vertices+1,0));
    return 0;
}
