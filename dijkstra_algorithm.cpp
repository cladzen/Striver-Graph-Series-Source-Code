#include "bits/stdc++.h"
using namespace std;

#define INF INT_MAX

const int N = 100;
vector<int> dis(N, INF);

void dijkstra_algorithm(vector<vector<pair<int, int>>>& graph, int n, int src) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	dis[src] = 0;
	pq.push({dis[src], src});

	while (!pq.empty()) {
		pair<int, int> unpack = pq.top();
		pq.pop();
		int d = unpack.first;
		int node = unpack.second;

		for (auto p : graph[node]) {
			int w = p.second;
			int neigh = p.first;
			if (d + w < dis[neigh]) {
				dis[neigh] = d + w;
				pq.push({dis[neigh], neigh});
			}
		}
	}

	return;
}

int main() {
	int n, m;
	cin >> n >> m;

	vector<vector<pair<int, int>>> graph(n);
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		u--; v--;

		graph[u].push_back({v, w});
	}

	// source 0
	dijkstra_algorithm(graph, n, 0);

	for (int i = 0; i < n; i++) {
		(dis[i] == INF) ? cout << "INF " : cout << dis[i] << ' ';
	}

	cout << '\n';

	return 0;
}