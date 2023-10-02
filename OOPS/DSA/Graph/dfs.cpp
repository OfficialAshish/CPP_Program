#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void createAdjacency(unordered_map<int, set<int>> &adjList, const vector<pair<int, int>> &edges, bool isUndirected)
{
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].insert(v);
        if (isUndirected)
            adjList[v].insert(u);
    }
}

void dfsPrint(vector<int> &component, unordered_map<int, set<int>> &adjList, unordered_map<int, bool> &visited, const int node)
{
    component.push_back(node);
    visited[node] = true;

    for (auto i : adjList[node])
    {
        if (!visited[i])
        {
            dfsPrint(component, adjList, visited, i);
        }
    }
}

vector<vector<int>> DFS(int vertices, vector<pair<int, int>> edges)
{
    unordered_map<int, set<int>> adjList;
    vector<vector<int>> ans;
    unordered_map<int, bool> visited;
    createAdjacency(adjList, edges, 1);
    for (int i = 0; i < vertices; i++)
    {
        vector<int> component;
        if (!visited[i])
        {
            dfsPrint(component, adjList, visited, i);
            ans.push_back(component);
        }
    }

    return ans;
}