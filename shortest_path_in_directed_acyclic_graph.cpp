#include "bits/stdc++.h"
using namespace std;

const int N = 100;
vector<int> dis(N, INT_MAX - 10);
vector<bool> visited(N, 0);

void toposort_dfs(vector<vector<pair<int, int>>>& graph, int root, stack<int>& s) {
	visited[root] = true;
	for (auto neigh : graph[root]) {
		if (!visited[neigh.first]) {
			visited[neigh.first] = true;
			toposort_dfs(graph, neigh.first, s);
		}
	}

	s.push(root);
}

void shortest_path_dag(vector<vector<pair<int, int>>>& graph, int src, int n) {
	stack<int> s;
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			toposort_dfs(graph, i, s);
		}
	}

	dis[src] = 0;
	while (!s.empty()) {
		int node = s.top();
		s.pop();
		if (dis[node] != INT_MAX - 10) {
			for (auto neigh : graph[node]) {
				dis[neigh.first] = min(dis[neigh.first], dis[node] + neigh.second);
			}
		}
	}
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
	shortest_path_dag(graph, 0, n);

	for (int i = 0; i < n; i++) {
		(dis[i] == INT_MAX - 10) ? cout << "INF " : cout << dis[i] << ' ';
	}

	cout << '\n';

	return 0;
}