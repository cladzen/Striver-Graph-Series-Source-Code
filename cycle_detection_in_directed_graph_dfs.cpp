#include "bits/stdc++.h"
using namespace std;

const int N = 100;
vector<bool> visited(N, 0);
vector<bool> curdfs(N, 0);

bool detect_cycle_directed_dfs(vector<vector<int>>& graph, int root) {
	visited[root] = true;
	curdfs[root] = true;
	for (auto neigh : graph[root]) {
		if (!visited[neigh]) {
			if (detect_cycle_directed_dfs(graph, neigh)) return true;
		}
		else {
			if (curdfs[neigh]) {
				return true;
			}
		}
	}

	curdfs[root] = false;
	return false;
}

int main() {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> graph(n);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;

		graph[u].push_back(v);
	}

	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			if (detect_cycle_directed_dfs(graph, i)) {
				cout << "YES" << '\n';
				return 0;
			}
		}
	}

	cout << "NO" << '\n';

	return 0;
}