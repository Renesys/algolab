#include<iostream>
#include<fstream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

struct Runner {
	int idx;
	int data;
};

vector<Runner> r;
int res = 0;

void checkidx(int next, int idx) {
	if (next < idx) {
		//cout << "========" << idx << ' ' << next << endl;
		res += (idx - next);
	}
}

vector<Runner> merge(vector<Runner> r1, vector<Runner> r2) {
	/*
	for (auto t : r1) {
	/printf("(%d, %d) ", t.idx, t.data);
	}
	cout << "|| ";
	for (auto t : r2) {
		printf("(%d, %d) ", t.idx, t.data);
	}
	cout << endl;
	*/
	vector<Runner> temp;
	int f = 0, b = 0;
	int nextidx = 0;
	while (true) {
		if (f == r1.size() || b == r2.size())
			break;
		if (r1[f].data > r2[b].data) {
			temp.push_back({ nextidx, r1[f].data });
			checkidx(nextidx, r1[f].idx);
			nextidx++;
			f++;
		}
		else if (r1[f].data < r2[b].data) {
			temp.push_back({ nextidx, r2[b].data });
			checkidx(nextidx, r1.size() + r2[b].idx);
			nextidx++;
			b++;
		}
		else {
			temp.push_back({ nextidx, r1[f].data });
			temp.push_back({ nextidx + 1, r2[b].data });
			checkidx(nextidx, r1[f].idx);
			checkidx(nextidx + 1, r1.size() + r2[b].idx);
			f++;
			b++;
			nextidx += 2;
		}
	}
	while (b != r2.size()) {
		temp.push_back({ nextidx++, r2[b].data });
		checkidx(nextidx, r1.size() + r2[b].idx);
		nextidx++;
		b++;
	}
	while (f != r1.size()) {
		checkidx(nextidx, r1[f].idx);
		temp.push_back({ nextidx, r1[f].data });
		nextidx++;
		f++;
	}

	/*
	for (auto t : temp) {
		printf("(%d, %d) ", t.idx, t.data);
	}
	cout << endl;
	*/

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
			r.push_back({ 0, a });
		}

		r = mergesort(r);

		printf("#%d %d\n", ca, res);

	}
	return 0;
}



==========================================
	
	
	
#include<iostream>
#include<fstream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

struct Runner {
	int idx;
	int data;
};

Runner r[100001];
Runner tmp[100001];
int res = 0;

void merge(int s, int m, int e) {
	int f_idx = s;
	int r_idx = m + 1;
	int t = 0;

	while (f_idx <= m || r_idx <= e) {
		if (f_idx > m) {
			tmp[t++] = r[r_idx++];
		}
		else if (r_idx > e) {
			tmp[t++] = r[f_idx++];
		}
		else {
			if (r[r_idx].data > r[f_idx].data) {
				tmp[t++] = r[r_idx++];
				res += (m - f_idx + 1);
			}
			else {
				tmp[t++] = r[f_idx++];
			}
		}
	}

	for (int i = 0; i < t; i++) {
		r[i + s] = tmp[i];
	}
}

void mergesort(int s, int e) {
	if (s == e) {
		return;
	}

	int m = (s + e) / 2;

	mergesort(s, m);
	mergesort(m + 1, e);
	merge(s, m, e);
}

int main() {
	ifstream f("input.txt");
	int CA;
	f >> CA;
	for (int ca = 1; ca <= CA; ca++) {
		int N;
		f >> N;
		res = 0;
		for (int i = 1; i <= N; i++) {
			int a;
			f >> a;
			r[i] = { 0, a };
		}

		mergesort(1, N);

		printf("#%d %d\n", ca, res);

	}
	return 0;
}


