#include <iostream>
#include<fstream>
#include<vector>
#include<string>
#include<queue>
#include<unordered_map>
using namespace std;
typedef pair<int, int> pii;      // pair int
typedef vector< pii > vii;	     // vector of pair int int
void make_path(vector<pair<int, int>> *G, int source, int N, vector<int> *map_direction)
{
	vector<int> dist;										//distance from source
	vector<bool> visited(N, false);
	dist.assign(N, INT_MAX);
	dist[source] = 0;
	map_direction[source].push_back(source);
	priority_queue<pii, vector<pii>, greater<pii> > Q;
	Q.push({ source,0 });
	while (!Q.empty())
	{
		int u = Q.top().first;
		Q.pop();
		visited[u] = true;
		for (auto &c : G[u])
		{
			if (!visited[c.first])
			{
				int w = c.second;
				int v = c.first;
				if (dist[v] > dist[u] + w)
				{
					dist[v] = dist[u] + w;
					map_direction[v] = map_direction[u];
					map_direction[v].push_back(v);
					Q.push({ v,dist[v] });
				}
			}
		}


	}
}