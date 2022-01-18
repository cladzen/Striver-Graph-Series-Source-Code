#include "bits/stdc++.h"
using namespace std;

const int N = 100;
vector<bool> visited(N, 0);
vector<int> paint(N, -1);

bool bipartite_dfs_recursive(vector<vector<int>>& graph, int root) {
	for (auto neigh : graph[root]) {
		if (!visited[neigh]) {
			visited[neigh] = true;
			paint[neigh] = 1 - paint[root];
			if (!bipartite_dfs_recursive(graph, neigh))
				return false;
		}
		else {
			if (paint[neigh] == paint[root])
				return false;
		}
	}

	return true;
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
		graph[v].push_back(u);
	}

	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			visited[i] = true;
			paint[i] = 0;
			if (!bipartite_dfs_recursive(graph, i)) {
				cout << "NO" << '\n';
				return 0;
			}
		}
	}

	cout << "YES" << '\n';

	return 0;
}