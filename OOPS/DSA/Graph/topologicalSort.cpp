#include <bits/stdc++.h>

// void sortTopoDFS(stack<int> &st, unordered_map<int, list<int>> adjList,
//                  vector<bool> &visited, int node) {

//   visited[node] = true;

//   for (int nig : adjList[node]) {
//     if (!visited[nig]) {
//       sortTopo(st, adjList, visited, nig);
//     }
//   }
//   st.push(node);
// }

/* vector<int> sortTopoBFS(unordered_map<int, list<int>> adjList,
                        vector<bool> &visited, int node) {


}
 */

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
{

  unordered_map<int, list<int>> adjList;
  vector<bool> visited;

  for (int i = 0; i < e; i++)
  {
    int u = edges[i][0];
    int v = edges[i][1];

    adjList[u].push_back(v);
  }

  // BFS
  queue<int> q;

  vector<int> indegree(v);
  vector<int> ans;
  for (auto i : adjList)
  {
    for (auto j : i.second)
      indegree[j]++;
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
      indegree[neig]--;
      if (indegree[neig] == 0)
        q.push(neig);
    }
  }
  return ans;

  /*

    vector<int> ans;
    stack<int> st;

    for (int i = 0; i < v; i++) {
      if (!visited[i]) {
        return sortTopoDFS(st,adjList, visited, i);
      }
    }
    while(!st.empty()) {
      ans.push_back(st.top());
      st.pop();
    }

    return ans;
     */
}