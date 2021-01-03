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
	f >> CA;
	for (int ca = 1; ca <= CA; ca++) {
		int V, E;
		f >> V >> E;
		for (int i = 1; i <= V; i++) {
			f >> type[i];
			group[i] = i;
			cnt[i] = 0;
		}
		for (int i = 0; i < E; i++) {
			int a, b;
			f >> a >> b;
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
======================================
3 
4 5 
2 1 0 0 
1 4 
4 3 
3 2 
1 2 
2 4 
10 15 
1 1 0 1 0 1 1 1 2 0 
8 5 
8 9 
9 4 
10 5 
4 2 
10 7 
6 7 
8 3 
1 4 
10 2 
2 5 
8 1 
4 7 
3 4 
3 5 
13 15 
2 1 0 0 0 1 2 1 2 0 1 0 1 
11 13 
8 11 
8 2 
5 8 
13 3 
1 13 
5 6 
11 10 
7 8 
5 12 
4 7 
9 4 
4 5 
6 11 
6 10
  ======================================================
 
