#include<iostream>
#include<fstream>
#include<cstdio>
#include<deque>
#include<vector>
#include<string>
#include<algorithm>
#define MAX 10000007
using namespace std;

vector<int> prime;
int is_prime[10001];
int chk[10001];
int res;

void make_prime() {
	int idx = 2;	
	for (int i = 1; i <= 10000; i++) {
		is_prime[i] = true;
	}
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i <= 10000; i++) {
		if (!is_prime[i]) continue;
		for (int j = i * 2; j <= 10000; j += i) {
			is_prime[j] = false;
		}
	}	

	for (int i = 1000; i <= 10000; i++) {
		if (is_prime[i]) {
			prime.push_back(i);
		}
	}

}


deque<pair<int, int>> dq;
void search_path(pair<int, int> src, int dest) {
	if (res != MAX) {
		return;
	}
	else if (src.second == dest) {
		if (res > src.first) {
			res = src.first;
		}
		return;
	}

	//choose candidate
	int arr[4] = { 1000, 100, 10, 1 };
	string s = to_string(src.second);
	
	for (int i = 0; i < 4; i++) {
		int t = 0;
		//add except pivot line
		for (int j = 0; j < 4; j++) {
			if (i != j) {
				t += ((s[j]-'0') * arr[j]);
			}
		}	
		//add pivot line
		for (int j = 0; j < 10; j++) {
			if (i == 0 && j == 0) continue;
			t += j * arr[i];

			if (is_prime[t] && !chk[t]) {
				dq.push_back({ src.first + 1, t });
				chk[t] = true;
			}
			t -= j*arr[i];
		}
	}
	
	//BFS
	while (!dq.empty()) {
		pair<int, int> next = dq.front();
		dq.pop_front();
		search_path(next, dest);
	}
	return;
}

int main() {
	ifstream f("input.txt");
	int CA;
	f >> CA;
	make_prime();

	for (int ca = 1; ca <= CA; ca++) {
		for (int i = 0; i <= 10000; i++) {
			chk[i] = false;
		}
		int a, b;
		dq.clear();
		res = MAX;
		f >> a >> b;
		chk[a] = true;
		search_path({ 0,a }, b);
		printf("#%d %d\n", ca, res);
	}
	return 0;
}

