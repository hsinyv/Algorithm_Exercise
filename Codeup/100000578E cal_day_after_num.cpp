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
string cal_date(int y, int m, int d, int interval){
	int days_of_year = (leap_judge(y))? 366:365;
	
	while(interval >= days_of_year){
		interval -= days_of_year;
		y++;	
		days_of_year = (leap_judge(y))? 366:365;
	}
	
	d += interval;
	for(int i = m; i < 13; i++){
		if(leap_judge(y)){
			if(d <= days_of_month_leap[i]){
				string s = to_string(y); s+="-";
				if(m < 10) s += "0";
				s += to_string(m); s+="-";
				if(d < 10) s += "0";
				s += to_string(d);
				return s;				
			}
			else{
				d = d-days_of_month_leap[i];
				m++;
			}
		}
		else{
			if(d <= days_of_month[i]){
				string s = to_string(y); s+="-";
				if(m < 10) s += "0";
				s += to_string(m); s+="-";
				if(d < 10) s += "0";
				s += to_string(d);
				return s;				
			}
			else{
				d = d-days_of_month[i];
				m++;
			}
		}
		if(m == 13){ //deal with the case that go over years but interval is less than a year
			y++;
			m = 1;
			i = 0; //this round of loop will inc i
		}
	}
}
int main() {
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		int y,m,d,interval;
		cin >> y >> m >> d >> interval;
		cout << cal_date(y,m,d,interval) ;
		if(i < n-1) cout << endl;
	}
//	int y,m,d,interval;
//	while(cin >> y >> m >> d >> interval){
//		cal_date(y,m,d,interval);
//		cout << cal_date(y,m,d,interval) << endl;
//	}
	return 0;
}
