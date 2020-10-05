// Prim code

// LOGIC :
// 1. builds the spanning tree by ADDING VERTEX one by one into a growing spanning tree
// 2. Select the cheapest vertex that is connected to the growing spanning tree and is 
//    not in the growing spanning tree and add it into the growing spanning tree (GREEDY)
// 3. add it to the growing spanning tree. (VERTEX WHICH DON'T FORM A CYCLE)

#include <queue>
#include <iostream>
#include <vector>
using namespace std;

vector <pair <int, int> > graph[101];
vector <bool> visited(101, false);

int prim(int src) {
	priority_queue <pair <int, int>, vector <pair <int, int> >, greater <pair <int, int> > > q;
	int ans = 0;
	q.push(make_pair(0, src));
	while (!q.empty()) {
		int u = q.top().second;
		int val = q.top().first;
		q.pop();
		if (visited[u]) {
			continue;
		}
		visited[u] = 1;
		ans += val;
		for (int i = 0; i < graph[u].size(); i++) {
			int v = graph[u][i].second;
			if (visited[v] == false) {
				q.push(graph[u][i]);
			}
		} 
	}
	return ans;
}