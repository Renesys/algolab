#include<iostream>
#include<fstream>
#include<cstdio>
using namespace std;

int graph[101];
int group[101];
bool checked[101];

int check(int N, int num) {
	if (group[N] != 0)
		return 0;
	group[N] = num;
	return 1 + check(graph[N], num);
}

int find(int N) {
	if(group[N] == N)
		return N;
	else {
		return group[N] = find(group[N]);
	}
}

void uni(int a, int b) {
	int pa = group[a];
	int pb = group[b];
	group[pa] = find(pb);

}

int main() {
	ifstream f("input.txt");
	int CA;
	cin >> CA;
	for (int ca = 1; ca <= CA; ca++) {
		int N;
		cin >> N;
		for (int i = 1; i <= N; i++) {
			cin >> graph[i];
			group[i] = i;
			checked[i] = false;
		}

		//logic
		for (int i = 1; i <= N; i++) {
			uni(i, graph[i]);
		}
		int res = 0;
		for (int i = 1; i <= N; i++) {
			if (!checked[find(group[i])]) {
				res++;
				checked[find(group[i])] = true;
			}
		}
		printf("#%d %d\n", ca, res);
	}
	return 0;
}
