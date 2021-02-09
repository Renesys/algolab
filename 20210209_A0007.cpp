#include<iostream>
#include<fstream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define MX 1000001

int arrow[MX];

int main() {
	ifstream f("input.txt");
	int CA;
	f >> CA;
	for (int ca = 1; ca <= CA; ca++) {
		int N;
		f >> N;
		for (int i = 1; i <= N; i++) {
			arrow[i] = false;
		}
		int res = 0;
		for (int i = 1; i <= N; i++) {
			int num;
			f >> num;
			if (arrow[num] == 0) {
				arrow[num - 1]++;
				res++;
			}
			else {
				arrow[num]--;
				arrow[num - 1]++;
			}
		}
		printf("#%d %d\n", ca, res);
	}
	return 0;
}
