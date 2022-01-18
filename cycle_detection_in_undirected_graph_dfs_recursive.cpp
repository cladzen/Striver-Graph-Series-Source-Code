#include "bits/stdc++.h"
using namespace std;

const int N = 100;
vector<bool> visited(N, 0);

bool detect_cycle_dfs_recursive(vector<vector<int>>& graph, int root, int parent = -1) {
	for (auto node : graph[root]) {
		if (!visited[node]) {
			visited[node] = true;
			bool res = detect_cycle_dfs_recursive(graph, node, root);
			if (res) return true;
		}
		else {
			if (node != parent) return true;
		}
	}

	return false;
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

	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			visited[i] = true;
			if (detect_cycle_dfs_recursive(graph, i)) {
				cout << "YES" << '\n';
				return 0;
			}
		}
	}

	cout << "NO" << '\n';

	return 0;
}