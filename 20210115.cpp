#include<iostream>
#include<fstream>
#include<cstdio>
#include<algorithm>
using namespace std;

int map[501][501];
int point[501][501];


int main() {
	ifstream f("input.txt");
	int CA;
	f >> CA;
	for (int ca = 1; ca <= CA; ca++) {
		int N, M;
		f >> N >> M;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				f >> map[i][j];
				point[i][j] = 0;
			}
		}
		
		int res = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (i == 1) {
					point[i][j] = point[i][j - 1] + map[i][j];
				}
				else if (j == 1) {
					point[i][j] = point[i-1][j] + map[i][j];
				}
				else {
					point[i][j] = min(point[i - 1][j], point[i][j - 1]) + map[i][j];
				}
				
			}
		}

		printf("#%d %d\n", ca, point[N][M]);
	}
	return 0;
}


==========================
3
3 5 
2 7 5 11 6
5 1 14 0 7
3 9 12 2 4
3 3
1 1 1
2 2 2
3 3 3
10 10
14 25 13 46 98 31 23 70 35 11
32 55 24 17 58 87 13 10 9 12
57 20 9 98 25 11 15 17 23 41
0 99 92 13 87 13 41 55 74 34
97 24 11 57 13 15 24 36 42 61
87 61 29 35 62 43 12 93 14 60
73 51 84 93 14 56 72 83 91 37
55 38 63 29 71 34 45 98 72 5
41 29 80 67 32 34 59 80 7 88
1 89 16 15 29 63 61 3 84 28
