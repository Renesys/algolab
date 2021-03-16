#include<iostream>
#include<fstream>
#include<cstdio>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;

vector<int> G[100001];
int order[100001];
bool chk[100001];
int seq;

int dfs(int N, bool is_root) {
	order[N] = ++seq;
	int ret = order[N];
	int child = 0;

	for (auto e : G[N]) {
		if (order[e]) {
			ret = min(ret, order[e]);
			continue;
		}
		child++;
		int pre = dfs(e, false);
		if (!is_root && pre >= order[N]) {
			chk[N] = true;
		}
		ret = min(ret, pre);
	}
	if (is_root && child >= 2) {
		chk[N] = true;
		
	}
	
	return ret;
}

int main() {
	ifstream f("input.txt");
	int CA;
	f >> CA;

	for (int ca = 1; ca <= CA; ca++) {
		int V, E;
		f >> V >> E;
		//init
		seq = 0;
		for (int i = 1; i <= V; i++) {
			G[i].clear();
			chk[i] = false;
			order[i] = 0;
		}
		for (int i = 1; i <= E; i++) {
			int a, b;
			f >> a >> b;
			G[a].push_back(b);
			G[b].push_back(a);
		}

		for (int i = 1; i <= V; i++) {
			if (!order[i]) {
				dfs(i, true);
			}
		}

		int cnt = 0;
		for (int i = 1; i <= V; i++) {
			if (chk[i]) {
				cnt++;
			}
		}
		printf("#%d %d ", ca, cnt);
		for (int i = 1; i <= V; i++) {
			if (chk[i]) {
				printf("%d ", i);
			}
		}
		printf("\n");

	}
	return 0;
}

======================================================
30
9 10
4 1
1 2
2 3
2 7
7 3
7 6
4 8
1 5
5 8
8 9
5 5
1 2
1 3
4 2
5 3
5 4
10 15
1 5
8 10
9 1
5 3
8 7
6 5
2 6
4 6
1 2
10 1
1 7
1 6
2 8
4 3
8 5
20 25
16 12
19 6
14 2
19 2
20 8
19 5
17 2
6 11
2 13
10 9
19 10
6 2
16 2
11 18
14 8
18 2
12 18
19 13
12 3
15 6
3 18
20 18
7 2
20 4
2 1
10 15
1 10
8 1
1 6
1 4
1 3
5 1
5 10
3 7
9 1
8 6
10 9
4 2
7 6
4 5
4 9
