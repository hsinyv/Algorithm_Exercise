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
bool f1(int t){
	if((t%5 == 0) && (t%2 == 0)) return true;
	return false;
}
bool f2(int t){
	if(t%5 == 1) return true;
	return false;
}
bool f3(int t){
	if(t%5 == 2) return true;
	return false;
}
bool f4(int t){
	if(t%5 == 3) return true;
	return false;
}
bool f5(int t){
	if(t%5 == 4) return true;
	return false;
}
int main() {
	int n;
	while(cin >> n){
		bool a1_f = true, a2_f = true,	a3_f = true,	a4_f = true,	a5_f = true;
		int a1_sum = 0,a2_sum = 0,a3_n = 0,  a5_grt = 0;
		double a4_n = 0, a4_sum = 0;
		int a2_flag = 1;
		for(int i = 0; i < n; i++){
			int t; cin >> t;
			if(f1(t)){
				a1_sum += t;
				a1_f = false;
			}
			if(f2(t)){
				a2_f = false;
				if(a2_flag){
					a2_sum += t;	a2_flag = 0;
				}
				else{
					a2_sum -= t;	a2_flag = 1;
				}
			}
			if(f3(t)){
				a3_f = false;
				a3_n++;
			}
			if(f4(t)){
				a4_f = false;
				a4_sum += t;	a4_n++;
			}
			if(f5(t)){
				a5_f = false;
				if(a5_grt < t) a5_grt = t;
			}
		}
		if(a1_f) cout << "N ";
		else cout << a1_sum << " ";
		if(a2_f) cout << "N ";
		else cout << a2_sum<< " ";
		if(a3_f) cout << "N ";
		else cout << a3_n<< " ";
		if(a4_f) cout << "N ";
		else cout << fixed << setprecision(1) << a4_sum/a4_n << " ";
		if(a5_f) cout << "N" << endl;
		else cout << a5_grt << endl;
	} 
	return 0;
}

