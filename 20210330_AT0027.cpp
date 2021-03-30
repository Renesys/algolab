#include<iostream>
#include<fstream>
#include<cstdio>
#include<algorithm>
#define MAX 1000000000
using namespace std;

long long D[101][101][2];


int main() {
	ifstream f("input.txt");
	int CA;
	f >> CA;

	D[1][0][0] = D[1][0][1] = 1;
	for (int i = 2; i <= 100; i++) {
		for (int j = 0; j < i; j++) {
			D[i][j][0] = D[i - 1][j][0] + D[i - 1][j][1];
			D[i][j][1] = D[i - 1][j][0] + D[i - 1][j - 1][1];
		}
	}

	for (int ca = 1; ca <= CA; ca++) {
		int N, K;
		f >> N >> K;

		printf("#%d %lld\n", ca, D[N][K][0] + D[N][K][1]);
		
	}
	return 0;
}
