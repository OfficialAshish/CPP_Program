#include <bits/stdc++.h>

void dfs(int node, int parent, int timer, vector<int> &discover,
         vector<int> &lowestTime, unordered_map<int, bool> &visited,
         unordered_map<int, list<int>> &adj, vector<vector<int>> &ans) {

  visited[node] = true;
  discover[node] = lowestTime[node] = timer++;

  for (auto nbr : adj[node]) {
    if (nbr == parent)
      continue;

    if (!visited[nbr]) {
      dfs(nbr, node, timer, discover, lowestTime, visited, adj, ans);

      lowestTime[node] = min(lowestTime[nbr], lowestTime[node]);

      //   checking bridge
      if (lowestTime[nbr] > discover[node]) {
        vector<int> result;
        result.push_back(node);
        result.push_back(nbr);
        ans.push_back(result);
      }
    } else {
      // for loop edge
      lowestTime[node] = min(lowestTime[node], discover[nbr]);
    }
  }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {

  unordered_map<int, list<int>> adj;

  for (int i = 0; i < e; i++) {
    int u = edges[i][0];
    int v = edges[i][1];

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  int parent = -1, timer = 0;

  vector<int> discover(v, -1);
  vector<int> lowestTime(v, -1);
  unordered_map<int, bool> visited;

  vector<vector<int>> ans;

  for (int i = 0; i < v; i++) {
    if (!visited[i])
      dfs(i, parent, timer, discover, lowestTime, visited, adj, ans);
  }
  return ans;
}