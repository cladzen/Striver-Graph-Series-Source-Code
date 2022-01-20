#include "bits/stdc++.h"
using namespace std;

/*
if we reverse the edges of the entire graph
the SCC remains SCC
watch the coding ninjas video on the topic if anything is not clear
*/

const int N = 100;
vector<bool> visited(N, 0);

stack<int> s;

vector<vector<int>> graph_transpose(vector<vector<int>>& graph, int n) {
	vector<vector<int>> transposed(n);
	for (int i = 0; i < n; i++) {
		for (auto v : graph[i]) {
			transposed[v].push_back(i);
		}
	}

	return transposed;
}

void dfs1(vector<vector<int>>& graph, int root) {
	visited[root] = true;
	for (auto neigh : graph[root]) {
		if (!visited[neigh]) {
			dfs1(graph, neigh);
		}
	}

	s.push(root);
}

void dfs2(vector<vector<int>>& graph, vector<vector<int>>& scc, int root, int com) {
	visited[root] = true;
	for (auto neigh : graph[root]) {
		if (!visited[neigh]) {
			scc[com - 1].push_back(neigh);
			dfs2(graph, scc, neigh, com);
		}
	}
}

vector<vector<int>> kosaraju_algorithm(vector<vector<int>>& graph, int n) {
	for (int i = 0; i < n; i++) {
		visited[i] = false;
	}

	vector<vector<int>> scc;
	int com = 0;

	while (!s.empty()) {
		int node = s.top();
		s.pop();

		if (!visited[node]) {
			scc.push_back({node});
			com += 1;
			dfs2(graph, scc, node, com);
		}
	}

	return scc;
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
			dfs1(graph, i);
		}
	}

	stack<int> t = s;
	while (!t.empty()) {
		cout << t.top() << ' ';
		t.pop();
	}

	cout << '\n';

	vector<vector<int>> graphdash = graph_transpose(graph, n);

	for (int i = 0; i < n; i++) {
		cout << i << ": ";
		for (auto v : graphdash[i]) {
			cout << v << ' ';
		}

		cout << '\n';
	}

	vector<vector<int>> scc = kosaraju_algorithm(graphdash, n);

	for (int i = 0; i < scc.size(); i++) {
		for (auto v : scc[i]) {
			cout << v << ' ';
		}

		cout << '\n';
	}

	return 0;
}