#include<iostream>
#include<fstream>
#include<cstdio>
#include<utility>
#include<vector>
#include<queue>
#include<algorithm>
#define MAX 100000000
using namespace std;

int cost[1001];
vector<pair<int, int> > g[1001];
int dist[1001];
bool chk[1001];

struct cmp {
	bool operator()(pair<int, int>& a, pair<int, int>& b) {
		if (a.second == b.second) {
			return a.first > b.first;
		}
		return a.second > b.second;
	}
};




void dijkstra(int N, int V) {
	priority_queue<pair<int, int>, vector<pair<int, int> >, cmp> pq;
	int target = N;
	dist[target] = 0;
	pq.push(make_pair( N, 0 ));

	while (!pq.empty()) {
		if (g[target].size() == 0)
			break;
		pair<int, int> t = pq.top();
		target = t.first;
		pq.pop();
		if (dist[t.first] < t.second)
			continue;
		for (auto e : g[target]) {
			if (dist[e.first] > dist[target] + e.second) {
				dist[e.first] = dist[target] + e.second;
			}
			pq.push(make_pair(e.first, dist[target] + e.second));
		}

		for (int i = 1; i <= V; i++) {
			cout << dist[i] << ' ';
		}
		cout << endl;
	}
}

int main() {
	ifstream f("input.txt");
	int CA;
	f >> CA;
	for (int ca = 1; ca <= CA; ca++) {
		int V, E, P;
		f >> V >> E >> P;
		for (int i = 1; i <= V; i++) {
			g[i].clear();
			cost[i] = MAX;
			dist[i] = MAX;
			chk[i] = false;
		}
		for (int i = 0; i < E; i++) {
			int a, b, d;
			f >> a >> b >> d;
			g[a].push_back(make_pair(b, d));
		}

		
		cost[P] = 0;
		dijkstra(P, V);
		for (int i = 1; i <= V; i++) {
			cost[i] = dist[i];
		}

		int res = -1;
		for (int i = 1; i <= V; i++) {
			if (i == P)
				continue;
			for (int j = 0; j <= V; j++) {
				dist[j] = MAX;
				chk[j] = false;
			}
			cout << "start : " << i << endl;
			dijkstra(i, V);
			cost[i] += dist[P];
			if (cost[i] > res) {
				res = cost[i];
			}
		}

		printf("#%d %d\n", ca, res);
	}
	return 0;
}
