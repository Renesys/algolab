// lab01.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <deque>
#include <algorithm>
#define MAX 1000000002
using namespace std;

int m[1001][1001];

struct Edge {
	int a;
	int b;
	int v;
	int diff;
};
deque<Edge> edges;
int group[1001];
int treerank[1001];

int find_root(int a) {
	return group[a] == a ? a : group[a] = find_root(group[a]);
}


//need to fix
void uni(int a, int b) {
	int pa = find_root(group[a]);
	int pb = find_root(group[b]);
	if (pa != pb) {
		int ra = treerank[pa];
		int rb = treerank[pb];
		if (ra <= rb) {
			group[pa] = pb;
			if (ra == rb) {
				treerank[pa]++;
			}
		}
		else if (ra > rb) {
			group[pb] = pa;
		}
	}
}

bool cmp(Edge a, Edge b) {
	//return abs(a.diff) < abs(b.diff);
	return a.v < b.v;
}

int main()
{
	ifstream f("in.txt");
	int CA;
	f >> CA;
	//scanf("%d", &CA);
	for (int ca = 1; ca <= CA; ca++) {
		edges.clear();
		int N, E;
		f >> N >> E;
		//scanf("%d %d", &N, &E);

		for (int i = 0; i < E; i++) {
			int a, b, v;
			f >> a >> b >> v;
			//scanf("%d %d %d", &a, &b, &v);
			if (a > b) swap(a, b);
			edges.push_back({ a, b, v, 0 });
		}
		int start, end;
		f >> start >> end;
		//scanf("%d %d", &start, &end);

		sort(edges.begin(), edges.end(), cmp);

		int res = MAX;
		while (!edges.empty()) {
			//kruskal
			int M = -1;
			int m = MAX;
			for (int i = 1; i <= N; i++) {
				group[i] = i;
				treerank[i] = 1;
			}
			for (auto e : edges) {
				if (group[start] == group[end]) break;
				if (find_root(e.a) != find_root(e.b)) {
					cout << e.a << ' ' << e.b << ' ' << e.v << endl;
					if (e.v > M) {
						M = e.v;
					}
					if (e.v < m) {
						m = e.v;
					}
					uni(e.a, e.b);

					for (int i = 1; i <= N; i++) {
						cout << group[i] << ' ';
					}
					cout << endl;
				}
			}
			if (find_root(start) != find_root(end)) {
				break;
			}
			edges.pop_front();
			if (M - m < res) {
				res = M - m;
			}
		}
		cout << res << endl;

	}
}
