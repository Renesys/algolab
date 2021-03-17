#include<iostream>
#include<fstream>
#include<cstdio>
#include<algorithm>
#define MAX 1000000000
using namespace std;

long long dist[301][301];

int main() {
	ifstream f("input.txt");
	int CA;
	f >> CA;

	for (int ca = 1; ca <= CA; ca++) {
		int V;
		f >> V;

		for (int i = 1; i <= V; i++) {
			for (int j = 1; j <= V; j++) {
				f >> dist[i][j];
			}
		}

		long long res = 0;

		for (int k = 1; k <= V; k++) {
			for (int i = 1; i <= V; i++) {
				for (int j = 1; j <= V; j++) {
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);	
				}
			}
		}

		for (int i = 1; i <= V; i++) {
			for (int j = 1; j <= V; j++) {
				if (dist[i][j] > res && dist[i][j] != MAX && dist[i][j] != 0) {
					res = dist[i][j];
				}
			}
		}

		printf("#%d %lld\n", ca, res);


	}
	return 0;
}

===============================

2
4
0 5 3 1
2 0 8 6
8 5 0 4
4 9 8 0
6
0 8 1 7 13 18
13 0 13 5 3 5
16 17 0 8 14 5
5 7 15 0 18 10
10 15 13 11 0 9
1 8 1 20 4 0
