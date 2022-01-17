#include "bits/stdc++.h"
using namespace std;

const int N = 100;
vector<bool> visited(N, 0);

void dfs(vector<vector<int>>& graph, int root, vector<int>& order) {
	order.push_back(root + 1);
	visited[root] = true;
	for (auto neigh : graph[root]) {
		if (!visited[neigh]) {
			dfs(graph, neigh, order);
		}
	}

	return;
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

	vector<int> order;
	for (int i = 0; i < n; i++) {
		if (!visited[i])
			dfs(graph, i, order);
	}

	for (auto node : order) {
		cout << node << ' ';
	}

	cout << '\n';

	return 0;
}