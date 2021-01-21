#include<iostream>
#include<fstream>
#include<cstdio>
#include<deque>
#include<algorithm>
using namespace std;

deque<int> dq[6001];

bool cmp(const int a, const int b) {
	return a > b;
}

int main() {
	ifstream f("input.txt");
	int CA;
	f >> CA;
	for (int ca = 1; ca <= CA; ca++) {
		long long res = 0;

		//input
		int N;
		f >> N;
		for (int i = 0; i < N; i++) {
			dq[i].clear();
			int M, data;
			f >> M;
			for (int j = 0; j < M; j++) {
				f >> data;
				dq[i].push_back(data);
			}
			sort(dq[i].begin(), dq[i].end(), cmp);
		}

		//logic
		for (int i = N - 1; i >= 0; i--) {
			int max = -1;
			int idx = -1;
			for (int j = i; j < N; j++) {
				if (dq[j].size() > 0 && dq[j][0] > max) {
					max = dq[j][0];
					idx = j;
				}
			}
			res += max;
			dq[idx].pop_front();
		}
		

		printf("#%d %d\n", ca, res);
	}
	return 0;
}

==============================================
4
5
1
3000
4
8000 4000 5000 1000
2
2000 6000
1
2500
2
7000 5500
5
4
1049 8409 8444 6054
3
5983 2726 3627
2
8591 4074
3
4610 7157 3958
2
8562 1304
5
2
7490 5898
3
4970 9393 1788
1
3155
3
5837 7236 5894
3
6293 6630 3662
10
4
8284 2317 7755 3301
3
1040 8514 2311
2
2786 3048
2
2967 9401
3
9123 9614 5931
4
1536 8973 4761 4840
3
5688 2072 7870
1
8669
3
9216 5805 9908
3
8187 5501 9890
