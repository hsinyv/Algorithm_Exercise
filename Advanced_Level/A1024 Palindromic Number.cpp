/***********************************************
*  Program Ability Test Advanced Level Practice
*  No.A1024 Palindromic Number
*  Date: 2021/03/12
***********************************************/
/***********************************************
* Core Mission: input data will bigger than the range of long long 
* Point:  
***********************************************/
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;

bool IsPalindromic(string a) {
	string b = a;
	reverse(b.begin(), b.end());
	return a == b;
}

string LongPlus(string a, string b) {
	string result;
	int carry = 0;
	for (int i = 0; i < a.size(); i++)
	{
		int this_sum = (a[i] - '0') + (b[i] - '0') + carry;
		carry = this_sum / 10;
		result = to_string(this_sum % 10) + result;
	}
	if (carry > 0) {
		result = to_string(carry) + result;
	}
	return result;
}

int main(void) {
	string ini_number; int max_steps_num;
	cin >> ini_number >> max_steps_num;
	int steps_cnt = 0;
	while (!IsPalindromic(ini_number)) {
		if (steps_cnt >= max_steps_num) break;
		string reverse_number = ini_number;
		reverse(reverse_number.begin(), reverse_number.end());
		ini_number = LongPlus(ini_number, reverse_number);
		++steps_cnt;
	}
	cout << ini_number << "\n" << steps_cnt << endl;
	return 0;
}
 
