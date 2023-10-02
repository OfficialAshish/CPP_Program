#include <bits/stdc++.h>

vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	unordered_map<int, list<int>> adjList;
	for(int i=0; i<edges.size(); i++)
	{
		int u=edges[i].first;
		int v=edges[i].second;

		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}

	// vector<int> parent(n);
	unordered_map<int,int> parents;
	unordered_map<int , bool> visited;

	queue <int> q;

	q.push(s);
	visited[s]=1;
	parents[s]=-1;

	while(!q.empty())
	{
		int f = q.front();
		q.pop();

		for(auto neig: adjList[f]){
			if(!visited[neig]){
				visited[neig] = 1;
				parents[neig] = f;
				q.push(neig);
			}
		}
	}

	// parent is ready

	vector<int> ans;

	int current = t;
	ans.push_back(t);

	while(current != s)
	{
		current = parents[current]; //gets the parent of current node
		ans.push_back(current);
	}
	reverse(ans.begin(),ans.end());
	return ans;

	
}
