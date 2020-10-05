// SPANNING TREE : includes every vertex of the parent graph &  is a tree.
// MINIMUM SPANNING TREE : where the cost is minimum among all the spanning trees

// Kruskal code

// LOGIC :
// builds the spanning tree by ADDING EDGES one by one into a growing spanning tree
// in each iteration it finds an edge which has least weight (GREEDY)
// add it to the growing spanning tree. (EDGES WHICH DON'T FORM A CYCLE)

#include <queue>
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

// GRAPH REPRESENTATION : 
vector <pair <int, pair <int, int> > > edges;

// DSU
int par[101], sz[101];

void init(){
	for (int i = 0; i < 101; i++) {
		par[i] = i;
		sz[i] = 1;
	}
}

int find(int x) {
	if (par[x] != x) {
		par[x] = find(par[x]);
	}
	return par[x];
}

void merge(int x, int y) {
	int xRoot = find(x), yRoot = find(y);
	if (xRoot == yRoot) {
		return;
	}
	if (sz[xRoot] >= sz[yRoot]) {
		par[yRoot] = xRoot;
		sz[xRoot] += sz[yRoot];
	} else {
		par[xRoot] = yRoot;
		sz[yRoot] += sz[xRoot];
	}
}

int kruskal() {
	int ans = 0;
	sort(edges.begin(), edges.end());
	for (int i = 0; i < edges.size(); i++) {
		int u = edges[i].second.first;
		int v = edges[i].second.first;
		int val = edges[i].first;
		if (find(u) != find(v)) {
			ans += val;
			merge(u, v);
		}
	}
	return ans;
}
