#include<iostream>
#include<fstream>
#include<cstdio>
#include<algorithm>
#define MAX 1000000000
using namespace std;

int G[201][201];
int N, M, S, E, F;
int dust[201];
bool chk[201];

int dfs(int node) {
	if (node == E) {
		return dust[E];
	}

	int ret = MAX;
	for (int i = 1; i <= N; i++) {
		if (!chk[i] && G[node][i] == 1 && dust[i] < F) {
			chk[i] = true;
			ret = min(ret, dfs(i) + dust[node]);
			chk[i] = false;
		}
	}

	return ret;
}

int main() {
	ifstream f("input.txt");
	int CA;
	f >> CA;

	for (int ca = 1; ca <= CA; ca++) {
		f >> N >> M >> S >> E >> F;

		for (int i = 1; i <= N; i++) {
			dust[i] = 0;
			chk[i] = false;
		}

		for (int i = 1; i <= N; i++) {
			int d;
			f >> d;
			dust[i] = d;
		}

		for (int i = 1; i <= M; i++) {
			int s, e;
			f >> s >> e;
			G[s][e] = G[e][s] = 1;
		}

		chk[S] = true;
		int res = MAX;
		res = dfs(S);

		printf("#%d %d\n", ca, res);
		
	}
	return 0;
}

=======================================================

2
8 11 1 8 120
30 60 13 120 22 53 63 10
1 2
1 4 
1 5
2 3
3 4
3 7
5 4
4 7
4 6
6 8
7 8
5 8 4 2 133
143 82 126 62 35 
4 2
4 1
5 2
1 2
2 3
4 5
3 1
5 1
