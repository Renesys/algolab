#include <iostream>
#include <fstream>
#include <algorithm>
#include <deque>
#include <cstdio>
using namespace std;

deque<int> birth;
deque<int> adult;
deque<int> death;
deque<int> res;

int main(int argc, char** argv) {
	ifstream f;
	f.open("in.txt");	
	int CA;
	cin >> CA;
	
	for (int ca = 1; ca <= CA; ca++){
		int a, b, d, N;
		cin >> a >> b >> d >> N;
		
		//init
		long long q = 0;
		birth.clear();
		adult.clear();
		death.clear();
		res.clear();
		birth.push_back(1);
		adult.push_back(0);
		death.push_back(0);
		res.push_back(1);
		
		//printf("0: %d %d %d %d\n", birth[0], adult[0], death[0], res[0]);
		
		//logic
		for(int n = 1; n <= N; n++){
			//rotate
			if(birth.size() > d+1){
				birth.pop_front();
			}
			if(adult.size() > d+1){
				adult.pop_front();
			}
			if(death.size() > d+1){
				death.pop_front();
			}
			if(res.size() > d+1){
				res.pop_front();
			}
			

			if(n <= d+1){
				//adult
				if(n - a >= 0){
					adult.push_back(birth[n-a]); 
				}
				else{
					adult.push_back(0);
				}
				
				//birth
				for(int j = n; j > n-(b-a); j--){
					if(j < 0)
						break;
					if(j == n){
						birth.push_back(adult[j]);
					}
					else{
						birth[n] += adult[j];
					}
				}
				
				//death
				if(n - d >= 0){
					death.push_back(birth[n-d]); 
				}
				else{
					death.push_back(0);
				}
			
				//result
				res.push_back(res[n-1] + birth[n] - death[n]);
				
				//printf("%d: %d %d %d %d\n", n, birth[n], adult[n], death[n], res[n]);
				q = res[n];
			}
			else{
				//adult
				adult.push_back(birth[d+1-a]); 
				//birth
				for(int j = d+1; j > d+1-(b-a); j--){
					if(j < 0)
						break;
					if(j == d+1){
						birth.push_back(adult[j]);
					}
					else{
						birth[d+1] += adult[j];
					}
				}
				//death
				death.push_back(birth[1]); 
				//result
				res.push_back(res[d] + birth[d+1] - death[d+1]);
				
				//printf("%d: %d %d %d %d\n", n, birth[d+1], adult[d+1], death[d+1], res[d+1]);
				q = res[d+1];
			}

			
					
			
		}
		
		printf("#%d %lld\n", ca, q%1000);

	}
	
	return 0;
}
