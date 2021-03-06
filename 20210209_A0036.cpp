#include<iostream>
#include<fstream>
#include<cstdio>
#include<deque>
#include<vector>
#include<algorithm>
using namespace std;

int cont[1001];
vector<int> map[1001];
vector<int> virus;
bool chk[1001];
deque<pair<int, int> > q;

void bfs(pair<int, int> p) {
	q.pop_front();
	if (chk[p.first])
		return;
	chk[p.first] = true;
	if (cont[p.first] == 0 || cont[p.first] > p.second) {
		cont[p.first] = p.second;
	}
	for (auto e : map[p.first]) {
		if (!chk[e]) {
			q.push_back({ e, p.second + 1 });
		}
	}
}

int main() {
	ifstream f("input.txt");
	int CA;
	f >> CA;
	for (int ca = 1; ca <= CA; ca++) {
		int res = 10000001;
		int V, E, N;
		f >> V >> E >> N;
		virus.clear();
		q.clear();
		for (int i = 1; i <= V; i++) {
			map[i].clear();
		}

		for (int i = 0; i < N; i++) {
			int n;
			f >> n;
			virus.push_back(n);
		}
		for (int i = 1; i <= E; i++) {
			int s, e;
			f >> s >> e;
			map[s].push_back(e);
			map[e].push_back(s);
		}
		for (int i = 1; i <= V; i++) {
			cont[i] = 0;
		}

		for (auto v : virus) {
			cont[v] = -1;
			q.clear();
			q.push_back({ v, 0 });
			for (int i = 1; i <= V; i++) {
				chk[i] = false;
			}

			while (!q.empty()) {
				pair<int, int> tp = q.front();
				bfs(tp);
			}
		}

		int node = -1;
		int time = -1;
		for (int i = V; i > 0; i--) {
			if (cont[i] >= time) {
				time = cont[i];
				node = i;
			}
		}


		printf("#%d %d %d\n", ca, node, time);
	}
	return 0;
}

========================================

3 
5 6 1 
1 
1 3 
4 3 
3 5 
5 2 
1 4 
3 2 
5 6 1 
3 
1 3 
4 3 
3 5 
5 2 
1 4 
3 2 
7 8 2 
7 5 
6 3 
4 1 
3 7 
4 6 
3 1 
4 5 
5 1 
2 6
15 17 2
13 6 
10 8
10 14
2 1
7 13
14 1
8 12
5 11
15 12
7 15
9 2
5 2
1 4
10 1
6 3
7 3
7 1
3 13
23 23 4
14 9 2 13 
4 21
1 5
14 3
12 15
22 15
18 13
4 22
20 23
2 14
12 20
2 11
12 21
3 8
10 16
2 10
20 1
15 7
1 13
19 1
9 14
6 12
17 6
14 12
