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
bool leap_judge(int n) {
	if ((n % 4 == 0) && (n % 100 != 0)) return true;
	if ((n % 100 == 0) && (n % 400 == 0)) return true;
	return false;
}

void get_date(string s, string t, int date[]) {
	//transfer the date in string form to yyyymmdd format
	//date[0...3] is the first and less year
	date[0] = stoi(s.substr(0, 4));
	date[3] = stoi(t.substr(0, 4));
	if (date[0] > date[3]) {
		//adjust year
		date[0] = stoi(t.substr(0, 4));
		date[1] = stoi(t.substr(4, 2));
		date[2] = stoi(t.substr(6, 2));
		date[3] = stoi(s.substr(0, 4));
		date[4] = stoi(s.substr(4, 2));
		date[5] = stoi(s.substr(6, 2));
	}
	else if (date[0] == date[3]) {
		date[1] = stoi(s.substr(4, 2));
		date[4] = stoi(t.substr(4, 2));
		if (date[1] > date[4]) {
			date[1] = stoi(t.substr(4, 2));
			date[2] = stoi(t.substr(6, 2));
			date[4] = stoi(s.substr(4, 2));
			date[5] = stoi(s.substr(6, 2));
		}
		else if (date[1] == date[4]) {
			date[2] = stoi(s.substr(6, 2));
			date[5] = stoi(t.substr(6, 2));
			if (date[2] > date[5]) {
				date[2] = stoi(t.substr(6, 2));
				date[5] = stoi(s.substr(6, 2));
			}
		}
		else {
			date[2] = stoi(s.substr(6, 2));
			date[5] = stoi(t.substr(6, 2));
		}
	}
	else {
		date[1] = stoi(s.substr(4, 2));
		date[2] = stoi(s.substr(6, 2));
		date[4] = stoi(t.substr(4, 2));
		date[5] = stoi(t.substr(6, 2));
	}
	return;
}
int cal_interval(int* date) {
	const int days_of_month[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	const int days_of_month_leap[13] = { 0,31,29,31,30,31,30,31,31,30,31,30,31 };
	const int day_of_year = 365;
	const int day_of_leap_year = 366;
	//get the date
	int y1 = date[0], m1 = date[1], d1 = date[2];
	int y2 = date[3], m2 = date[4], d2 = date[5];
	int interval = 0;
	//generate leap year flag
	bool leap_year_1 = leap_judge(y1);
	bool leap_year_2 = leap_judge(y2);
	//cal interval of integral years between the two dates
	for (int i = 0; i < y2 - y1 - 1; i++) {
		if (leap_judge(y1 + 1 + i)) interval += day_of_leap_year;
		else interval += day_of_year;
	}
	//case: the two dates is in the same year
	if (y1 == y2) {
		if (leap_year_1) {
			//leap_year
			int month = (m1 < m2) ? m1 : m2;
			//cal interval of integral months between the two dates
			for (int i = 0; i < m2 - m1 - 1; i++) {
				interval += days_of_month_leap[month + 1 + i];
			}
			if (m1 == m2) {
				//the two dates is in the same month
				interval += abs(d2 - d1);
			}
			else {
				//the two dates is not in the same month
				interval += days_of_month_leap[m1] - d1;
				interval += d2;
			}
		}
		else {
			//ordinary year
			int month = (m1 < m2) ? m1 : m2;
			for (int i = 0; i < m2 - m1 - 1; i++) {
				interval += days_of_month[month + 1 + i];
			}
			if (m1 == m2) {
				interval += abs(d2 - d1);
			}
			else {
				interval += days_of_month[m1] - d1;
				interval += d2;
			}
		}
		return interval + 1;
	}
	//the date is not in the same year
	else {
		int a[6] = { y1,m1,d1,y1,12,31 };
		interval += cal_interval(a);
		int b[6] = { y2,1,1,y2,m2,d2 };
		interval += cal_interval(b);
		return interval;
	}
	
}
int main() {
	string s, t;
	while (cin >> s >> t) {
		int date[6];
		get_date(s, t, date);
		cout << cal_interval(date) << endl;
	}
	return 0;
}
