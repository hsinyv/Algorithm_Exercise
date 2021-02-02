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
	int m;
	cin >> m;
	for(int i = 0; i < m ; i++){
		int n;
		cin >> n;
		int width = 3*n-2;
		int space_num = n-1;
		for(int i = 0; i < n; i++){
			string s;	
			for(int j = 0; j < n+(2*i); j++){
				s = s + "*";
			}
			for(int j = space_num; j > 0; j--){
				s = " " + s;
			}
			space_num--;
			//cout << setw(width) << s << endl;
			cout << s << endl;
			//if(i < n-1) cout << endl;
		}
	}
		
	
	
	return 0;
}
