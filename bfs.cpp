#include "bits/stdc++.h"
using namespace std;

const int N = 100;
vector<bool> visited(N, 0);

vector<int> bfs(vector<vector<int>>& graph, int n) {
	vector<int> order;
	queue<int> q;
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			q.push(i);
			visited[i] = true;

			while (!q.empty()) {
				int node = q.front();
				q.pop();
				order.push_back(node + 1);

				for (auto neigh : graph[node]) {
					if (!visited[neigh]) {
						visited[neigh] = true;
						q.push(neigh);
					}
				}
			}
		}
	}

	return order;
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

	vector<int> order = bfs(graph, n);
	for (auto node : order) {
		cout << node << ' ';
	}

	cout << '\n';

	return 0;
}