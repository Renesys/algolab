#include<iostream>
#include<fstream>
#include<cstdio>
#include<deque>
#include<string>
#include<algorithm>
using namespace std;

deque<int> dq;

int main() {
	ifstream f("input.txt");
	int CA;
	f >> CA;
	for (int ca = 1; ca <= CA; ca++) {
		int N, K;
		f >> N >> K;
		dq.clear();
		int res[2] = { 0, 0 };

		for (int i = 1; i <= N; i++) {
			dq.push_back(i);
		}

		int idx = 1;
		while (true) {
			res[idx % 2] += dq.front();
			dq.pop_front();
			idx++;
			if (dq.size() == 0) {
				break;
			}
			for (int i = 0; i < K-1; i++) {
				int t = dq.front();
				dq.pop_front();
				dq.push_back(t);
			}
		}

		printf("#%d %d\n", res[1], res[0]);
		
	}
	return 0;
}
