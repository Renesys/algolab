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
	f >> CA;
	for (int ca = 1; ca <= CA; ca++) {
		int N;
		f >> N;
		for (int i = 1; i <= N; i++) {
			f >> graph[i];
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


=============================================================
	
10
9
2 1 3 4 5 8 7 6 9 
12
12 7 10 2 4 3 9 6 1 8 5 11 
46
28 45 3 4 5 44 34 16 11 15 31 7 25 22 26 38 17 18 32 46 21 40 20 24 13 37 19 30 41 10 9 12 29 6 35 33 39 1 27 8 14 2 43 36 23 42 
26
6 22 18 8 22 3 17 14 1 10 21 12 13 11 25 20 1 2 10 12 16 5 5 3 9 16 
20
7 2 17 6 11 12 7 8 3 17 6 3 3 17 6 18 2 19 15 4 
38
18 22 29 19 27 38 35 8 7 21 11 12 13 25 5 16 1 30 2 6 9 3 20 34 14 17 26 28 31 10 15 32 36 33 24 23 37 4 
15
5 6 8 10 12 1 14 9 3 15 13 4 7 11 2 
58
1 33 3 4 5 6 2 8 9 10 11 12 13 29 15 16 17 18 19 28 21 22 23 24 25 26 20 32 14 30 31 7 27 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 
50
17 15 41 23 4 6 7 8 9 10 11 12 13 16 39 14 38 18 50 3 21 22 26 24 25 20 27 28 29 30 31 44 33 34 35 36 37 1 2 40 32 19 43 47 45 46 42 48 49 5 
54
1 49 3 4 5 6 7 25 9 10 35 12 13 2 15 16 17 18 19 47 21 22 23 24 14 26 27 28 29 30 31 32 33 34 11 36 37 38 8 40 41 42 43 44 45 46 20 48 39 50 51 52 53 54 
	
	
