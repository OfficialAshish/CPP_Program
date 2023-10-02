#include <bits/stdc++.h>
vector<pair<pair<int, int>, int>>
calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g) {
  unordered_map<int, list<pair<int, int>>> adjList;

  for (int i = 0; i < m; i++) {
    int u = g[i].first.first;
    int v = g[i].first.second;
    int w = g[i].second;

    adjList[u].push_back(make_pair(v, w));
    adjList[v].push_back(make_pair(u, w));
  }
  vector<int> key(n + 1, INT_MAX);
  vector<int> parent(n + 1, -1);
  vector<bool> inMST(n + 1, false);

  priority_queue<pair<int,int> , vector<pair<int,int> > , greater<pair<int,int> >> pq;

  // begin
  key[1] = 0;
  parent[1] = -1;
  pq.push(make_pair(0,1));

  // for (int j = 1; j < n; j++) {
  while (!pq.empty()) {

    // finding minim node as u
    // int u;

    int u = pq.top().second;
    pq.pop();

    // for (int v = 1, mini = INT_MAX; v <= n; v++) {
    //   if (inMST[v] == false && key[v] < mini) {
    //     u = v;
    //     mini = key[v];
    //   }
    // }

  if (inMST[u]) continue;
    // make min node as true
    inMST[u] = true;

    for (auto neighbor : adjList[u]) {
      int v = neighbor.first;
      int weight = neighbor.second;

      if (!inMST[v] && weight < key[v]) {
        key[v] = weight;
        parent[v] = u;
        pq.push({key[v], v});
      }
    }
  }
  vector<pair<pair<int, int>, int>> result;

  for (int i = 2; i <= n; i++) {
    result.push_back( { {i, parent[i]}, key[i]} );
  }
  return result;
}
