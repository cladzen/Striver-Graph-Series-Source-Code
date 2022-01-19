#include "bits/stdc++.h"
using namespace std;

#define INF INT_MAX

int main() {
	int n, m;
	cin >> n >> m;

	vector<vector<pair<int, int>>> graph(n);
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		u--; v--;

		graph[u].push_back({v, w});
		graph[v].push_back({u, w});
	}

	vector<int> parent(n, -1);
	vector<bool> mst(n, 0);
	vector<int> key(n, INF);

	// priority queue will contain all the edges with one end in visited component and another
	// end in un visited component with the weight of the edge
	// or we can say it contains edges from the contracted visited component with the weights
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	key[0] = 0;
	pq.push({0, 0});
	for (int i = 0; i < n - 1; i++) {
		pair<int, int> unpack = pq.top();
		pq.pop();

		int node = unpack.second;
		mst[node] = true;

		for (auto neigh : graph[node]) {
			// add only the edges which have one end in visited and another in unvisited component
			if (mst[neigh.first] == 0) {
				// if the edge weight is not less than the one in the key
				// this means that another edge is already present in the priority queue
				// which connect the given neigh to the visited component but with lesser weight
				// so we will connect them
				if (neigh.second < key[neigh.first]) {
					key[neigh.first] = neigh.second;
					pq.push({key[neigh.first], neigh.first});
					parent[neigh.first] = node;
				}
			}
		}
	}

	for (int i = 1; i < n; i++) {
		cout << parent[i] + 1 << ' ' << i + 1 << '\n';
	}

	return 0;
}