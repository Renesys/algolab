#include<iostream>
#include<fstream>
#include<cstdio>
#include<algorithm>
using namespace std;

int num[501];
int root[501];
int weight[501];

int find(int a) {
	if (root[a] != a){
		return root[a] = find(root[a]);
	}
	return a;
}

void uni(int a, int b) {
	int pa = find(a);
	int pb = find(b);

	if (pa != pb) {
		root[pa] = pb;
		weight[pb] += weight[pa];
	}
}

int main() {
	ifstream f("input.txt");
	int CA;
	f >> CA;
	for (int ca = 1; ca <= CA; ca++) {
		int res = -1;
		//input
		int N;
		f >> N;
		for (int i = 1; i <= N; i++) {
			f >> num[i];
			root[i] = i;
			weight[i] = 1;
		}

		//logic
		for (int i = 2; i <= N; i++) {
			for (int j = i-1 ; j > 0; j--) {
				if (num[i] % num[j] == 0 || num[j] % num[i] == 0) {
					uni(i, j);
				}
			}

			for (int j = 1; j <= N; j++) {
				if (res < weight[j]) {
					res = weight[j];
				}
			}
		}
		
		printf("#%d %d\n", ca, res);
	}
	return 0;
}
