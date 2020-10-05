// Bellman Ford's algorithm is used to find the shortest paths from the source vertex 
// to ALL other vertices in a weighted graph

// LOGIC: 
// Shortest path contains at most (n - 1) edges, 
//   because the shortest path couldn't have a cycle.

// Bellman Ford checks if there is a negative cycle in the graph

#include <queue>
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

vector <pair <int, pair <int, int> > > edges;
vector <int> dist(101, INT_MAX);

// negative cycle test done if outer loop runs 1 more time

void BF(int src, int vertexCount) {
	dist[0] = 0;
    for(int i = 1; i <= vertexCount - 1; i++) {
		for (int j = 0; j < edges.size(); j++) {
			int u = edges[j].first; // from
			int v = edges[j].second.first; // to
			int val = edges[j].second.second; // weight

			if (dist[u] + val < dist[v]) {
				dist[v] = dist[u] + val;
			}
		}
	}
}