#include<iostream>
#include<fstream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> seoksun;
vector<int> jongyu;

int A[500001];
int B[500001];

int main() {
	ifstream f("input.txt");
	int CA;
	f >> CA;
	for (int ca = 1; ca <= CA; ca++) {
		int N, H;
		f >> N >> H;
		seoksun.clear();
		jongyu.clear();
		A[0] = 0;
		for (int i = 1; i <= H; i++) {
			A[i] = 0;
			B[i] = 0;
		}
		for (int i = 0; i < N/2; i++) {
			int s, j;
			f >> s >> j;
			B[1]++;
			B[s + 1]--;
			seoksun.push_back(s);
			B[H - j + 1]++;
			jongyu.push_back(j);
		}
		
		for (int i = 1; i <= H; i++) {
			A[i] = A[i - 1] + B[i];
		}

		long long res = 1000000000;
		int cnt = 0;
		for (int i = 1; i <= H; i++) {
			if (A[i] < res) {
				res = A[i];
				cnt = 1;
			}
			else if(A[i] == res){
				cnt++;
			}
		}
		printf("#%d %lld %d\n", ca, res, cnt);

	}
	return 0;
}


=================================
2
6 6
3
3
3
3
3
3
14 5
1
3
4
2
2
4
3
4
3
3
3
2
3
3
