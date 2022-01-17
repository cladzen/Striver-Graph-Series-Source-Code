#include "bits/stdc++.h"
using namespace std;

const int N = 100;
vector<bool> visited(N, 0);

bool detect_cycle_bfs(vector<vector<int>>& graph, int n) {
	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			q.push({i, -1});
			visited[i] = true;

			while (!q.empty()) {
				pair<int, int> node = q.front();
				q.pop();
				for (auto neigh : graph[node.first]) {
					if (!visited[neigh]) {
						visited[neigh] = true;
						q.push({neigh, node.first});
					}
					else {
						if (neigh != node.second) {
							return true;
						}
					}
				}
			}
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

	if (detect_cycle_bfs(graph, n)) cout << "YES" << '\n';
	else cout << "NO" << '\n';

	return 0;
}