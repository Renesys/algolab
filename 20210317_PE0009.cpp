#include<iostream>
#include<fstream>
#include<cstdio>
#include<vector>
#include<deque>
#include<algorithm>
#define MAX 10000000000007
using namespace std;

struct Edge {
	int dest;
	int cost;
};

vector<Edge> G[100001];
bool chk[100001];
long long dist[100001];


void dijkstra(int N) {
	if (chk[N] || N == 0) {
		return;
	}
	chk[N] = true;

	long long tempdist = MAX;
	int next = 0;
	for (auto e : G[N]) {
		dist[e.dest] = min(dist[e.dest], dist[N] + e.cost);
		if (!chk[e.dest] && tempdist > dist[e.dest]) {
			tempdist = dist[e.dest];
			next = e.dest;
		}
	}
	dijkstra(next);
	return;
}

int main() {
	ifstream f("input.txt");
	int CA;
	f >> CA;

	for (int ca = 1; ca <= CA; ca++) {
		int V, E;
		f >> V >> E;

		for (int i = 1; i <= V; i++) {
			G[i].clear();
			chk[i] = false;
			dist[i] = MAX;
		}

		for (int i = 1; i <= E; i++) {
			int s, e, c;
			f >> s >> e >> c;
			G[s].push_back({ e,c });
			G[e].push_back({ s,c });
		}

		dist[1] = 0;
		dijkstra(1);
		
		printf("#%d %lld\n", ca, dist[V]);

	}
	return 0;
}

===============================
2
3 3
1 2 3
2 3 1
1 3 2
6 9
1 2 2
1 3 4
2 3 1
2 5 2
2 4 4
3 5 3
4 5 3
4 6 2
5 6 2
