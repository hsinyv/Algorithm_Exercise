#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cctype>
#include <unordered_map>
#include <iomanip>
using namespace std;
int main() {
	int sum; cin >> sum;
	map<int,int> score_sum;
	int no, score;
	for(int i = 0; i < sum; i++){
		cin >> no >> score;
		score_sum[no] += score;
	}
	pair<int,int> champion = {0,0};
	for(auto it : score_sum){
		if(it.second > champion.second){
			champion = it;
		}
	}
	cout << champion.first << " " << champion.second << endl;
	return 0;
}
