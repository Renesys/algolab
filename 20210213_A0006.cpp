#include<iostream>
#include<fstream>
#include<cstdio>
#include<algorithm>
#define MAX 1000000007
using namespace std;

int main() {
	ifstream f("input.txt");
	int CA;
	f >> CA;
	for (int ca = 1; ca <= CA; ca++) {
		int A, B;
		long long res = 1;
		f >> A >> B;
		long long mu = A;
		while (B != 0) {
			int t = B % 2;
			B /= 2;
			if(t != 0)
				res *= (t * mu);
			mu *= mu;
			if (res > MAX) {
				res %= MAX;
			}
		}


		printf("#%d %lld\n", ca, res);
	}
	return 0;
}
