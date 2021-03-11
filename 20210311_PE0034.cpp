#include<iostream>
#include<fstream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#define MAX 10000007
using namespace std;

vector<int> prime;
int is_prime[1000001];

void make_prime() {
	int idx = 2;
	for (int i = 1; i <= 1000000; i++) {
		is_prime[i] = true;
	}
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i <= 1000000; i++) {
		if (!is_prime[i]) continue;
		for (int j = i * 2; j <= 1000000; j += i) {
			is_prime[j] = false;
		}
	}

	for (int i = 2; i <= 1000000; i++) {
		if (is_prime[i]) {
			prime.push_back(i);
		}
	}

}

int getsize(char K[]){
	int len = 0;
	for (int i = 0; i <= 100; i++) {
		if (K[i] == NULL) {
			len = i;
			break;
		}
	}
	return len;
}

int main() {
	ifstream f("input.txt");
	int CA;
	f >> CA;
	make_prime();

	for (int ca = 1; ca <= CA; ca++) {
		char K[101];
		int L;
		f >> K;
		f >> L;

		bool chk = true;
		int num = 0;
		int size = getsize(K);
		for (auto p : prime) {
			if (L <= p) break;
			//cout << "prime : " << p << endl;

			int pivot = 0;
			for (int i = 0; i < size; i++) {
				int a = pivot * 10 + (K[i] - '0');
				pivot = a % p;
			}
			if (pivot == 0) {
				chk = false;
				num = p;
				break;
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

