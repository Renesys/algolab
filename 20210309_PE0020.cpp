#include<iostream>
#include<fstream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

struct Runner {
	int idx;
	int abilty;
};

vector<Runner> r;
int res = 0;

void checkidx(int ti, int idx) {
	if (ti < idx) {
		res += (idx - ti);
	}
}

vector<Runner> merge(vector<Runner> r1, vector<Runner> r2) {
	vector<Runner> temp;
	int idx1 = 0, idx2 = 0;
	int tidx = 0;
	while (true) {
		if (idx1 == r1.size() || idx2 == r2.size())
			break;
		if (r1[idx1].abilty > r2[idx2].abilty) {
			temp.push_back({ tidx, r1[idx1].abilty });
			checkidx(tidx, r1[idx1].idx);
			tidx++;
			idx1++;
		}
		else if (r1[idx1].abilty < r2[idx2].abilty) {
			temp.push_back({ tidx, r2[idx2].abilty });
			checkidx(tidx, r2[idx2].idx);
			tidx++;
			idx2++;
		}
		else {
			temp.push_back({ tidx, r1[idx1].abilty });
			temp.push_back({ tidx + 1, r2[idx2].abilty });
			checkidx(tidx, r1[idx1].idx);
			checkidx(tidx + 1, r2[idx2].idx);
			idx1++;
			idx2++;
			tidx += 2;
		}
	}
	while (idx2 != r2.size()) {
		temp.push_back({ tidx++, r2[idx2].abilty });
		checkidx(tidx, r2[idx2].idx);
		tidx++;
		idx2++;
	}
	while (idx1 != r1.size()) {
		checkidx(tidx, r1[idx1].idx);
		temp.push_back({ tidx, r1[idx1].abilty });
		tidx++;
		idx1++;
	}

	for (auto t : temp) {
		printf("(%d, %d) ", t.idx, t.abilty);
	}
	cout << endl;

	return temp;
}

vector<Runner> mergesort(vector<Runner> r) {
	if (r.size() == 1) {
		return r;
	}

	int iter = r.size() / 2;
	vector<Runner> front;
	front.assign(r.begin(), r.begin() + iter);
	vector<Runner> back;
	back.assign(r.begin() + iter, r.end());


	front = mergesort(front);
	back = mergesort(back);
	return merge(front, back);
}

int main() {
	ifstream f("input.txt");
	int CA;
	f >> CA;
	for (int ca = 1; ca <= CA; ca++) {
		int N;
		f >> N;
		res = 0;
		r.clear();
		for (int i = 0; i < N; i++) {
			int a;
			f >> a;
			r.push_back({ i, a });
		}

		r = mergesort(r);

		printf("#%d %d\n", ca, res);

	}
	return 0;
}


