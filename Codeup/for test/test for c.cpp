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
#include <fstream>
using namespace std;
const int days_of_month[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
const int days_of_month_leap[13] = { 0,31,29,31,30,31,30,31,31,30,31,30,31 };
const string month_eng[13] = { "#", "January","February","March","April","May","June","July","August","September","October","November","December" };
ofstream out("test for c.txt");
bool leap_judge(int n) {
	if ((n % 4 == 0) && (n % 100 != 0)) return true;
	if ((n % 100 == 0) && (n % 400 == 0)) return true;
	return false;
}

void cal_date(int year, int day) {
	int month;
	if (leap_judge(year)) {
		for (int i = 1; i < 13; i++) {
			if (day < days_of_month_leap[i]) {
				month = i;
				break;
			}
			else {
				day -= days_of_month_leap[i];
			}
		}
	}

	else {
		for (int i = 1; i < 13; i++) {
			if (day < days_of_month[i]) {
				month = i;
				break;
			}
			else {
				day -= days_of_month[i];
			}
		}
	}
	string s = to_string(year); s += "-";
	if (month < 10) {
		s += "0";
	}
	s += to_string(month);
	s += "-";
	if (day < 10) {
		s += "0";
	}
	s += to_string(day);
	out << s << endl;
	return;
}
int main() {
	int year, day;
	for(year = 2000; year < 2001; year++){
		int day_lim = (leap_judge(year))? 366 : 365;
		for(day = 1; day < day_lim + 1; day++){
			out << year << " " << day << " "; 
			cal_date(year, day);
		}
	}
	out.close();
	return 0;
}
