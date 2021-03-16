#include<iostream>
#include<fstream>
#include<cstdio>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;

struct Edge {
	int dest;
	int cost;
};

struct Node {
	int in;
	int low;
};

Node node[100001];
vector<Edge> G[100001];


bool cmp(const Edge &a, const Edge &b) {
	return a.cost < b.cost;
}

void pathfind(int N) {
	deque<int> dq;
	dq.push_back(1);

	int S = 0;
	while (!dq.empty()) {
		S = dq.front();
		dq.pop_front();
		node[S].in = -1;
		for (auto e : G[S]) {
			node[e.dest].in--;
			if (node[e.dest].in == 0) {
				dq.push_back(e.dest);
			}
			int t = node[S].low + e.cost;
			if (node[e.dest].low < t) {
				node[e.dest].low = t;
			}
		}

		/*
		for (int i = 1; i <= N; i++) {
			cout << node[i].low << ' ';
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
		int V, E;
		f >> V >> E;
		
		for (int i = 0; i <= V; i++) {
			G[i].clear();
			node[i] = { 0, 0 };
		}

		for (int i = 1; i <= E; i++) {
			int s, d, c;
			f >> s >> d >> c;
			G[s].push_back({ d, c });
			node[d].in++;
		}

		pathfind(V);


		printf("#%d %d\n", ca, node[V].low);
	}
	return 0;
}

========================
2
7 9
1 2 4
1 3 2
1 4 3
2 6 3
2 7 5
3 5 1
4 6 4
5 6 2
6 7 5
7 10
6 4 5
1 6 7
4 5 5
5 7 5
5 7 3
1 4 7
1 3 2
6 4 5
5 7 6
1 2 2
