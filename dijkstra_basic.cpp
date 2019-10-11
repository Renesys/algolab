// lab01.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX 100000000
using namespace std;

vector<pair<int, int>> G[100];


int main() {
	int CA;
	ifstream f("in.txt");
	f >> CA;
	for (int ca = 1; ca <= CA; ca++) {
		int V, E, S;
		f >> V >> E >> S;
		//init
		vector<int> dist(V, MAX);
		for (int i = 0; i < V; i++) {
			G[i].clear();
		}
		for (int i = 0; i < E; i++) {
			int s, e, c;
			f >> s >> e >> c;
			G[s].push_back(make_pair(e, c));
			G[e].push_back(make_pair(s, c));
		}

		//dijkstra
		int cur = S;
		int res = 0;
		dist[cur] = 0;
		priority_queue<pair<int, int>> pq;
		pq.push(make_pair(S, dist[cur]));
		while (!pq.empty()) {
			int cost = -pq.top().second;
			cur = pq.top().first;
			pq.pop();

			if (dist[cur] < cost) {
				continue;
			}

			for (int i = 0; i < G[cur].size(); i++) {
				int candi = G[cur][i].first;
				int nextcost = cost + G[cur][i].second;

				if (dist[candi] > nextcost) {
					res += G[cur][i].second;
					dist[candi] = nextcost;
					pq.push(make_pair(candi, -nextcost));
				}
			}
		}

		for (int i = 0; i < V; i++) {
			cout << dist[i] << ' ';
		}
		cout << endl;
		cout << res << endl;
	}

	return 0;
}
