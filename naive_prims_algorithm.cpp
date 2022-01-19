#include "bits/stdc++.h"
using namespace std;

#define INF INT_MAX

/*
prims algorithm is a greedy algorithm to find the minimum spanning tree of a weighted undirected graph
the algorithm tries to divide the graph into two parts of visited and unvisited nodes
and we will choose the best edge (with the minimum weight) to connect the two parts
so the edge we choose should have one end in the visited part and the other end in the unvisited part
and then we will update the visited and the unvisited parts and look for the edges in the similar way

this algorithm can be understood by the fact that we try to connect the entire graph at the end
so at each stage we are choosing the best edge to connect the two components of visited and unvisited nodes

the algorithm can be proved very easily
suppose you have the minimum spanning tree of a graph G
and you have the spanning tree produced by the prims algorithm
there must be atleast one edge in our tree that is not present in the minimum spanning tree
lets say this edge is e(a, b) the edge connects the two vertices a and b

the two vertices will be connected via some path in the minimum spanning tree
lets call this path P

now consider the time while running the prims algorithm you had to choose the minimum path to connect the visited and the unvisited components
and you chose e(a, b) using the prims algorithm, which means that e(a, b) had to be the minimum weight edge that connect the two components
(visited and unvisited)
i claim that at that time there had to be some edge in the path P which could have also been choosen by the prims algorithm but the edge was just
not the minimum (or the best)
why is that there has to an edge in P such that it was having one end in visited and one in unvisited components at the time when e(a, b) was also
having one end in visited and one end in unvisited components?
because if there was no edge in P of such kind at that time
then all edges of P are already in the visited component
which means that a and b are already in the visited component
but they are not
so there has to be some edge which satisfy the claim

now since we chose e(a, b) over that edge to connect the two components this means that the weight(a, b) should be <= to the weight of that edge
so if we remove that edge from the Minimum spanning tree and add e(a, b) (which is not there in the supposed MST) the weight will decrease or remain the same
which proves the optimality of prims algorithm.
*/

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

	// the key array will store the minimum distance of unvisited nodes from the contracted visited component
	// by contraction i mean we can merge the visited nodes together
	// you can understand more about contraction from the MIT opencourseware
	vector<int> key(n, INF);
	vector<bool> mst(n, 0);
	vector<int> parent(n, -1);

	key[0] = 0;
	for (int i = 0; i < n - 1; i++) {
		int minedge = INT_MAX;
		int vertex = -1;
		for (int j = 0; j < n; j++) {
			if (key[j] < minedge) {
				if (mst[j] == 0) {
					minedge = key[j];
					vertex = j;
				}
			}
		}

		if (vertex == -1) break;
		mst[vertex] = true;

		for (auto neigh : graph[vertex]) {
			if (mst[neigh.first] == 0) {
				if (neigh.second < key[neigh.first]) {
					key[neigh.first] = neigh.second;
					parent[neigh.first] = vertex;
				}
			}
		}
	}

	for (int i = 1; i < n; i++) {
		cout << parent[i] << ' ' << i;
		cout << '\n';
	}

	return 0;
}
