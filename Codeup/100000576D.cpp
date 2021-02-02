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
	while(cin >> n){
		int *a = new int[n];
		for(int i = 0; i < n; i++){
			cin >> a[i];
		} 
		int m;
		cin >> m;
		for(int i = 0; i < m; i++){
			int t;
			cin >> t;
			bool not_found = true;
			for(int i = 0; i < n; i++){
				if(a[i] == t){
					cout << "YES" << endl;
					not_found = false;
					break;
				}
			}
			if(not_found) cout << "NO" << endl; 
		}
		//cin >> n;
		delete []a;
	}
	
	return 0;
}
