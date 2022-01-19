#include "bits/stdc++.h"
using namespace std;

int n;
vector<int> parent(n);
vector<int> rankk(n);

void init() {
	for (int i = 0; i < n; i++) {
		parent[i] = i;
		rankk[i] = 0;
	}
}

int find(int node) {
	if (parent[node] == node) return node;
	return parent[node] = find(parent[node]);
}

void merge(int u, int v) {
	u = find(u);
	v = find(v);

	if (u == v) return;

	if (rankk[u] < rankk[v]) {
		parent[u] = v;
	}
	else if (rankk[u] > rankk[v]) {
		parent[v] = u;
	}
	else {
		parent[v] = u;
		rankk[u] += 1;
	}
}

int main() {
	cin >> n;

	init();

	int m;
	cin >> m;

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;

		merge(u, v);
	}



	return 0;
}