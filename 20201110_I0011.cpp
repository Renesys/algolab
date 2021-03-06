#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <stdio.h>

using namespace std;

string input[5];

string map[5][4][5] = {
	{
		{"00100", "00100", "00100", "00100", "00100"},
		{"00000", "00000", "11111", "00000", "00000"},
		{"00100", "00100", "00100", "00100", "00100"},
		{"00000", "00000", "11111", "00000", "00000"}
	},
	{
		{"11111", "00001", "11111", "10000", "11111"},
		{"11101", "10101", "10101", "10101", "10111"},
		{"11111", "00001", "11111", "10000", "11111"},
		{"11101", "10101", "10101", "10101", "10111"},
	},
	{
		{"11111", "00001", "11111", "00001", "11111"},
		{"10101", "10101", "10101", "10101", "11111"},
		{"11111", "10000", "11111", "10000", "11111"},
		{"11111", "10101", "10101", "10101", "10101"}
	},
	{
		{"10100", "10100", "11111", "00100", "00100"},
		{"00111", "00100", "11111", "00100", "00100"},
		{"00100", "00100", "11111", "00101", "00101"},
		{"00100", "00100", "11111", "00100", "11100"}
	},
	{
		{"11111", "10000", "11111", "00001", "11111"},
		{"10111", "10101", "10101", "10101", "11101"},
		{"11111", "10000", "11111", "00001", "11111"},
		{"10111", "10101", "10101", "10101", "11101"},
	},
};

int check_num(int idx){
	int res = 0;
	int flag = 0;
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 5; j++){
			if(map[idx][i][j] != input[j]){
				flag = 0;
				break;
			}
			flag++;
		}
		if(flag == 5){
			res = idx+1;
			break;
		}
	}
	
	return res;
}

int main(int argc, char** argv) {
	ifstream f;
	f.open("in.txt");
	
	int CA;
	int res = 0;
	cin >> CA;
	for (int ca = 1; ca <= CA; ca++){
		int res = 0;
		
		for (int i = 0; i < 5; i++){
			input[i] = "";
			string s;
			for (int j = 0; j < 5; j++){
				cin >> s;
				input[i] += s;
			}
		}
		

		for (int i = 0; res == 0 && i < 5; i++){
			res = check_num(i);
		}


		printf("#%d %d\n", ca, res);
	}
	
	return 0;
}
