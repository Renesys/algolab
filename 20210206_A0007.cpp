#include<iostream>
#include<fstream>
#include<cstdio>
#include<algorithm>
using namespace std;

int cost[3001];
int dp[3001];

int main() {
	ifstream f("input.txt");
	int CA;
	f >> CA;

	for (int ca = 1; ca <= CA; ca++) {
		int N;
		f >> N;
		cost[0] = 0;
		for (int i = 1; i <= N; i++) {
			f >> cost[i];
			dp[i] = 0;
		}


		dp[0] = 0;
		dp[1] = cost[1];
		for (int i = 2; i <= N; i++) {
			int max = cost[i];
			for (int j = i; j >= i/2; j--) {
				if (max < dp[j] + dp[i - j]) {
					max = dp[j] + dp[i - j];
				}
			}
			dp[i] = max;
			for (int k = 1; k <= N; k++) {
				cout << dp[k] << ' ';
			}
			cout << endl;
		}

		printf("#%d %d\n", ca, dp[N]);
	}
	return 0;
}
