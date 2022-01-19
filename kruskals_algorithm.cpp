#include "bits/stdc++.h"
using namespace std;

const int N = 100;
int n;
vector<int> parent(N);
vector<int> rankk(N);

struct edge {
	int u;
	int v;
	int w;

	edge(int start, int end, int weight) {
		u = start;
		v = end;
		w = weight;
	}
};

bool cmp(edge a, edge b) {
	return a.w < b.w;
}

void init() {
	for (int i = 0; i < n; i++) {
		parent[i] = i;
		rankk[i] = 0;
	}
}

int find(int node) {
	if (parent[node] == node) return node;
	return parent[node] = find(parent[node]); // path compression
}

void merge(int u, int v) {
	u = find(u);
	v = find(v);

	if (u == v) return;

	if (rankk[u] > rankk[v]) {
		parent[v] = u;
	}
	else if (rankk[v] > rankk[u]) {
		parent[u] = v;
	}
	else {
		rankk[u] += 1;
		parent[v] = u;
	}
}

int main() {
	cin >> n;
	int m;
	cin >> m;

	vector<edge> edges;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		u--; v--;

		edges.push_back(edge(u, v, w));
	}

	sort(edges.begin(), edges.end(), cmp);

	init();

	int cost = 0;
	vector<pair<int, int>> mst;
	for (auto e : edges) {
		if (find(e.u) != find(e.v)) {
			cost += e.w;
			mst.push_back({e.u, e.v});
			merge(e.u, e.v);
		}
	}

	cout << cost << '\n';
	for (auto e : mst) {
		cout << e.first + 1 << ' ' << e.second + 1 << '\n';
	}

	return 0;
}