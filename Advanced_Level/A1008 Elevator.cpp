#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
#define up_t 6
#define down_t 4
#define stay_t 5

int main() {
	int cur_f = 0, next_f;
	int t_cost = 0; int n;
	cin >> n;
	
	for(int i = 0; i < n; i++){
		cin >> next_f;
		int dif = cur_f - next_f;
		if(dif > 0){
			t_cost += dif * down_t;
		}
		else{
			dif = next_f - cur_f;
			t_cost += dif * up_t;
		}
		t_cost += stay_t;
		cur_f = next_f;
	}
	
	cout << t_cost << endl;
	return 0;
}


