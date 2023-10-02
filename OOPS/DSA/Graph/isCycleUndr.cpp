#include <bits/stdc++.h>
#include <iostream>
using namespace std;


void createAdjacency(unordered_map<int, set<int>> &adjList,
                    const vector<vector<int>> &edges, bool isUndirected) {
  for (int i = 0; i < edges.size(); i++) {
    int u = edges[i][0];
    int v = edges[i][1];

    adjList[u].insert(v);
    if (isUndirected)
      adjList[v].insert(u);
  }
}

bool isCycleBFS(unordered_map<int, set<int>> &adjList,
               unordered_map<int, bool> &visited,
               unordered_map<int, int> & parents,const int & node) 
    {
        
        queue<int> q;
        q.push(node);
        visited[node]=1;
        parents[node] = -1;

        while(!q.empty())
        {
            int front = q.front();
            q.pop();

            for(auto neigh : adjList[front]){
                if(!visited[neigh])
                {
                    visited[neigh] =1;
                    parents[neigh]=front;
                    q.push(neigh);
                }
                else if(visited[neigh] and parents[front] != neigh) //check the child of parent ()
                    return true;
            }
        }
        return false;
    }

bool isCycleDFS(unordered_map<int, set<int>> &adjList,
               unordered_map<int, bool> &visited,
               int parents,const int & node) 
    {
        visited[node]=1;
        
        for(int neigh : adjList[node]){
            if(!visited[neigh])
            {
                bool ans= isCycleDFS(adjList, visited, node , neigh);
                if (ans) return true;
            }
            else if( parents!= neigh  ) //check the child of parent ()
                return true;
           
        }
        return false;
    }

string cycleDetection(vector<vector<int>> &edges, int n, int m) {
  unordered_map<int, set<int>> adjList;
  // string ans;
  unordered_map<int, bool> visited;
//   unordered_map<int, int> parents;

  createAdjacency(adjList, edges, 1);

  for (int i = 0; i < n; i++) { 
    if (!visited[i]) {
    //   int ans = isCycleBFS(adjList, visited, parents, i);
      bool ans = isCycleDFS(adjList, visited, -1, i);
      if(ans) return "Yes";
    }
  }

  return "No";
}
