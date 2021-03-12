#include<iostream>
#include<fstream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#define MAX 1152921504606846976
using namespace std;
unsigned long long pas[1002][1002];

void make_pascal() {
	pas[0][0] = pas[1][0] = pas[1][1] = 1;

	for (int i = 2; i <= 1000; i++) {
		for (int j = 0; j <= i/2; j++) {
			if (j == 0) {
				pas[i][j] = pas [i][i] = 1;
			}
			else {
				if (MAX < pas[i - 1][j - 1] + pas[i - 1][j]) {
					break;
				}		
				pas[i][j] = pas[i][i - j] = pas[i - 1][j - 1] + pas[i - 1][j];
				
			}
		}
	}
}

void bit(int N, int K, unsigned long long seq) {
	if (N != 1) {
		if (seq <= pas[N - 1][K] || pas[N - 1][K] == 0) {
			printf("0");
			bit(N - 1, K, seq);
		}
		else {
			printf("1");
			bit(N - 1, K - 1, seq - pas[N - 1][K]);
		}
	}
	else {
		printf("%d", K == 1 ? 1 : 0);
	}
	return;
}


int main() {
	ifstream f("input.txt");
	int CA;
	f >> CA;
	make_pascal();
/*
	for (int i = 0; i <= 100; i++) {
		printf("%llu\n", pas[100][i]);
	}
	*/
	for (int ca = 1; ca <= CA; ca++) {
		int N, K;
		unsigned long long S;
		f >> N >> K;
		f >> S;

		printf("#%d ", ca);
		bit(N, K, S);
		cout << endl;
	}
	return 0;
}

=============================================

10
20 1 13
20 20 1
20 11 91593
20 6 26534
20 10 84809
20 5 3233
20 13 58356
300 158 1152921504606846976
500 206 1152921504606846976
1000 600 1152921504606846976
