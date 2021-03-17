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
	int val;
};

vector<Edge> G[50001];
vector<Edge> RG[50001];

long long dist[50001];
long long rev[50001];

bool chk[50001];
bool rev_chk[50001];

int V;

struct cmp {
	bool operator()(pair<int, long long> &a, pair<int, long long> &b) {
		if (a.first == b.first) {
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
		//if (G[node].size() == 0) break;
		pair<int, long long> info = pq.top();
		node = info.first;
		chk[node] = true;
		pq.pop();

		//result will be ommitted if distance is shorter than target node's it.
		if (dist[node] < info.second) continue;

		for (auto e : G[node]) {
			if (!chk[e.dest] && dist[e.dest] > dist[node] + e.val) {
				dist[e.dest] = dist[node] + e.val;
				pq.push(make_pair(e.dest, dist[e.dest]));
			}
		}

		for (int i = 1; i <= V; i++) {
			cout << dist[i] << ' ';
		}
		cout << endl;
	}
}

void rev_dijkstra(int N) {
	priority_queue<pair<int, long long>, vector<pair<int, long long> >, cmp> pq;
	int node = N;
	rev[node] = 0;
	pq.push(make_pair(node, 0));

	while (!pq.empty()) {
		//if (RG[node].size() == 0) break;
		pair<int, long long> info = pq.top();
		node = info.first;
		rev_chk[node] = true;
		pq.pop();

		//result will be ommitted if distance is shorter than target node's it.
		if (rev[node] < info.second) continue;

		for (auto e : RG[node]) {
			if (!rev_chk[e.dest] && rev[e.dest] > rev[node] + e.val) {
				rev[e.dest] = rev[node] + e.val;
				pq.push(make_pair(e.dest, rev[e.dest]));
			}
		}
	}
}

int main() {
	ifstream f("input.txt");
	int CA;
	f >> CA;

	for (int ca = 1; ca <= CA; ca++) {
		int E, P;
		f >> V >> E >> P;

		for (int i = 1; i <= V; i++) {
			G[i].clear();
			RG[i].clear();
			dist[i] = rev[i] = MAX;
			chk[i] = rev_chk[i] = false;
		}

		for (int i = 1; i <= E; i++) {
			int s, e, v;
			f >> s >> e >> v;
			G[s].push_back({ e, v });
			RG[e].push_back({ s, v });
		}

		dist[P] = rev[P] = 0;
		dijkstra(P);
		rev_dijkstra(P);

		for (int i = 1; i <= V; i++) {
			cout << dist[i] << ' ';
		}
		cout << endl;
		for (int i = 1; i <= V; i++) {
			cout << rev[i] << ' ';
		}
		cout << endl;

		long long res = 0;
		for (int i = 1; i <= V; i++) {
			res = max(res, dist[i] + rev[i]);
		}

		printf("#%d %lld\n", ca, res);

	}
	return 0;
}
