#include<iostream>
#include<fstream>
#include<cstdio>
#include<vector>
#include<algorithm>
#define MAX 1000000007
using namespace std;

int arr[5000001];
vector< pair<int, int> > v;


int check_tower(int i, int n) {
	if (i == 1) {
		v.push_back({ i, n });
		return 0;
	}
	pair<int, int> back = v.back();
	
	while (!v.empty() && v.back().second <= n) {
		v.pop_back();
	}
	v.push_back({ i, n });


	if (v.size() == 1) {
		return 0;
	}
	else {
		return v[v.size() - 2].first;
	}
}

int main() {
	ifstream f("input.txt");
	int CA;
	f >> CA;
	for (int ca = 1; ca <= CA; ca++) {
		int N;
		long long res = 0;
		f >> N;
		v.clear();
		for (int i = 1; i <= N; i++) {
			int n;
			f >> n;
			res += check_tower(i, n);

		}
		printf("#%d %lld\n", ca, res % MAX);

	}
	return 0;
}
