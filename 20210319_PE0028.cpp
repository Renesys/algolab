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

		for (int i = 1; i < A.size(); i++) {
			for (int j = 1; j < B.size(); j++) {
				if (A[i] == B[j]) {
					D[i][j] = D[i - 1][j - 1] + 1;
				}
				else {
					D[i][j] = max(D[i - 1][j], D[i][j - 1]);
				}
			}

			for (int j = 1; j < A.size(); j++) {
				cout << D[i][j] << ' ';
			}
			cout << endl;
		}

		//search
		vector<char> res;
		int a = A.size() - 1;
		int b = B.size() - 1;
		while (D[a][b] != 0) {
			if (D[a][b] == D[a][b - 1]) {
				b--;
			}
			else if (D[a][b] == D[a - 1][b]) {
				a--;
			}
			else if (D[a][b] - 1 == D[a - 1][b - 1]) {
				res.push_back(A[a]);
				a--;
				b--;
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
