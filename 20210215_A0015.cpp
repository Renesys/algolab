#include<iostream>
#include<fstream>
#include<cstdio>
#include<deque>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> g[101];
bool dfschk[101];
bool bfschk[101];
deque<int> q;

void bfs(int N) {
	int target = N;
	while (!q.empty()) {
		if (bfschk[target]) {
			target = q.front();
			q.pop_front();
			continue;
		}
		cout << target << ' ';
		bfschk[target] = true;
		q.pop_front();
		for (auto e : g[target]) {
			if (!bfschk[e]) {
				q.push_back(e);
			}
		}
		if(!q.empty())
			target = q.front();
	}
}

void dfs(int N) {
	if (dfschk[N])
		return;
	dfschk[N] = true;
	cout << N << ' ';

	for (auto e : g[N]) {
		dfs(e);
	}

}

int main() {
	ifstream f("input.txt");
	int CA;
	f >> CA;
	for (int ca = 1; ca <= CA; ca++) {
		int V, E, S;
		f >> V >> E >> S;
		q.clear();
		for (int i = 1; i <= V; i++) {
			g[i].clear();
			dfschk[i] = false;
			bfschk[i] = false;
		}
		for (int i = 0; i < E; i++) {
			int a, b;
			f >> a >> b;
			g[a].push_back(b);
			g[b].push_back(a);
		}

		for (int i = 1; i <= V; i++) {
			sort(g[i].begin(), g[i].end());
		}

		printf("#%d ", ca);
		q.push_back(S);
		dfs(S);
		cout << endl;

		bfs(S);
		cout << endl;
		
	}
	return 0;
}
