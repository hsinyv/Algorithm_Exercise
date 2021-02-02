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
const int days_of_month[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
const int days_of_month_leap[13] = { 0,31,29,31,30,31,30,31,31,30,31,30,31 };

bool leap_judge(int n) {
	if ((n % 4 == 0) && (n % 100 != 0)) return true;
	if ((n % 100 == 0) && (n % 400 == 0)) return true;
	return false;
}

string date_class(int y, int m, int d){
	if(leap_judge(y)){
		if(d >= days_of_month_leap[m]){
			//the last day of the month
			if(m == 12){
				//the last day of the year
				string s = to_string(y+1);
				s += "-01-01";
				return s;
			}
			else{
				//not the last day of the year
				string s = to_string(y); s += "-";
				if(m+1 < 10) s += "0";
				s += to_string(m+1); s += "-";
				s += "01";
				return s;
			}
		}
		else{
			//not the last day of the month
			string s = to_string(y); s += "-";
			if(m < 10) s += "0";
			s += to_string(m); s += "-";
			if(d+1 < 10) s += "0";
			s += to_string(d+1);
			return s;
		}
	}
	else{
		if(d >= days_of_month[m]){
			//the last day of the month
			if(m == 12){
				//the last day of the year
				string s = to_string(y+1);
				s += "-01-01";
				return s;
			}
			else{
				//not the last day of the year
				string s = to_string(y); s += "-";
				if(m+1 < 10) s += "0";
				s += to_string(m+1); s += "-";
				s += "01";
				return s;
			}
		}
		else{
			//not the last day of the month
			string s = to_string(y); s += "-";
			if(m < 10) s += "0";
			s += to_string(m); s += "-";
			if(d+1 < 10) s += "0";
			s += to_string(d+1);
			return s;
		}
	}
}
int main() {
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		int y; int m; int d;
		cin >> y >> m >> d;
		cout << date_class(y,m,d) << endl;
		
	}
	return 0;
}
