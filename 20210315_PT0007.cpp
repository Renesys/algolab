#include<iostream>
#include<fstream>
#include<cstdio>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;

struct Edge {
	int src;
	int dest;
	int cost;
};

vector<Edge> v;

int G[50001];
int W[50001];

int find(int N) {
	if (G[N] == N) {
		return N;
	}
	return G[N] = find(G[N]);
}

void uni(int a, int b) {
	int pa = G[a];
	int pb = G[b];

	if (W[pa] > W[pb]) {
		G[pb] = pa;
	}
	else if (W[pa] < W[pb]) {
		G[pa] = pb;
	}
	else {
		G[pa] = pb;
		W[pb]++;
	}
}

bool cmp(const Edge &a, const Edge &b) {
	return a.cost < b.cost;
}

int main() {
	ifstream f("input.txt");
	int CA;
	f >> CA;

	for (int ca = 1; ca <= CA; ca++) {
		int V, E;
		f >> V >> E;

		v.clear();
		for (int i = 1; i <= V; i++) {
			G[i] = i;
			W[i] = 0;
		}

		for (int i = 1; i <= E; i++) {
			int s, e, c;
			f >> s >> e >> c;
			v.push_back({ s, e, c });
		}

		sort(v.begin(), v.end(), cmp);

		long long res = 0;
		for (auto e : v) {
			if (find(G[e.src]) != find(G[e.dest])) {
				uni(e.src, e.dest);
				res += e.cost;
			}
		}

		printf("#%d %lld\n", ca, res);

	}
	return 0;
}

================================
3
5
8
1 2 4
1 3 9
1 4 21
2 3 8
2 4 17
3 4 16
5 2 20
5 4 30
5
10
4 5 4104
1 4 6205
3 5 2697
1 2 1170
1 3 4437
3 4 1963
2 4 76
2 3 2750
1 5 2507
2 5 4790
10
30
1 7 5541
1 4 8902
1 6 2024
7 8 7993
7 9 3972
5 6 7520
1 2 7993
3 5 3723
4 10 3903
4 9 9514
2 7 6593
4 7 201
1 8 8517
8 9 8644
2 9 6636
5 9 7628
1 9 8568
3 9 9737
4 8 6164
4 6 6882
3 4 3251
3 6 8581
2 3 9248
7 10 9062
3 10 7460
6 8 1382
1 10 6914
3 8 234
2 10 7406
2 6 2348
