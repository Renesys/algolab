#include<iostream>
#include<fstream>
#include<cstdio>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;

vector<char> v;

int N;
bool chk[11];
int fac[11];

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

int seq(string a) {
	int val = 0;
	int f = N - 1;
	for (int i = 0; i < a.size() - 1 ; i++) {
		val += fac[f] * charrank(a[i]);
		f--;
	}
	return val + 1;
}


int main() {
	ifstream f("input.txt");
	int CA;
	f >> CA;
	fac[0] = 1;

	for (int ca = 1; ca <= CA; ca++) {
		string a, b;
		f >> N >> a >> b;
		for (int i = 1; i <= N; i++) {
			chk[i] = false;
			fac[i] = fac[i - 1] * i;
		}
		int resA = seq(a);
		for (int i = 1; i <= N; i++) {
			chk[i] = false;
		}
		int resB = seq(b);

		cout << resA << ' ' << resB << endl;

		printf("#%d %d\n", ca, abs(resB - resA) - 1);
	}
	return 0;
}


=============================
5
4 adbc bdca
5 ebdac eadcb
6 ecfabd dfcaeb
8 dgceabhf fhagbcde
10 cfhjdabegi cbhagfdije
