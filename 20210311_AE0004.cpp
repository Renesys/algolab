#include<iostream>
#include<fstream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#define MAX 10000007
using namespace std;

int gcd(int a, int b) {
	if (b > a) {
		swap(a, b);
	}
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int lcm(int a, int b) {
	int g = gcd(a, b);
	return a * b / g;
}

int main() {
	ifstream f("input.txt");
	int CA;
	f >> CA;
	for (int ca = 1; ca <= CA; ca++) {
		int N, M;
		f >> N >> M;
		int l = lcm(N, M);
		int offset = l / M;
		int gold_offset = l / N;
		int res = 0;
		for (int i = 0; i < l; i += offset) {
			if (i % gold_offset != 0) {
				res++;
			}
		}
		printf("#%d %d\n", ca, res);
	}
	return 0;
}
