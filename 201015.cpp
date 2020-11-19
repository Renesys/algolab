#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class Type {
	char c;
	vector<int> v;
};

int main() {
	ifstream f("input.txt");
	int CA;
	f >> CA;
	for (int ca = 1; ca <= CA; ca++) {
		int M, N, K;
		string workers;
		vector<int> v[5];
		bool used[5];
		string work;

		//initialize
		f >> M >> N >> K;
		f >> workers;
		for (int k = 0; k < K; k++) {
			v[k].clear();
			v[k].assign(N, 0);
			used[k] = false;
		}
		for (int i = 0; i < M; i++) {
			f >> work;
			for (int j = 0; j < N; j++) {
				for (int k = 0; k < K; k++) {
					if (work[j] == workers[k]) {
						v[k][j]++;
					}
				}
			}
		}

		//map print
		for (int k = 0; k < K; k++) {
			for (int j = 0; j < N; j++) {
				cout << v[k][j] << ' ';
			}
			cout << endl;
		}
		cout << endl;

		//algorithm
		for (int j = 0; j < N; j++) {
			int maxcol = -1;
			int maxval = -100;
			for (int k = 0; k < K; k++) {
				if()
			}
		}

	}
	return 0;
}
