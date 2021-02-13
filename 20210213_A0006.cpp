#include<cstdio>
#include<algorithm>
#define MAX2 90000001
#define MAX 1000000007
using namespace std;

int main() {
	ifstream f("input.txt");
	int CA;
	f >> CA;
	for (int ca = 1; ca <= CA; ca++) {
		long long A, B;
		long long res = 1;
		f >> A >> B;
		long long mu = A;
		while (B != 0) {
			long long t = B % 2;
			B /= 2;
			if (t == 1) {
				res = (res % MAX) * (mu % MAX);
			}
			while (mu > MAX) {
				mu %= MAX;
			}
			mu *= mu;
			
			while (res > MAX) {
				res %= MAX;
			}
		}


		printf("#%d %lld\n", ca, res%MAX);
	}
	return 0;
}
