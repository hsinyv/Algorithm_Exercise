/***********************************************
*  Program Ability Test Advanced Level Practice
*  No.A1060 Are They Equal
*  Date: 2021/03/12
***********************************************/
/***********************************************
* Core Mission: transform float to scientific notation
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
typedef pair<string, int> ScientificNotation;
//first is effective digits, second is exponent

ScientificNotation Transform2ScientificNotation(string number, int significant_digits_num) {
	//count integer part length
	int i;
	int integer_len = 0;
	for (i = 0; i < number.size(); i++)
	{
		if (number[i] == '.') {
			integer_len = i;
			number.erase(number.begin() + i);
			break;
		}
	}
	if (integer_len == 0) integer_len = number.size();
	if (number.size() < significant_digits_num) {
		int loop_lim = significant_digits_num - number.size();
		for (int i = 0; i < loop_lim; i++)
		{
			number += '0';
		}
	}
	string integer_substr = number.substr(0, significant_digits_num);
	bool is_zero = true;
	for (auto digit : integer_substr) {
		if (digit != '0') {
			is_zero = false;
			break;
		}
	}
	if(is_zero) return make_pair("#",0);
	return make_pair(number.substr(0, significant_digits_num), integer_len);
}

int main(void) {
	int significant_digits_num;
	string a_number, b_number;
	while (cin >> significant_digits_num >> a_number >> b_number) {
		ScientificNotation a = Transform2ScientificNotation(a_number, significant_digits_num);
		ScientificNotation b = Transform2ScientificNotation(b_number, significant_digits_num);
		if (a.second == b.second && a.first == b.first) {
			if (a.first == "#") {
				cout << "YES 0\n";
			}
			else {
				cout << "YES 0." << a.first << "*10^" << a.second << endl;
			}
		}
		else {
			cout << "No ";
			if (a.first == "#") {
				cout << "0 ";
			}
			else {
				cout << "0." << a.first << "*10^" << a.second << " ";
			}
			if (b.first == "#") {
				cout << "0\n";
			}
			else {
				cout << "0." << b.first << "*10^" << b.second << endl;
			}
		}
	}
	
	return 0;
}
 
