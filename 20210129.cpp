#include<iostream>
#include<fstream>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
#define MAX 100000000

bool isCandidate[21];
int voted[21];

struct Man {
	int num;
	int seq;
};

struct cmp {
	bool operator() (pair<int, int>& a, pair<int, int>& b) {
		if (voted[a.first] == voted[b.first]) 
			return a.second > b.second;
		else
			return voted[a.first] > voted[a.first];
	}
};


priority_queue<pair<int, int>, vector< pair<int, int> >, cmp > pq;

int main() {
	ifstream f("input.txt");
	int CA;
	f >> CA;
	for (int ca = 1; ca <= CA; ca++) {
		int C, V;
		f >> C >> V;
		for (int i = 1; i <= 20; i++) {
			isCandidate[i] = false;
			voted[i] = 0;
		}

		for (int i = 0; i < V; i++) {
			int n;
			f >> n;
			if (isCandidate[n]) {
				voted[n]++;
			}
			else {
				if (pq.size() == C) {
					pair<int, int> t = pq.top();
					pq.pop();
					isCandidate[t.first] = false;
					voted[t.first] = 0;
				}
				pq.push({ n, i });
				isCandidate[n] = true;
				voted[n]++;
			}
			int a = 1;
		}

		vector<int> elect;
		while (pq.size() > 0) {
			pair<int, int> t = pq.top();
			pq.pop();
			elect.push_back(t.first);
		}

		sort(elect.begin(), elect.end());
		printf("#%d ", ca);
		for (int i = 0; i < elect.size(); i++) {
			cout << elect[i] << ' ';
		}
		cout << endl;

	}
	return 0;
}
