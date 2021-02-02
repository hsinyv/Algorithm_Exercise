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
	int len, num;
	cin >> len >> num;
	while(len + num){
		int *a = new int[len + 1];
		for(int i = 0; i <= len; i++){
			a[i] = 0;
		}
		for(int i = 0; i < num; i++){
			int start, end;
			cin >> start >> end;
			if(end > len) end = len;
			for(int i = start; i <= end; i++){
				a[i] = -1;
			}
		}
		int sum = 0;
		for(int i = 0; i <= len; i++){
			if(a[i] == 0) ++sum;
		}
		cout << sum << endl;
		cin >> len >> num;
	} 
	return 0;
}
