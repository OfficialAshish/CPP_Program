#include <bits/stdc++.h>
using namespace std;

void createAdjacency(unordered_map<int, set<int>> &adjList,
                     const vector<pair<int, int>> &edges)
{
  for (int i = 0; i < edges.size(); i++)
  {
    int u = edges[i].first - 1;
    int v = edges[i].second - 1;

    adjList[u].insert(v);
  }
}

bool isCycleDFS(unordered_map<int, set<int>> &adjList,
                unordered_map<int, bool> &visited,
                unordered_map<int, bool> &dfsvisited, const int &node)
{

  visited[node] = 1;
  dfsvisited[node] = 1;

  for (int neigh : adjList[node])
  {
    if (!visited[neigh])
    {
      bool ans = isCycleDFS(adjList, visited, dfsvisited, neigh);
      if (ans)
        return true;
    }
    else if (dfsvisited[neigh])
      return true;
  }

  dfsvisited[node] = 0;
  return false;
}

int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges)
{
  unordered_map<int, set<int>> adjList;
  unordered_map<int, bool> visited;
  unordered_map<int, bool> dfsvisited;

  createAdjacency(adjList, edges);

  // for DFS >>>
  // for (int i = 0; i < n; i++) {
  //   if (!visited[i]) {
  //     bool ans = isCycleDFS(adjList, visited,dfsvisited,i);
  //     if (ans)
  //       return 1;
  //   }
  // }
  // return 0;

  // FOR BFS >>>

  int count = 0;
  queue<int> q;
  vector<int> indeg(n);

  for (auto i : adjList)
    for (int j : i.second)
      indeg[j]++;

  for (int i = 0; i < n; i++)
    if (indeg[i] == 0)
      q.push(i);

  while (!q.empty())
  {
    int front = q.front();
    q.pop();
    count++;
    for (auto nig : adjList[front])
    {
      indeg[nig]--;
      if (indeg[nig] == 0)
        q.push(nig);
    }
  }

  if (count == n)
    return false;
  else
    return true;
}