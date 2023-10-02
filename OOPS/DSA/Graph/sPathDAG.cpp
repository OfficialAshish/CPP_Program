
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// sortest path in acyclic directed graph with weighted edges
class Graph
{
  unordered_map<int, list<pair<int, int>>> adjList;
  vector<int> topoSort;

public:
  void addEdge(int u, int v, int weight)
  {
    adjList[u].push_back(make_pair(v, weight));
  }
  void print()
  {
    cout << "Printing...\n";
    for (auto ad : adjList)
    {
      cout << endl
           << ad.first << " -> ";
      for (auto ls : ad.second)
      {
        cout << "(" << ls.first << "," << ls.second << ") ,";
      }
    }
  }
  int getVertexSize()
  {
    int mx = 0;
    for (auto i : adjList)
    {
      for (auto j : i.second)
        mx = max(mx, max(i.first, j.first));
    }
    return mx + 1; //for zero indexing
  }
  // void sortestPathDAG(int source, int target);
  vector<int> topologicalSort()
  {

    // BFS
    queue<int> q;
    int v = this->getVertexSize();
    vector<int> indegree(v);
    vector<int> ans;

    for (auto i : adjList)
    {
      for (auto j : i.second)
        indegree[j.first]++;
    }

    for (int j = 0; j < v; j++)
      if (indegree[j] == 0)
        q.push(j);

    while (!q.empty())
    {
      int front = q.front();
      q.pop();
      ans.push_back(front);

      for (auto neig : adjList[front])
      {
        indegree[neig.first]--;
        if (indegree[neig.first] == 0)
          q.push(neig.first);
      }
    }

    topoSort = ans;
    return ans;
  }

  void sortestPath(int src, vector<int> &dist)
  {
    dist[src] = 0;
    for (int i = 0; i < topoSort.size(); i++)
    {
      if (dist[i] != INT_MAX)
      {
        for (auto ng : adjList[i])
        {
          if (dist[i] + ng.second < dist[ng.first])
          {
            dist[ng.first] = dist[i] + ng.second;
          }
        }
      }
    }
  }
};

int main()
{
  Graph g;

  g.addEdge(0, 1, 5);
  g.addEdge(0, 2, 3);
  g.addEdge(1, 2, 2);
  g.addEdge(1, 3, 6);
  g.addEdge(2, 3, 7);
  g.addEdge(2, 4, 4);
  g.addEdge(2, 5, 2);
  g.addEdge(3, 4, -1);
  g.addEdge(4, 5, -2);

  g.print();

  vector<int> tSort = g.topologicalSort();
  for (int a : tSort)
    cout << a << ", ";

  int n = g.getVertexSize();
  
  int  src = 1;

  vector<int> dist(n);
  for (int &i : dist)
    i = INT_MAX;

  g.sortestPath(src, dist);

  cout << "\nDistance array for node : " <<src <<endl;
  for (int i : dist)
    cout << i << ", ";

  return 0;
}