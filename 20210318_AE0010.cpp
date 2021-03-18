#include<iostream>
#include<fstream>
#include<cstdio>
#include<algorithm>
#define MAX 1000000000
using namespace std;

int map[1001][1001];
int D[1001][1001];

int main() {
	ifstream f("input.txt");
	int CA;
	f >> CA;

	for (int ca = 1; ca <= CA; ca++) {
		int N, M;
		f >> N >> M;

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				int n;
				f >> n;
				map[i][j] = n;
				D[i][j] = 0;
			}
		}

		int res = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (map[i][j] == 0) {
					D[i][j] = min(D[i][j-1], min(D[i - 1][j - 1], D[i - 1][j])) + 1;
					res = max(res, D[i][j]);
				}
			}
		}

		printf("#%d %d\n", ca, res);

	}
	return 0;
}
