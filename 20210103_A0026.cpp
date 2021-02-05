#include<iostream>
#include<fstream>
#include<cstdio>
using namespace std;

int graph[101];
int type[1001];
int group[1001];
int cnt[1001];



int find(int N) {
	if(group[N] == N)
		return N;
	else {
		return group[N] = find(group[N]);
	}
}

void uni(int a, int b) {
	int pa = find(a);
	int pb = find(b);

	group[pa] = pb;
}

int main() {
	ifstream f("input.txt");
	int CA;
	cin >> CA;
	for (int ca = 1; ca <= CA; ca++) {
		int V, E;
		cin >> V >> E;
		for (int i = 1; i <= V; i++) {
			cin >> type[i];
			group[i] = i;
			cnt[i] = 0;
		}
		for (int i = 0; i < E; i++) {
			int a, b;
			cin >> a >> b;
			if ((type[a] == 0 && type[b] == 1) || (type[a] == 1 && type[b] == 0)) {
				continue;
			}
			uni(a, b);
		}

		for (int i = 1; i <= V; i++) {
			cnt[find(i)]++;
		}

		int res = -1;
		for (int i = 1; i <= V; i++) {
			if (res < cnt[i])
				res = cnt[i];
		}
		
		printf("#%d %d\n", ca, res);
	}
	return 0;
}
