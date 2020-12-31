#include<iostream>
#include<fstream>
#include<cstdio>
using namespace std;

int graph[101];
int group[101];

int check(int N, int num) {
	if (group[N] != 0)
		return 0;
	group[N] = num;
	return 1 + check(graph[N], num);
}

int main() {
	ifstream f("input.txt");
	int CA;
	f >> CA;
	for (int ca = 1; ca <= CA; ca++) {
		int res = 0;
		int N;
		f >> N;
		for (int i = 1; i <= N; i++) {
			f >> graph[i];
			group[i] = 0;
		}

		//logic
		int group_no = 1;
		for (int i = 1; i <= N; i++) {
			int t = check(i, group_no);
			if (t > 0) {
				group_no++;
			}
		}
		printf("#%d %d\n", ca, group_no-1);
	}
	return 0;
}
