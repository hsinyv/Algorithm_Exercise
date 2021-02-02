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
		int width = 3*n-2;
		for(int i = 0; i < n; i++){
			string s;
			for(int j = 0; j < n+(2*i); j++){
				s = s + "*";
		}
		cout << setw(width) << s << endl;
		//if(i < n-1) cout << endl;
	}
	}
	
	
	return 0;
}
