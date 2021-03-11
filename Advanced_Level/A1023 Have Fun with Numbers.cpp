/***********************************************
*  Program Ability Test Advanced Level Practice
*  No.A1023 Have Fun with Numbers
*  Date: 2021/03/11
***********************************************/
/***********************************************
* Core Mission: check if doubling the input number gives a number 
*				that consists of only a permutation of the digits 
*				in the original number
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

string LongDoubling(string ini_number) {
	string result;
	reverse(ini_number.begin(), ini_number.end());
	int carry_down = 0;
	for (auto digit : ini_number) {
		int product_this_level = (digit - '0') * 2 + carry_down;
		int digit_this_level = product_this_level % 10;
		carry_down = product_this_level / 10;
		result = to_string(digit_this_level) + result;
	}
	if (carry_down != 0) {
		result = to_string(carry_down) + result;
	}
	return result;
}

int main(void) {
	string ini_number;
	cin >> ini_number;
	string doubling_number = LongDoubling(ini_number);
	vector<pair<char, int>> all_digits;
	for (auto digit : ini_number) {
		all_digits.push_back(make_pair(digit, 0));
	}
	bool not_found = true;
	for (auto digit : doubling_number) {
		not_found = true;
		for (int i = 0; i < all_digits.size(); i++)
		{
			if (all_digits[i].first == digit && all_digits[i].second == 0) {
				all_digits[i].second = 1;
				not_found = false;
				break;
			}
		}
		if (not_found) break;
	}
	if (not_found) {
		cout << "No\n";
	}
	else {
		cout << "Yes\n";
	}
	cout << doubling_number << endl;
	return 0;
}
 
