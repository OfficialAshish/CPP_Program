#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <set>
#include <climits>

using namespace std;


vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges,
                     int source) {

  vector<int> dist(vertices);

  unordered_map<int, list<pair<int, int>>> adjList;

  for (int i = 0; i < edges; i++) {
    int u = vec[i][0];
    int v = vec[i][1];
    int w = vec[i][2];

    adjList[u].push_back(make_pair(v, w));
    adjList[v].push_back(make_pair(u, w));
  }

  for (int i = 0; i < vertices; i++) {
    dist[i] = INT_MAX;
  }

  // distance,node pairs
  set<pair<int, int>> st;

  dist[source] = 0;
  st.insert(make_pair(0, source));

  while (!st.empty()) {
    auto top = *(st.begin());
    int minTopDist = top.first, topNode = top.second;
    st.erase(st.begin());

    for (auto nd : adjList[topNode]) {
      if (minTopDist + nd.second < dist[nd.first]) {
        auto fnd = st.find(make_pair(dist[nd.first], nd.first));
        if (fnd != st.end()) {
          st.erase(fnd);
        }
        dist[nd.first] = nd.second + minTopDist;
        st.insert(make_pair(dist[nd.first], nd.first));
      }
    }
  }

  return dist;
}


int main() {
    int vertices = 6; // Number of vertices
    int edges = 9;    // Number of edges

    // Define the edges in the format {u, v, weight}
    vector<vector<int>> edgesList = {
        {0, 1, 2},
        {0, 2, 4},
        {1, 2, 1},
        {1, 3, 7},
        {2, 4, 3},
        {3, 4, 1},
        {3, 5, 5},
        {4, 5, 2},
        {2, 5, 6}
    };

    int source = 0; // Source vertex

    vector<int> distances = dijkstra(edgesList, vertices, edges, source);

    cout << "Shortest distances from source " << source << " to all vertices:\n";
    for (int i = 0; i < vertices; ++i) {
        cout << "Vertex " << i << ": " << distances[i] << endl;
    }

    return 0;
}
