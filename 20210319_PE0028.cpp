#include<iostream>
#include<fstream>
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
#define MAX 1000000000
using namespace std;


int D[1001][1001];

int main() {
	ifstream f("input.txt");
	int CA;
	f >> CA;

	for (int ca = 1; ca <= CA; ca++) {
		string A = "0", B = "0";
		string as, bs;
		f >> as >> bs;
		A += as;
		B += bs;

		for (int i = 0; i <= A.size(); i++) {
			for (int j = 0; j <= B.size(); j++) {
				D[i][j] = 0;
			}
		}

		for (int i = 1; i < B.size(); i++) {
			for (int j = 1; j < A.size(); j++) {
				if (A[j] == B[i]) {
					D[i][j] = D[i - 1][j - 1] + 1;
				}
				else {
					D[i][j] = max(D[i - 1][j], D[i][j - 1]);
				}
			}
		}

		//search
		vector<char> res;
		int a = A.size() - 1;
		for (int b = B.size() - 1; b > 0; b--) {
			if (D[b][a] != D[b-1][a]) {
				res.push_back(B[b]);
				a--;
			}
		}

		printf("#%d ", ca);
		while (!res.empty()) {
			printf("%c", res.back());
			res.pop_back();
		}
		printf("\n");
	}
	return 0;
}
