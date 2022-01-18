#include "bits/stdc++.h"
using namespace std;

const int N = 100;
vector<int> visited(N, 0);
vector<int> paint(N, -1);

bool bipartite_dfs(vector<vector<int>>& graph, int n) {
	stack<int> s;
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			s.push(i);
			visited[i] = true;
			paint[i] = 0;

			while (!s.empty()) {
				int node = s.top();
				s.pop();
				for (auto neigh : graph[node]) {
					if (!visited[neigh]) {
						visited[neigh] = true;
						paint[neigh] = 1 - paint[node];
						s.push(neigh);
					}
					else {
						if (paint[neigh] == paint[node])
							return false;
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
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;

		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	if (bipartite_dfs(graph, n)) cout << "YES" << '\n';
	else cout << "NO" << '\n';

	return 0;
}