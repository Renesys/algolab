#include<iostream>
#include<fstream>
#include<cstdio>
#include<vector>
#include<algorithm>
#define MAX 1000000000
using namespace std;

int C[1001];
int W[1001];
int D[1001][10001];

int main() {
	ifstream f("input.txt");
	int CA;
	f >> CA;

	for (int ca = 1; ca <= CA; ca++) {
		int N, M;
		f >> N >> M;

		//init;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				D[i][j] = 0;
			}
		}

		for (int i = 1; i <= N; i++) {
			int c, w;
			f >> C[i] >> W[i];
		}

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (W[i] > j) {
					D[i][j] = D[i - 1][j];
				}
				else {
					D[i][j] = max(D[i - 1][j], D[i - 1][j - W[i]] + C[i]);
				}
			}

			for (int j = 0; j <= M; j++) {
				cout << D[i][j] << ' ';
			}
			cout << endl;
		}

		printf("#%d %d\n", ca, D[N][M]);
	}
	return 0;
}
