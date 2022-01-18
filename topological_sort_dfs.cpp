#include "bits/stdc++.h"
using namespace std;

/*
Topological Sort is a linear ordering of vertices such that for all edges u -> v
u appears before v in the ordering.
topological sort can be done only on DAGs
which is Directed Acyclic Graphs
why?
because if there is a cycle in a directed graph
it will be of the form A->B->C->A this means B should appear after A
C should appear after B and A should appear after C
which cannot happen!
*/

const int N = 100;
vector<bool> visited(N, 0);

stack<int> s;

void topological_sort_dfs(vector<vector<int>>& graph, int root) {
	visited[root] = true;
	for (auto neigh : graph[root]) {
		if (!visited[neigh]) {
			topological_sort_dfs(graph, neigh);
		}
	}

	s.push(root);
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
	}

	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			topological_sort_dfs(graph, i);
		}
	}

	vector<int> order;
	while (!s.empty()) {
		order.push_back(s.top() + 1);
		s.pop();
	}

	for (auto nodes : order) {
		cout << nodes << ' ';
	}

	cout << '\n';

	return 0;
}