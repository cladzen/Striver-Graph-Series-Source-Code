#include "bits/stdc++.h"
using namespace std;

const int N = 100;
vector<int> indegree(N, 0);

bool detect_cycle_directed_bfs(vector<vector<int>>& graph, int n) {
	queue<int> q;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (indegree[i] == 0) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		int node = q.front();
		q.pop();
		cnt += 1;

		for (auto neigh : graph[node]) {
			indegree[neigh] -= 1;
			if (indegree[neigh] == 0) {
				q.push(neigh);
			}
		}
	}

	if (cnt == n) return false;
	else return true;
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
		indegree[v] += 1;
	}

	if (detect_cycle_directed_bfs(graph, n)) cout << "YES" << '\n';
	else cout << "NO" << '\n';

	return 0;
}