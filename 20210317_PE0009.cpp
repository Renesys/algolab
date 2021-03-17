#include<iostream>
#include<fstream>
#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
#define MAX 1000000000
using namespace std;

struct Edge {
	int dest;
	int cost;
};

vector<Edge> G[100001];
bool chk[100001];
long long dist[100001];
int V;

struct cmp {
	bool operator()(pair<int, long long> &a, pair<int, long long> &b) {
		if (a.second == b.second) {
			return a.first < b.first;
		}
		return a.second > b.second;
	}
};

void dijkstra(int N) {
	priority_queue<pair<int, long long>, vector<pair<int, long long> >, cmp> pq;
	int node = N;
	pq.push(make_pair(node, 0));

	while (!pq.empty()) {
		if (G[node].size() == 0) break;
		pair<int, long long> p = pq.top();
		node = p.first;

		//cout << node << endl;
		chk[node] = true;
		pq.pop();

		if (dist[node] < p.second) {
			continue;
		}

		for (auto e : G[node]) {
			if (!chk[e.dest] && dist[e.dest] > dist[node] + e.cost) {
				dist[e.dest] = dist[node] + e.cost;
				pq.push(make_pair(e.dest, dist[e.dest]));
			}
		}
		/*
		for (int i = 1; i <= V; i++) {
			cout << dist[i] << ' ';
		}
		cout << endl;
		*/
	}
}

int main() {
	ifstream f("input.txt");
	int CA;
	f >> CA;

	for (int ca = 1; ca <= CA; ca++) {
		int E;
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
30 50 
11 29 17 
11 30 27 
18 4 27 
18 15 21 
8 21 24 
13 26 8 
24 29 56 
27 26 61 
4 5 45 
20 16 71 
18 1 91 
21 11 74 
5 11 93 
8 4 38 
23 7 56 
8 12 15 
30 12 75 
23 22 69 
12 15 100 
18 28 38 
11 26 42 
19 6 81 
21 3 63 
16 23 47 
30 26 30 
7 16 14 
28 23 82 
19 25 37 
14 30 14 
30 29 16 
7 10 38 
29 25 68 
11 30 96 
1 14 23 
26 2 4 
26 9 58 
20 7 7 
21 26 96 
2 5 43 
30 4 55 
11 9 22 
3 11 41 
30 1 61 
23 14 18 
27 6 59 
9 25 68 
18 26 10 
22 6 76 
24 10 48 
26 30 54 
