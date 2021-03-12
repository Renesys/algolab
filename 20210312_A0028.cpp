#include<iostream>
#include<fstream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;

int N;
bool chk[19];
long long fac[19];

int charrank(char c) {
	int val = 0;
	for (int i = 1; i <= N; i++) {
		if ('a' + i - 1 == c) {
			chk[i] = true;
			return val;
		}
		if (!chk[i]) {
			val++;
		}
	}
}

long long seq(string a) {
	long long val = 0;
	int f = N - 1;
	for (int i = 0; i < a.size() - 1; i++, f--) {
		val += fac[f] * charrank(a[i]);
	}
	return val + 1;
}

void make_fac(int N) {
	for (int i = 1; i <= N; i++) {
		fac[i] = fac[i - 1] * i;
	}
}

int main() {
	ifstream f("input.txt");
	int CA;
	f >> CA;
	fac[0] = 1;
	make_fac(18);


	for (int i = 1; i <= 18; i++) {
		cout << fac[i] << endl;
	}

	for (int ca = 1; ca <= CA; ca++) {
		string a, b;
		f >> N >> a >> b;
		for (int i = 1; i <= N; i++) {
			chk[i] = false;
		}
		long long resA = seq(a);
		for (int i = 1; i <= N; i++) {
			chk[i] = false;
		}
		long long resB = seq(b);

		printf("#%d %lld\n", ca, abs(resB - resA) - 1);
	}
	return 0;
}
