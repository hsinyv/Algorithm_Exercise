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
	int n;
	cin >> n;
	while(n){
		int *score = new int[n];
		for(int i = 0; i < n; ++i){
			cin >> score[i];
		}
		int target, cnt = 0;
		cin >> target;
		for(int i = 0; i < n; ++i){
			if(score[i] == target) ++cnt;
		}
		cout << cnt << endl;
		cin >> n;
	}
	return 0;
}

