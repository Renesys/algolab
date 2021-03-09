#include<iostream>
#include<fstream>
#include<cstdio>
#include<deque>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> up;
vector<int> down;

int main() {
	ifstream f("input.txt");
	int CA;
	f >> CA;
	for (int ca = 1; ca <= CA; ca++) {
		int N, H;
		f >> N >> H;
		up.clear();
		down.clear();
		for (int i = 0; i < N/2; i++) {
			int u, d;
			f >> u >> d;
			up.push_back(u);
			down.push_back(d);
		}

		sort(up.begin(), up.end());
		sort(down.begin(), down.end());

		//search from up
		int upres = 0;
		int downcheck = H - up.back();
		for (int i = 0; i < down.size(); i++) {
			if (down[i] >= downcheck) {
				upres = down.size() - i;
				break;
			}
		}

		//search from down
		int downres = 0;
		int upcheck = H - down.back();
		for (int i = 0; i < up.size(); i++) {
			if (up[i] >= upcheck) {
				downres = up.size() - (i-1);
				break;
			}
		}

		int res = upres > downres ? downres : upres;
		printf("#%d %d\n", ca, res);

	}
	return 0;
}

=================================
2
6 6
3
3
3
3
3
3
14 5
1
3
4
2
2
4
3
4
3
3
3
2
3
3
