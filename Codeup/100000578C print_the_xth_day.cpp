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
//ofstream out("day.txt");
bool leap_judge(int n) {
	if ((n % 4 == 0) && (n % 100 != 0)) return true;
	if ((n % 100 == 0) && (n % 400 == 0)) return true;
	return false;
}
//void print_to_file(int n){
//	int i;
//	if(leap_judge(n)){
//		for(i = 1; i < 13; i++){
//			for(int j = 1; j <= days_of_month_leap[i]; j++){
//				out << j << " " << month_eng[i] <<" " << to_string(n) << endl;
//			}
//		}
//	}
//	else{
//		for(i = 1; i < 13; i++){
//			for(int j = 1; j <= days_of_month[i]; j++){
//				out << j << " " << month_eng[i] << " " << to_string(n) << endl;
//			}
//		}
//	}
//	
//	return;
//}
void cal_date(int year, int day) {
	int month = -1;
	if (leap_judge(year)) {
		for (int i = 1; i < 13; i++) {
			if (day < days_of_month_leap[i]+1) {
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
			if (day < days_of_month[i]+1) {
				month = i;
				break;
			}
			else {
				day -= days_of_month[i];
			}
		}
	}
	string s; 
	if(year < 10){
		s += "0";
	}
	if(year < 100){
		s += "0";
	}
	if(year < 1000){
		s += "0";
	}
	s += to_string(year);
	s += "-"; 
	if (month < 10) {
		s += "0";
	}
	s += to_string(month);
	s += "-";
	if (day < 10) {
		s += "0";
	}
	s += to_string(day);
	cout << s << endl;
}
int main() {
	int year, day;
	while (cin >> year >> day) {
		cal_date(year, day);
	}
	return 0;
}
