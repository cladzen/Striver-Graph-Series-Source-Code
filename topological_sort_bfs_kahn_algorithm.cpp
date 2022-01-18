#include "bits/stdc++.h"
using namespace std;

/*
Kahn's Algorithm
*/

const int N = 100;
vector<int> indegree(N, 0);

vector<int> kahn_algorithm(vector<vector<int>>& graph, int n) {
	queue<int> q;
	for (int i = 0; i < n; i++) {
		if (indegree[i] == 0) {
			q.push(i);
		}
	}

	vector<int> order;
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		order.push_back(node);

		for (auto neigh : graph[node]) {
			indegree[neigh] -= 1;
			if (indegree[neigh] == 0) {
				q.push(neigh);
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
		indegree[v] += 1;
	}

	vector<int> order = kahn_algorithm(graph, n);
	for (auto nodes : order) {
		cout << nodes + 1 << ' ';
	}

	cout << '\n';

	return 0;
}