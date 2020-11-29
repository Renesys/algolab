#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

vector< pair<int, float> > map[201];

int main() {
	int CA;
	ifstream f("input.txt");
	f >> CA;

	for (int ca = 1; ca <= CA; ca++) {
		int V, E, T;
		f >> V >> E >> T;
		//initialize
		for (int i = 1; i <= V; i++) {
			map[i].clear();
		}

		for (int i = 0; i < E; i++) {
			int a, b;
			float p;
			f >> a >> b >> p;
			map[a].push_back(make_pair(b, p));

		}

		vector<float> now;
		vector<float> pre;

		//initialize
		pre.push_back(0);
		pre.push_back(1);
		now.push_back(0);
		now.push_back(0);
		for (int i = 2; i <= V; i++) {
			pre.push_back(0);
			now.push_back(0);
		}

		float res = 0;
		int res_state = 0;

		for (int t = 1; t <= T / 10 + 1; t++) {
			for (int i = 1; i <= V; i++) {
				for (vector<pair<int, float> >::iterator it = map[i].begin(); it != map[i].end(); ++it) {
					now[it->first] += pre[i] * it->second;
				}		
			}
			res = 0;
			for (int j = 1; j <= V; j++) {
				//cout << pre[j] << ' ';
				if (res < pre[j]) {
					res = max(res, pre[j]);
					res_state = j;
				}
			}
			//cout << endl;
			pre = now;
			for (int i = 1; i <= V; i++) {
				now[i] = 0;
			}

			
		}	

		if (res < 0.0000001) {
			printf("#%d 0\n", ca);

		}
		else {
			printf("#%d %d %.6f\n", ca, res_state, res);
		}
	}

	
	

	

}
