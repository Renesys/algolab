#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;


int graph[1001];
bool villan[1001];
bool player[1001];


int selection(int n, int v, int K) {
	if (player[n]) {
		return 0;
	}
	else if (villan[n]) {
		if (v + 1 > K) {
			return 0;
		}
		else {
			player[n] = true;
			return 1 + selection(graph[n], v + 1, K);
		}	
	}
	else{
		player[n] = true;
		return 1 + selection(graph[n], v, K);
	}


}

int main() {
	int CA;
	ifstream f("input.txt");
	f >> CA;

	for (int ca = 1; ca <= CA; ca++) {
		int N, M, K;
		f >> N >> M >> K;

		for (int i = 1; i <= N; i++) {
			f >> graph[i];
			villan[i] = false;
		}
		for (int i = 1; i <= M; i++) {
			int t;
			f >> t;
			villan[t] = true;
		}

		//logic
		int res = -100;
		for (int i = 1; i <= N; i++) {
			for (int j = 0; j <= N; j++) {
				player[j] = false;
			}
			int t = selection(i, 0, K);
			printf("%d = %d\n", i, t);
			if (t > res) {
				res = t;
			}
		}
		printf("#%d %d\n", ca, res);

	}
}
