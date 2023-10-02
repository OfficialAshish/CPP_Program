#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void createAdjacency(unordered_map<int, set<int>> &adjList,const vector<pair<int,int>>& edges, bool isUndirected)
{
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first ;
        int v = edges[i].second ;

        adjList[u].insert(v);
        if(isUndirected)
            adjList[v].insert(u);
        
    }
}

void bfsPrint(vector<int>& ans, unordered_map<int, set<int>> &adjList, unordered_map<int,bool>& visited,const int source)
{
    queue<int> qu;
    qu.push(source);
    visited[source]=true;

    while (!qu.empty())
    {
        int front = qu.front();
        ans.push_back(front);

        for (auto i:adjList[front])
        {
            if(!visited[i]){
                qu.push(i);
                visited[i]=true;
            }
        } 
    }
}

vector<int> BFS(int vertices, vector<pair<int,int>> edges)
{
    unordered_map<int, set<int>> adjList;
    vector<int> ans;
    unordered_map<int,bool> visited;
    createAdjacency(adjList,edges,1);
    for (int i = 0; i < vertices; i++)
    {
        if(!visited[i]){
            bfsPrint(ans,adjList,visited,i);
        } 
    }
    
    return ans;
}