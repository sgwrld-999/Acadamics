#include<bits/stdc++.h>
using namespace std;

class Solution {
    public :
    int print(map<int,list<int>> adjList){
        for(auto i : adjList){
            cout<<i.first<<"->";
            for(auto j : i.second){
                cout<<j<<",";
            }
            cout<<endl;
        }
    }
    vector<int> BFS(map<int,list<int>>& adjList,vector<bool>& visited,int src){
        queue<pair<int,int>>que; //{currNode , parentNode}
        vector<int> ans(2,0);
        que.push({src,-1});
        while(!que.empty()){
            int currNode = que.front().first;
            int parentNode = que.front().second;
            que.pop();
            for(const auto& i : adjList[currNode]){
                if(!visited[i]){
                    visited[i] = true;
                    que.push({i,currNode});
                }
                else if(i != parentNode){
                    ans[0] = currNode;
                    ans[1] = i;
                }
            }
        }
        return ans;
    }

    bool DFS(int node,int parent,vector<bool>& visited,map<int,list<int>>& adjList){
        visited[node] = true;
        for(auto i : adjList[node]){
            if(!visited[i]){
                if(DFS(i,node,visited,adjList))
                    return true;
            }
            else if(i != parent)
                return true;
        }
        return false;
    }
    
    vector<int> checkCycles(vector<vector<int>>& edges){
        int rowofEdges  = edges.size();
        int colOfEdges = 2 ;
        map<int,list<int>> adjList;
        for(int i = 0 ; i < rowofEdges ; i++){
            adjList[edges[i][0]].push_back(edges[i][1]);
            adjList[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> visited(rowofEdges+1,false);
        vector<int> ans = BFS(adjList,visited,edges[0][0]);
        if(ans.size() == 2)
            return ans;
            
            
        return {};
    }
    bool checkCyclesDFS(vector<vector<int>>& edges){
        int rowofEdges  = edges.size();
        int colOfEdges = 2 ;
        map<int,list<int>> adjList;
        for(int i = 0 ; i < rowofEdges ; i++){
            adjList[edges[i][0]].push_back(edges[i][1]);
            adjList[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> visited(rowofEdges+1,false);
        bool ans = false;
        for(int i = 0 ; i < rowofEdges ; i++){
            if(!visited[i]){
                if(DFS(i,-1,visited,adjList))
                    return true;
            }
        }   
        return false;
    }
};

int main(){
    int n;
    cin>>n;
    vector<vector<int>> edges;
    for(int i=0;i<n;i++){
        int u,v;
        cin>>u>>v;
        edges.push_back({u,v});
    }
    Solution s;
    // vector<int> ans = s.checkCycles(edges);
    // cout<<ans[0]<<" "<<ans[1]<<endl;
    cout<<s.checkCyclesDFS(edges)<<endl;ß
    return 0;
}