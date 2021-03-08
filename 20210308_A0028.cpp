#include<iostream>
#include<fstream>
#include<cstdio>
#include<deque>
#include<vector>
#include<algorithm>
using namespace std;

int map[129][129];
int square[129][129];
int sq_cnt[2];

bool is_square(int x, int y, int size) {
	int base = map[x][y];
	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			if (map[i][j] != base) {
				return false;
			}
		}
	}
	return true;
}

void detect_square(int x, int y, int size) {
	int cnt = 0;
	if (size == 1) {
		sq_cnt[map[x][y]]++;
		return;
	}

	if (is_square(x, y, size)) {
		sq_cnt[map[x][y]]++;
	}
	else {
		size /= 2;
		detect_square(x, y, size);
		detect_square(x+size, y, size);
		detect_square(x, y+size, size);
		detect_square(x+size, y+size, size);
	}
}

int main() {
	ifstream f("input.txt");
	int CA;
	f >> CA;
	for (int ca = 1; ca <= CA; ca++) {
		int N;
		sq_cnt[0] = sq_cnt[1] = 0;
		f >> N;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				f >> map[i][j];
				square[i][j] = map[i][j];
			}
		}

		detect_square(1, 1, N);

		printf("#%d %d %d\n", ca, sq_cnt[0], sq_cnt[1]);

	}
	return 0;
}



======================
2
4
1 1 0 1
1 1 0 0
1 1 1 0
1 1 0 1
8
1 1 0 0 0 0 1 1
1 1 0 0 0 0 1 1
0 0 0 0 1 1 0 0
0 0 0 0 1 1 0 0
1 0 0 0 1 1 1 1
0 1 0 0 1 1 1 1
0 0 1 1 1 1 1 1
0 0 1 1 1 1 1 1
