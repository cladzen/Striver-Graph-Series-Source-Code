#include "bits/stdc++.h"
using namespace std;

const int N = 100;
vector<int> dis(N, INT_MAX - 10);

void shortest_path(vector<vector<int>>& graph, int src) {
	dis[src] = 0;
	queue<int> q;
	q.push(src);

	while (!q.empty()) {
		int node = q.front();
		q.pop();
		for (auto neigh : graph[node]) {
			if (dis[node] + 1 < dis[neigh]) {
				q.push(neigh);
				dis[neigh] = dis[node] + 1;
			}
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> graph(n);
	for (int i = 0; i < n; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;

		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	// source 0
	shortest_path(graph, 0);

	for (int i = 0; i < n; i++) {
		cout << dis[i] << ' ';
	}

	cout << '\n';

	return 0;
}