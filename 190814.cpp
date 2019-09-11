// lab01.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int info[100001][4];
int gross[100001];
int tree[100001 * 4];


void update_tree() {

}

void add_item(int s, int e, int c, int a) {
	for (int i = s; i <= e; i++) {
		info[i][c] += a;
	}
}

void make_set(int s, int r) {
	int hat = info[s][1];
	int cloth = info[s][2];
	int pants = info[s][3];
	int less = min(min(hat, cloth),pants);
	info[s][1] -= less;
	info[s][2] -= less;
	info[s][3] -= less;
	gross[s] += less;
}

void calc_total(int s, int e) {

}

int init_tree(int n, int s, int e) {
	if (s == e) {
		tree[n] = gross[n];
	}
	int m = (s + e) / 2;
	return tree[n] = init_tree(n * 2, s, m) + init_tree(n * 2 + 1, m + 1, e);
}


int main()
{
	ifstream f("in.txt");
	int CA;
	f >> CA;

	for (int ca = 1; ca <= CA; ca++) {
		int N, Q;
		f >> N >> Q;
		//initialize
		for (int i = 0; i <= N; i++) {
			info[i][1] = info[i][2] = info[i][3] = 0;
		}
		for (int i = 0; i <= N*2+10; i++) {
			gross[i] = 0;
		}
		int t = log2(N);

		for (int q = 0; q < Q; q++) {
			int type;
			f >> type;
			int start, end, code, amount, shop, req;
			switch (type) {
			case 1:
				f >> start >> end >> code >> amount;
				add_item(start, end, code, amount);
				break;
			case 2:
				f >> shop >> req;
				make_set(shop, req);
				break;
			case 3:
				f >> start >> end;
				calc_total(start, end);
				break;
			}

			for (int i = 1; i <= N; i++) {
				cout << info[i][1] << ' ' << info[i][2] << ' ' << info[i][3] << ' ' << endl;
			}
			for (int i = 1; i <= N; i++) {
				cout << gross[i] << ' ';
			}
			cout << endl << endl;

		}

	}
}
