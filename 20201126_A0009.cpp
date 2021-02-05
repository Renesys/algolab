#include <iostream>
#include <fstream>
#include <algorithm>
#include <stdio.h>

using namespace std;

int map[251][251] = {0,};
int S[251][251] = {0,};

int main(int argc, char** argv) {
	ifstream f;
	f.open("in.txt");
	
	int CA;
	int data;

	cin >> CA;
	for (int ca = 1; ca <= CA; ca++){
		int size;
		cin >> size;

		//initialize
		for(int i = 1; i <= size; i++){
			for (int j = 1; j <= size; j++){
				map[i][j] = S[i][j] = 0;
			}
		}

		//input
		for(int i = 1; i <= size; i++){
			for (int j = 1; j <= size; j++){
				cin >> data;
				map[i][j] = data;
				if(data == 1)
					S[i][j] = min(min(S[i-1][j-1], S[i-1][j]),S[i][j-1]) + 1;
			}
		}


		//logic
		int res = 0;
		for(int i = 1; i <= size; i++){
			for (int j = 1; j <= size; j++){
				if (S[i][j] >= 1){
					res += (S[i][j] -1);
				}
			}
		}

		printf("#%d %d\n", ca, res);
	}
	
	return 0;
}
