#include<iostream>
#include<fstream>
#include<cstdio>
#include<algorithm>
#define MAX 1000000007
using namespace std;

long long pas[5001][5001];

void make_pascal() {
	pas[1][0] = pas[1][1] = 1;

	for (int i = 2; i <= 5000; i++) {
		for (int j = 0; j <= i/2; j++) {
			if (j == 0) {
				pas[i][j] = pas[i][i] = 1;
			}
			else {
				pas[i][j] = pas[i][i-j] = (pas[i - 1][j - 1] + pas[i - 1][j]) % MAX;
			}
		}
	}
}

int main() {
	ifstream f("input.txt");
	int CA;
	f >> CA;
	make_pascal();

	for (int ca = 1; ca <= CA; ca++) {
		int a, b;
		f >> a >> b;

		printf("#%d %lld\n", ca, pas[a][b]);
	}
	return 0;
}
