#include<iostream>
#include<fstream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#define MAX 10000007
using namespace std;

bool is_prime[1000001];
int chk[1000001];
int res;

void make_prime() {
	fill_n(is_prime, 1000000, true);
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i <= 100000; i++) {
		if (!is_prime[i]) continue;
		for (int j = i * 2; j <= 100000; j += i) {
			is_prime[j] = false;
		}
	}
}

int main() {
	ifstream f("input.txt");
	int CA;
	f >> CA;
	make_prime();

	for (int ca = 1; ca <= CA; ca++) {
		string K;
		int L;
		f >> K;
		f >> L;

		bool chk = true;
		int num = 0;
		for (int p = 2; p < L; p++) {
			if (!is_prime[p]) {
				continue;
			}
			if (!chk) break;
			if (L <= p) break;
			//cout << "prime : " << p << endl;
			
			int pivot = 0;
			for (int i = 0; i < K.size(); i++) {
				long long a = pivot * 10 + (K[i] - '0');
				pivot = a % p;
			}
			if (pivot == 0) {
				chk = false;
				num = p;
			}
		}

		if (chk) {
			printf("#%d GOOD\n", ca);
		}
		else {
			printf("#%d BAD %d\n", ca, num);
		}

	}
	return 0;
}

