/***********************************************
*  Program Ability Test Advanced Level Practice
*  No.A1073 Scientific Notation
*  Date: 2021/03/13
***********************************************/
/***********************************************
* Core Mission: 
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

int main(void) {
	string ini_number; cin >> ini_number;
	//number[0] is the sign
	//number[1] is the integer portion
	//number[2] is the dot
	//find 'E'

	char number_sign = ini_number[0];
	string number = ini_number.substr(1,1);
	int cnt = 0;
	for (cnt = 3; cnt < ini_number.size(); cnt++) {
		if (ini_number[cnt] == 'E') {
			break;
		}
		else {
			number += ini_number[cnt];
		}
	}
	//cnt points to 'E' now
	char exponent_sign = ini_number[cnt + 1];
	int exponent = stoi(ini_number.substr(cnt + 2));
	if (exponent_sign == '+') {
		int fractional_portion_len = number.size() - 1;
		if (fractional_portion_len > exponent) {
			int dot_insert_index = exponent + 1;
			number.insert(dot_insert_index, ".");
		}
		else {
			int append_zero_num = exponent - fractional_portion_len;
			for (int i = 0; i < append_zero_num; i++)
			{
				number += "0";
			}
		}
	}
	else {
		if (exponent > 0) {
			for (int i = 0; i < exponent; i++)
			{
				number = "0" + number;
			}
		}
		number.insert(1, ".");
	}
	if (number_sign == '-') {
		number = number_sign + number;
	}
	cout << number << endl;
	return 0;
}
 
