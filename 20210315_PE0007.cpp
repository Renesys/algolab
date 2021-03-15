#include<iostream>
#include<fstream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

struct Info {
	int src;
	int dest;
	int cost;
};

int G[100001];
int W[100001];

int find(int N) {
	if (G[N] == N) {
		return N;
	}
	return G[N] = find(G[N]);
}

void uni(int a, int b) {
	int pa = find(a);
	int pb = find(b);
	if (pa == pb) {
		return;
	}
	if (W[pa] > W[pb]) {
		G[pb] = pa;
	}
	else if(W[pa] < W[pb]){
		G[pa] = pb;
	}
	else {
		G[pb] = pa;
		W[pa]++;
	}
}

bool cmp(const Info &a, const Info &b) {
	return a.cost < b.cost;
}

int main() {
	ifstream f("input.txt");
	int CA;
	f >> CA;

	for (int ca = 1; ca <= CA; ca++) {
		int N, M, K;
		f >> N >> M >> K;
		vector<Info> v;

		for (int i = 1; i <= N; i++) {
			G[i] = i;
			W[i] = 1;
		}

		int s, d, c;
		for (int i = 1; i <= M; i++) {
			f >> s >> d >> c;
			v.push_back({ s, d, -c });
		}
		for (int i = 1; i <= K; i++) {
			f >> s >> d >> c;
			v.push_back({ s, d, c });
		}

		sort(v.begin(), v.end(), cmp);

		int res = 0;
		for (auto e : v) {
			if (e.cost < 0) {
				if (find(e.src) != find(e.dest)) {
					uni(e.src, e.dest);
				}
				else {
					res += (-e.cost);
				}
			}
			else {
				if (find(e.src) != find(e.dest)) {
					uni(e.src, e.dest);
					res += e.cost;
				}
			}

		}

		printf("#%d %d\n", ca, res);
	}
	return 0;
}

==========================
1
10 5 5
1 8 23
8 4 8
4 5 23
5 2 15
2 6 9
6 9 26
9 10 2
10 3 24
3 7 17
7 1 19
