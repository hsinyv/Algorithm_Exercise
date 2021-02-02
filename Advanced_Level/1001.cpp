#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cctype>
#include <unordered_map>
using namespace std;
int main() {
	int a,b;
	cin >> a;
	cin >> b;
	int sum = a + b;
	string sum_s = to_string(sum);
	if(sum_s.length() < 4) cout << sum;
	else{
		for(int i = sum_s.length()-1, j = 1; i > 0; --i, ++j){
			if(j%3 == 0 && sum_s[i-1] != '-') {
				j = 1;
				sum_s.insert(i,",");
				--i;
			}
		}
		cout << sum_s;
	}
	return 0;

}
