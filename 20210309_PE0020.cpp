#include<iostream>
#include<fstream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int runner[100001];
int arr[100001];

int main() {
	ifstream f("input.txt");
	int CA;
	f >> CA;
	for (int ca = 1; ca <= CA; ca++) {
		int N;
		f >> N;

		for (int i = 1; i <= N; i++) {
			f >> runner[i];
		}

		int res = 0;
		for (int i = N-1; i >= 1; i--) {
			for (int j = i + 1; j <= N; j++) {
				if (runner[j] > runner[i]) {
					res++;
				}
			}
		}
		printf("#%d %d\n", ca, res);

	}
	return 0;
}
