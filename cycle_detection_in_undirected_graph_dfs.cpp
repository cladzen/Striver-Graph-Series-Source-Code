#include "bits/stdc++.h"
using namespace std;

const int N = 100;
vector<bool> visited(N, 0);

bool detect_cycle_dfs(vector<vector<int>>& graph, int n) {
	stack<pair<int, int>> s;
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			s.push({i, -1});
			visited[i] = true;

			while (!s.empty()) {
				pair<int, int> node = s.top();
				s.pop();
				for (auto neigh : graph[node.first]) {
					if (!visited[neigh]) {
						s.push({neigh, node.first});
						visited[neigh] = true;
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

	return true;
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

	if (detect_cycle_dfs(graph, n)) cout << "YES" << '\n';
	else cout << "NO" << '\n';

	return 0;
}