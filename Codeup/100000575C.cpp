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
	string s,t;
	while(cin >> s >> t){
		vector<int> a, b;
		for(int i = 0; i < s.size(); ++i){
			a.push_back(s[i] - '0');
		}
		for(int i = 0; i < t.size(); ++i){
			b.push_back(t[i] - '0');
		}
		int sum = 0;
		for(int i = 0; i < a.size(); ++i){
			for(int j = 0; j < b.size(); ++j){
				sum += a[i] * b[j];
			}
		}
		cout << sum << endl;
	}
	return 0;
}


